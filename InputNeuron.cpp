#include "InputNeuron.hpp"

NeuralNetwork::InputNeuron::InputNeuron() {}

NeuralNetwork::InputNeuron::~InputNeuron() {}

void NeuralNetwork::InputNeuron::setValue(double _value)
{
    m_value = _value;
}
