#ifndef NETWORKCONSTRUCTOR_HPP
#define NETWORKCONSTRUCTOR_HPP

#include <memory>
#include <list>

namespace NeuralNetwork
{
    class Network;
    class NetworkModelJson;
    class MiddleNeuron;
    class Link;

    class NetworkConstructor
    {
    public:
        static std::shared_ptr<Network> constructNetworkFromJsonModel(const NetworkModelJson& model) noexcept;
    private:
        static bool createLinks(std::shared_ptr<Network> network, std::shared_ptr<MiddleNeuron> neuron, const std::list<double>& links) noexcept;
        NetworkConstructor() noexcept;
    };
}

#endif // NETWORKCONSTRUCTOR_HPP
