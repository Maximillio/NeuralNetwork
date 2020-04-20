#ifndef MIDDLENEURON_HPP
#define MIDDLENEURON_HPP

#include <Neurons/Neuron.hpp>
#include <list>
#include <memory>

namespace NeuralNetwork
{
    class Link;

    class MiddleNeuron : public Neuron
    {
    public:
        MiddleNeuron() noexcept;
        MiddleNeuron(const std::list<std::shared_ptr<Link>>& links) noexcept;
        MiddleNeuron(std::list<std::shared_ptr<Link>>&& links) noexcept;
        NeuronType getType() const noexcept override;
        void addLink(std::shared_ptr<Link> link) noexcept;
        void addLinks(const std::list<std::shared_ptr<Link>>& links);
        std::string toString() const noexcept override;
        void readLinksValues() noexcept;
    private:
        double sigmaFunction(double value);
    protected:
        std::list<std::shared_ptr<Link>> mLinks;
    };
}

#endif // MIDDLENEURON_HPP
