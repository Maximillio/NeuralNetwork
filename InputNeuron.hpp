#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include <Neuron.hpp>

namespace NeuralNetwork
{
    class InputNeuron : public Neuron
    {
    public:
        InputNeuron();
        ~InputNeuron();
        void setValue(double _value);
    };
}
#endif // INPUTNEURON_H
