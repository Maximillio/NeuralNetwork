#include "Layer.hpp"
#include "Neurons/Neuron.hpp"
#include "Links/Link.hpp"
#include <random>
#include <strstream>

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
        links.push_back( std::make_shared<Link>(neuron, static_cast<double>(rand()%100)/100.0) );
    }
    return links;
}

const std::list<std::shared_ptr<NeuralNetwork::Neuron> >& NeuralNetwork::Layer::getNeuronsList() const noexcept
{
    return mNeurons;
}

std::string NeuralNetwork::Layer::toString() const noexcept
{
    std::strstream stream;
    for (auto neuron : mNeurons)
    {
        stream << neuron->toString();
    }
    return stream.str();
}
