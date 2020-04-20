#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Interface/Printable.hpp"
#include <list>
#include <memory>

namespace NeuralNetwork
{
    class Layer;

    class Network : public Printable
    {
    public:
        Network() noexcept;
        bool addInputLayer(std::shared_ptr<Layer> inputLayer) noexcept;
        bool addMiddleLayer(std::shared_ptr<Layer> middleLayer, bool connectionRequired = true) noexcept;
        bool addOutputLayer(std::shared_ptr<Layer> outputLayer, bool connectionRequired = true) noexcept;
        const std::shared_ptr<Layer>& getInputLayer() const noexcept;
        const std::list<std::shared_ptr<Layer>>& getMiddleLayers() const noexcept;
        const std::shared_ptr<Layer>& getOutputLayer() const noexcept;
        bool setInputValues(std::list<double> values) noexcept;
        std::string toString() const noexcept override;
        bool iterate() noexcept;
    private:
        void connectLayers(std::shared_ptr<Layer> previousLayer, std::shared_ptr<Layer> nextLayer) noexcept;
    private:
        std::shared_ptr<Layer> mInputLayer;
        std::list<std::shared_ptr<Layer>> mMiddleLayers;
        std::shared_ptr<Layer> mOutputLayer;
    };
}

#endif // NETWORK_HPP
