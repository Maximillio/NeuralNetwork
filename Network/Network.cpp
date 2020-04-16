#include "Network.hpp"
#include "Layers/Layer.hpp"
#include "Neurons/Neuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include <strstream>

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
    std::strstream stream;

    int index = 0;
    stream << "Input layer:" << std::endl;
    stream << index++ << '.'<< std::endl;
    stream << mInputLayer->toString();
    stream << "Middle layers:" << std::endl;
    for (auto layer : mMiddleLayers)
    {
        stream << index++ << '.'<< std::endl;
        stream << layer->toString();
    }
    stream << "Output layer:" << std::endl;
    stream << index++ << '.'<< std::endl;
    stream << mOutputLayer->toString();

    return stream.str();
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

