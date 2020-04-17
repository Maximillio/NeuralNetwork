#include "Neurons/MiddleNeuron.hpp"
#include "Links/Link.hpp"
#include <string>

NeuralNetwork::MiddleNeuron::MiddleNeuron() noexcept {}

NeuralNetwork::NeuronType NeuralNetwork::MiddleNeuron::getType() const noexcept
{
    return NeuronType::Middle;
}

void NeuralNetwork::MiddleNeuron::addLink(std::shared_ptr<Link> link) noexcept
{
    mLinks.push_back(link);
}

void NeuralNetwork::MiddleNeuron::addLinks(const std::list<std::shared_ptr<Link>>& links)
{
    mLinks.insert( mLinks.end(), links.begin(), links.end() );
}

std::string NeuralNetwork::MiddleNeuron::toString() const noexcept
{
    std::string string;

    string.append("|");
    string.append("Value:");
    string.append( std::to_string(mValue) );
    string.append("|");
    string.append("\r\n");
    for (auto link : mLinks)
    {
        string.append("|");
        string.append("Link weight:");
        string.append( std::to_string( link->getWeight() ) );
        string.append("|");
        string.append("\r\n");
    }

    return string;
}

void NeuralNetwork::MiddleNeuron::readLinksValues() noexcept
{
    mValue = 0;
    for (auto link : mLinks)
    {
        mValue = link->getValue();
    }
    mValue /= static_cast<double>( mLinks.size() );
}
