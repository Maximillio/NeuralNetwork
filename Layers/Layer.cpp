#include "Layer.hpp"
#include "Neurons/Neuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include "Links/Link.hpp"
#include <random>
#include <string>

NeuralNetwork::Layer::Layer() noexcept {}

void NeuralNetwork::Layer::addNeuron(std::shared_ptr<Neuron> neuron) noexcept
{
    mNeurons.push_back(neuron);
}

void NeuralNetwork::Layer::addNeurons(const std::list<NeuralNetwork::Neuron*>& neuron) noexcept
{
    mNeurons.insert( mNeurons.end(), neuron.begin(), neuron.end() );
}

std::list<std::shared_ptr<NeuralNetwork::Link> > NeuralNetwork::Layer::getLinks() const
{
    std::list<std::shared_ptr<Link>> links;
    for (auto neuron : mNeurons)
    {
        links.push_back( std::make_shared<Link>(neuron, static_cast<double>(rand()%10000)/10000.0) );
    }
    return links;
}

const std::list<std::shared_ptr<NeuralNetwork::Neuron> >& NeuralNetwork::Layer::getNeuronsList() const noexcept
{
    return mNeurons;
}

bool NeuralNetwork::Layer::iterate() noexcept
{
    if ( !mNeurons.empty() )
    {
        bool isValid = true;
        for (auto neuron : mNeurons)
        {
            if (neuron->getType() != NeuronType::Middle)
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            for (auto neuron : mNeurons)
            {
                dynamic_cast<MiddleNeuron*>( neuron.get() )->readLinksValues();
            }
            return true;
        }
    }

    return false;
}

std::string NeuralNetwork::Layer::toString() const noexcept
{
    std::string string;

    for (auto neuron : mNeurons)
    {
        if (neuron != nullptr)
        {
            string.append( neuron->toString() );
        }
    }

    return string;
}
