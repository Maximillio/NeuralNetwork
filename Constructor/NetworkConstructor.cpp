#include "NetworkConstructor.hpp"
#include "Network/Network.hpp"
#include "Layers/Layer.hpp"
#include "Links/Link.hpp"
#include "Neurons/InputNeuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include "Models/NetworkModelJson.hpp"
#include "Models/LayerModelJson.hpp"
#include "Models/NeuronModelJson.hpp"

std::shared_ptr<NeuralNetwork::Network> NeuralNetwork::NetworkConstructor::constructNetworkFromJsonModel(const NetworkModelJson& model) noexcept
{
    std::shared_ptr<Network> network = std::make_shared<Network>();
    size_t layerIndex = 0;
    for ( const auto& modelLayer : model.getLayers() )
    {
        std::shared_ptr<Layer> networkLayer = std::make_shared<Layer>();
        for ( const auto& modelNeuron : modelLayer.getNeurons() )
        {
            std::shared_ptr<Neuron> networkNeuron = nullptr;
            if ( !modelNeuron.getLinks().empty() )
            {
                std::shared_ptr<MiddleNeuron> middleNeuron = std::make_shared<MiddleNeuron>();
                createLinks( network, middleNeuron, modelNeuron.getLinks() );
                networkNeuron = middleNeuron;
            }
            else
            {
                networkNeuron = std::make_shared<InputNeuron>();
            }
            if (networkNeuron != nullptr)
            {
                networkLayer->addNeuron(networkNeuron);
            }
        }
        if ( !networkLayer->getNeuronsList().empty() )
        {
            if (layerIndex == 0)
            {
                network->addInputLayer(networkLayer);
            }
            if ( (layerIndex > 0 ) && ( layerIndex < (model.getLayers().size() - 1) ) )
            {
                network->addMiddleLayer(networkLayer, false);
            }
            if ( layerIndex == (model.getLayers().size() - 1) )
            {
                network->addOutputLayer(networkLayer, false);
            }
        }
        ++layerIndex;
    }
    return network;
}

bool NeuralNetwork::NetworkConstructor::createLinks(std::shared_ptr<NeuralNetwork::Network> network, std::shared_ptr<NeuralNetwork::MiddleNeuron> neuron, const std::list<double>& links) noexcept
{
    if ( (network == nullptr) || (neuron == nullptr) )
    {
        return false;
    }

    std::shared_ptr<Layer> previousLayer;

    if ( !network->getMiddleLayers().empty() )
    {
        previousLayer = network->getMiddleLayers().back();
    }
    else
    {
        previousLayer = network->getInputLayer();
    }
    if (previousLayer != nullptr)
    {
        auto linkIter = links.cbegin();
        for ( const auto& listNeuron : previousLayer->getNeuronsList() )
        {
            double linkValue = 0.0;
            if (linkIter != links.cend() )
            {
                linkValue = *linkIter;
                ++linkIter;
            }
            neuron->addLink(std::make_shared<Link>( Link(listNeuron, linkValue) ));
        }
    }
    return true;
}

NeuralNetwork::NetworkConstructor::NetworkConstructor() noexcept {}
