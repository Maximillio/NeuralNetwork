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

bool NeuralNetwork::Network::addMiddleLayer(std::shared_ptr<NeuralNetwork::Layer> middleLayer, bool connectionRequired) noexcept
{
    if (connectionRequired)
    {
        if ( !mMiddleLayers.empty() )
        {
            connectLayers( mMiddleLayers.back(), middleLayer);
        }
        else
        {
            connectLayers( mInputLayer, middleLayer);
        }
    }
    mMiddleLayers.push_back(middleLayer);

    return true;
}

bool NeuralNetwork::Network::addOutputLayer(std::shared_ptr<NeuralNetwork::Layer> outputLayer, bool connectionRequired) noexcept
{
    if ( !mMiddleLayers.empty() )
    {
        if (connectionRequired)
        {
            connectLayers(mMiddleLayers.back(), outputLayer);
        }
        mOutputLayer = outputLayer;
        return true;
    }
    return false;
}

const std::shared_ptr<NeuralNetwork::Layer>& NeuralNetwork::Network::getInputLayer() const noexcept
{
    return mInputLayer;
}

const std::list<std::shared_ptr<NeuralNetwork::Layer>>& NeuralNetwork::Network::getMiddleLayers() const noexcept
{
    return mMiddleLayers;
}

const std::shared_ptr<NeuralNetwork::Layer>& NeuralNetwork::Network::getOutputLayer() const noexcept
{
    return mOutputLayer;
}

bool NeuralNetwork::Network::setInputValues(std::list<double> values) noexcept
{
    if ( values.empty() ) return false;
    if (mInputLayer == nullptr) return false;
    if ( mInputLayer->getNeuronsList().empty() ) return false;

    auto valuesIter = values.cbegin();
    for ( auto neuron : mInputLayer->getNeuronsList() )
    {
        double value = 0.0;
        if ( valuesIter != values.cend() )
        {
            value = *valuesIter;
            ++valuesIter;
        }
        neuron->setValue(value);
    }
    return true;
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
    if (mInputLayer != nullptr)
    {
        string.append( mInputLayer->toString() );
    }
    string.append("\r\n");
    string.append("Middle layers:");
    string.append("\r\n");

    for (auto layer : mMiddleLayers)
    {
        string.append( std::to_string(index++) );
        string.append(".");
        string.append("\r\n");
        if (layer != nullptr)
        {
            string.append( layer->toString() );
        }
        string.append("\r\n");
    }
    string.append("Output layer:");
    string.append("\r\n");
    string.append( std::to_string(index++) );
    string.append(".");
    string.append("\r\n");
    if (mOutputLayer != nullptr)
    {
        string.append( mOutputLayer->toString() );
    }
    string.append("\r\n");

    return string;
}

bool NeuralNetwork::Network::iterate() noexcept
{
    bool isValid = true;
    for (auto layer : mMiddleLayers)
    {
        isValid &= layer->iterate();
    }
    isValid &= mOutputLayer->iterate();
    return isValid;
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

