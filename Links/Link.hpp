#ifndef LINK_HPP
#define LINK_HPP

#include <memory>

namespace NeuralNetwork
{
    class Neuron;

    class Link
    {
    public:
        Link(std::shared_ptr<Neuron> neuron, double weight) noexcept;
        std::shared_ptr<Neuron> getNeuron() const noexcept;
        double getWeight() const noexcept;
        double getValue() const noexcept;
    private:
        std::shared_ptr<Neuron> mNeuron;
        double mWeight;
    };
}

#endif // LINK_HPP
