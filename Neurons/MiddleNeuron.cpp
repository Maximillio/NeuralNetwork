#include "Neurons/MiddleNeuron.hpp"
#include "Links/Link.hpp"
#include <string>
#include <math.h>

NeuralNetwork::MiddleNeuron::MiddleNeuron() noexcept {}

NeuralNetwork::MiddleNeuron::MiddleNeuron(const std::list<std::shared_ptr<NeuralNetwork::Link> >& links) noexcept
    : mLinks(links) {}

NeuralNetwork::MiddleNeuron::MiddleNeuron(std::list<std::shared_ptr<NeuralNetwork::Link> >&& links) noexcept
    : mLinks( std::move(links) ) {}

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
        if (link != nullptr)
        {
            string.append( std::to_string( link->getWeight() ) );
        }
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
        mValue += link->getValue();
    }
    mValue = sigmaFunction(mValue);
}

double NeuralNetwork::MiddleNeuron::sigmaFunction(double value)
{
    return (1/(1+exp(-value)));
}
