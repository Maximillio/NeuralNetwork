#ifndef NEURON_HPP
#define NEURON_HPP

#include "Types/NeuronType.hpp"
#include "Interface/Printable.hpp"

namespace NeuralNetwork
{
    class Neuron : public Printable
    {
    public:
        virtual ~Neuron() noexcept override;
        double getValue() const noexcept;
        void setValue(double value) noexcept;
        virtual NeuronType getType() const noexcept = 0;
        virtual std::string toString() const noexcept override = 0;
    protected:
        Neuron() noexcept;
        Neuron(double value) noexcept;
    protected:
        double mValue;
    };
}

#endif //NEURON_HPP
