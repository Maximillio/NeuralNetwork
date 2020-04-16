#ifndef LAYER_HPP
#define LAYER_HPP

#include "Interface/Printable.hpp"
#include <list>
#include <memory>

namespace NeuralNetwork
{
    class Neuron;
    class Link;

    class Layer : public Printable
    {
    public:
        Layer() noexcept;
        void addNeuron(std::shared_ptr<Neuron> neuron) noexcept;
        void addNeurons(const std::list<Neuron*>& neuron) noexcept;
        std::list<std::shared_ptr<Link>> getLinks() const;
        const std::list<std::shared_ptr<Neuron>>& getNeuronsList() const noexcept;
        std::string toString() const noexcept override;
    private:
        std::list<std::shared_ptr<Neuron>> mNeurons;

        // Printable interface
    public:

    };
}

#endif // LAYER_HPP
