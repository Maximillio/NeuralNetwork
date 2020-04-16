#include "Neurons/MiddleNeuron.hpp"
#include "Links/Link.hpp"
#include <strstream>

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
    std::strstream stream;
    stream << '|' <<"Value:" << mValue << '|' << std::endl;
    for (auto link : mLinks)
    {
        stream << '|' <<"Link weight:" << link->getWeight() << '|'<<std::endl;
    }
    return stream.str();
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
