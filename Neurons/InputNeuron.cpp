#include "InputNeuron.hpp"
#include <strstream>

NeuralNetwork::InputNeuron::InputNeuron() {}

NeuralNetwork::InputNeuron::~InputNeuron() {}

NeuralNetwork::NeuronType NeuralNetwork::InputNeuron::getType() const noexcept
{
    return NeuronType::Input;
}

std::string NeuralNetwork::InputNeuron::toString() const noexcept
{
    std::strstream stream;
    stream << '|' <<"Value:" << mValue << '|' << std::endl;
    return stream.str();
}

void NeuralNetwork::InputNeuron::setValue(double value) noexcept
{
    mValue = value;
}
