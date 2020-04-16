#ifndef NEURONTYPE_HPP
#define NEURONTYPE_HPP

#include <string>
namespace NeuralNetwork
{
    enum class NeuronType
    {
        None,

        Input,
        Middle,
        Output,

        MaxNeuron
    };

    std::string toString(NeuronType type);
    NeuronType fromString(const std::string& type);
}

#endif // NEURONTYPE_HPP
