#include "Neuron.hpp"

NeuralNetwork::Neuron::~Neuron() noexcept {}

double NeuralNetwork::Neuron::getValue() const noexcept
{
    return mValue;
}

void NeuralNetwork::Neuron::setValue(double value) noexcept
{
    mValue = value;
}

NeuralNetwork::Neuron::Neuron() noexcept
    : mValue(0) {}

NeuralNetwork::Neuron::Neuron(double value) noexcept
    : mValue(value) {}
