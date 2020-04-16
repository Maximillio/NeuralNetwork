#include "Link.hpp"
#include "Neurons/Neuron.hpp"

NeuralNetwork::Link::Link(std::shared_ptr<Neuron> neuron, double weight) noexcept
    : mNeuron(neuron), mWeight(weight) {}

std::shared_ptr<NeuralNetwork::Neuron> NeuralNetwork::Link::getNeuron() const noexcept
{
    return mNeuron;
}

double NeuralNetwork::Link::getWeight() const noexcept
{
    return mWeight;
}

double NeuralNetwork::Link::getValue() const noexcept
{
    return (mNeuron->getValue() * mWeight);
}
