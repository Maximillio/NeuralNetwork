#include "NeuronType.hpp"
#include "Constants.hpp"

std::string NeuralNetwork::toString(NeuralNetwork::NeuronType type)
{
    using namespace NeuralNetwork::Constants::Enums::NeuronType;

    switch (type)
    {
        case NeuronType::None:
            return std::string(None);
        case NeuronType::Input:
            return std::string(Input);
        case NeuronType::Middle:
            return std::string(Middle);
        case NeuronType::Output:
            return std::string(Output);
        case NeuronType::MaxNeuron:
            return std::string(NeuralNetwork::Constants::Strings::Empty);
    }
}

NeuralNetwork::NeuronType NeuralNetwork::fromString(const std::string& type)
{
    using namespace NeuralNetwork::Constants::Enums::NeuronType;

    if (type == Input) return NeuronType::Input;
    if (type == Input) return NeuronType::Middle;
    if (type == Input) return NeuronType::Output;

    return NeuronType::None;
}
