#ifndef MIDDLENEURON_HPP
#define MIDDLENEURON_HPP

#include <Neuron.hpp>
#include <map>

namespace NeuralNetwork
{
    class MiddleNeuron : public Neuron
    {
    public:
        MiddleNeuron();
        bool addLink(Neuron*, double);
        bool removeLink(Neuron*);
        double getLinkValue(Neuron*);
        bool setLinkValue(Neuron*);
        void getVaulesFromLinkedNeurons();

    protected:
        std::map<Neuron*, double> m_connectedLinks;
    };
}

#endif // MIDDLENEURON_HPP
