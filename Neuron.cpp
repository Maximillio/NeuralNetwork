#include "Neuron.hpp"

NeuralNetwork::Neuron::~Neuron() {}

double NeuralNetwork::Neuron::normalizeValue(double _value) {return _value;}

double NeuralNetwork::Neuron::getValue()
{
    return normalizeValue(m_value);
}

NeuralNetwork::Neuron::Neuron() : m_value(0) {}
