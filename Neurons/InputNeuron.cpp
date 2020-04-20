#include "InputNeuron.hpp"
#include <string>

NeuralNetwork::InputNeuron::InputNeuron() noexcept {}

NeuralNetwork::InputNeuron::InputNeuron(double value) noexcept
    : Neuron(value) {}

NeuralNetwork::InputNeuron::~InputNeuron() noexcept {}

NeuralNetwork::NeuronType NeuralNetwork::InputNeuron::getType() const noexcept
{
    return NeuronType::Input;
}

std::string NeuralNetwork::InputNeuron::toString() const noexcept
{
    std::string string;

    string.append("|");
    string.append("Value:");
    string.append( std::to_string(mValue) );
    string.append("|");
    string.append("\r\n");

    return string;
}

void NeuralNetwork::InputNeuron::setValue(double value) noexcept
{
    mValue = value;
}
