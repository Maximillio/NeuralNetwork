#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <Neurons/Neuron.hpp>

namespace NeuralNetwork
{
    class InputNeuron : public Neuron
    {
    public:
        InputNeuron();
        ~InputNeuron() override;
        NeuronType getType() const noexcept override;
        std::string toString() const noexcept override;
        void setValue(double value) noexcept;
    };
}
#endif // INPUTNEURON_H
