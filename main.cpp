#include <iostream>

#include "Neurons/InputNeuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include "Layers/Layer.hpp"
#include "Network/Network.hpp"
#include <memory>
#include <list>

int main()
{
    NeuralNetwork::Network network;
    std::shared_ptr<NeuralNetwork::Layer> inputLayer = std::make_shared<NeuralNetwork::Layer>();
    for (int i = 0; i < 3; ++i)
    {
        inputLayer->addNeuron( std::shared_ptr<NeuralNetwork::Neuron>(new NeuralNetwork::InputNeuron{}) );
    }
    network.addInputLayer( std::move(inputLayer) );

    for (int i = 0; i < 3; ++i)
    {
        std::shared_ptr<NeuralNetwork::Layer> middleLayer = std::make_shared<NeuralNetwork::Layer>();
        for (int j = 0; j < 3; ++j)
        {
            middleLayer->addNeuron( std::shared_ptr<NeuralNetwork::Neuron>( new NeuralNetwork::MiddleNeuron{} ) );
        }
        network.addMiddleLayer( std::move(middleLayer) );
    }

    std::shared_ptr<NeuralNetwork::Layer> outputLayer = std::make_shared<NeuralNetwork::Layer>();
    for (int j = 0; j < 3; ++j)
    {
        outputLayer->addNeuron( std::shared_ptr<NeuralNetwork::Neuron>( new NeuralNetwork::MiddleNeuron{} ) );
    }
    network.addOutputLayer( std::move(outputLayer) );


    std::cout << network.toString() << std::endl;
    return 0;
}
