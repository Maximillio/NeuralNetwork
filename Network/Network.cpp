#include "Network.hpp"
#include "Layers/Layer.hpp"
#include "Neurons/Neuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include <string>

NeuralNetwork::Network::Network() noexcept {}

bool NeuralNetwork::Network::addInputLayer(std::shared_ptr<NeuralNetwork::Layer> inputLayer) noexcept
{
    bool isValid = true;
    for ( auto neuron : inputLayer->getNeuronsList() )
    {
        if ( neuron->getType() != NeuronType::Input )
        {
            isValid = false;
            break;
        }
    }
    if (!isValid)
    {
        return false;
    }
    mInputLayer = std::move(inputLayer);
    return true;
}

bool NeuralNetwork::Network::addMiddleLayer(std::shared_ptr<NeuralNetwork::Layer> middleLayer) noexcept
{
    if ( !mMiddleLayers.empty() )
    {
        connectLayers( mMiddleLayers.back(), middleLayer);
    }
    else
    {
        connectLayers( mInputLayer, middleLayer);
    }
    mMiddleLayers.push_back(middleLayer);

    return true;
}

bool NeuralNetwork::Network::addOutputLayer(std::shared_ptr<NeuralNetwork::Layer> outputLayer) noexcept
{
    if ( !mMiddleLayers.empty() )
    {
        connectLayers(mMiddleLayers.back(), outputLayer);
        mOutputLayer = outputLayer;
        return true;
    }
    return false;
}

std::string NeuralNetwork::Network::toString() const noexcept
{
    std::string string;

    int index = 0;
    string.append("Input layer:");
    string.append("\r\n");
    string.append( std::to_string(index++) );
    string.append(".");
    string.append("\r\n");
    string.append( mInputLayer->toString() );
    string.append("\r\n");
    string.append("Middle layers:");
    string.append("\r\n");

    for (auto layer : mMiddleLayers)
    {
        string.append( std::to_string(index++) );
        string.append(".");
        string.append("\r\n");
        string.append( layer->toString() );
        string.append("\r\n");
    }
    string.append("Output layer:");
    string.append("\r\n");
    string.append( std::to_string(index++) );
    string.append(".");
    string.append("\r\n");
    string.append( mOutputLayer->toString() );
    string.append("\r\n");

    return string;
}

void NeuralNetwork::Network::connectLayers(std::shared_ptr<NeuralNetwork::Layer> previousLayer, std::shared_ptr<NeuralNetwork::Layer> nextLayer) noexcept
{
    for ( auto neuron : nextLayer->getNeuronsList() )
    {
        if (neuron->getType() == NeuronType::Middle)
        {
            dynamic_cast<MiddleNeuron*>(neuron.get())->addLinks( previousLayer->getLinks() );
        }
    }
}

