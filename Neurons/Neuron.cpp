#include "Neuron.hpp"

NeuralNetwork::Neuron::~Neuron() noexcept {}

double NeuralNetwork::Neuron::getValue() const noexcept
{
    return mValue;
}

NeuralNetwork::Neuron::Neuron() noexcept
    : mValue(0) {}
