#include <iostream>

#include "Neurons/InputNeuron.hpp"
#include "Neurons/MiddleNeuron.hpp"
#include "Layers/Layer.hpp"
#include "Network/Network.hpp"
#include "Models/NetworkModelJson.hpp"
#include "Models/InputModelJson.hpp"
#include "Constructor/NetworkConstructor.hpp"
#include "Constants.hpp"
#include <memory>
#include <list>
#include <random>
#include <fstream>

int main()
{

    std::ifstream stream;
    NeuralNetwork::NetworkModelJson* networkModel = nullptr;
    NeuralNetwork::InputModelJson* inputModel = nullptr;
    std::shared_ptr<NeuralNetwork::Network> network = nullptr;
    bool finished = false;
    printf_s( NeuralNetwork::Constants::Messages::Greeting.c_str() );
    while (!finished)
    {
        printf_s( NeuralNetwork::Constants::Messages::Status.c_str(), ( (network != nullptr) ? "True"  : "False" ));
        printf_s( NeuralNetwork::Constants::Messages::Options.c_str() );

        int choise = 0;
        int isInputVaid = scanf_s("%d", &choise);
        if ( isInputVaid != 1 ) { choise = -1; char trashBuffer[250]; scanf_s( "%s", trashBuffer, sizeof(trashBuffer) ); }

        switch(choise)
        {
            case 1:
                {
                    printf_s( NeuralNetwork::Constants::Messages::InputFilename.c_str() );
                    char path[250];
                    scanf_s( "%s", path, sizeof(path) );
                    std::ifstream stream(path);
                    if ( stream.is_open() )
                    {
                        try
                        {
                            networkModel = new NeuralNetwork::NetworkModelJson( Json::parse(stream) );
                        }
                        catch(Json::exception& exception)
                        {
                            printf_s( NeuralNetwork::Constants::Messages::Errors::ParsingError.c_str(), exception.what() );
                        }
                        if (networkModel != nullptr)
                        {
                            network = NeuralNetwork::NetworkConstructor::constructNetworkFromJsonModel(*networkModel);
                            delete networkModel;
                            printf_s( NeuralNetwork::Constants::Messages::NetworkModelParsed.c_str() );
                        }
                        networkModel = nullptr;
                    }
                    else
                    {
                        printf_s(NeuralNetwork::Constants::Messages::Errors::FileCannotBeOpen.c_str(), path);
                    }
                }
            break;
            case 2:
                if (network != nullptr)
                {
                    printf_s( NeuralNetwork::Constants::Messages::InputFilename.c_str() );
                    char path[250];
                    scanf_s( "%s", path, sizeof(path) );
                    std::ifstream stream(path);
                    if ( stream.is_open() )
                    {
                        try
                        {
                            inputModel = new NeuralNetwork::InputModelJson( Json::parse(stream) );
                        }
                        catch(Json::exception& exception)
                        {
                            printf_s( NeuralNetwork::Constants::Messages::Errors::ParsingError.c_str(), exception.what() );
                        }
                        if (network != nullptr)
                        {
                            network->setInputValues( inputModel->getValues() );
                            delete inputModel;
                        }
                        inputModel = nullptr;
                        printf_s( NeuralNetwork::Constants::Messages::InputModelParsed.c_str() );
                    }
                    else
                    {
                        printf_s(NeuralNetwork::Constants::Messages::Errors::FileCannotBeOpen.c_str(), path);
                    }
                }
                else
                {
                    printf_s( NeuralNetwork::Constants::Messages::Errors::NetworkIsNotSet.c_str() );
                }
            break;
            case 3:
                if (network != nullptr)
                {
                    network->iterate();
                    printf_s( "\r\n%s\r\n", network->toString().c_str() );
                }
                else
                {
                    printf_s( NeuralNetwork::Constants::Messages::Errors::NetworkIsNotSet.c_str() );
                }
            break;
            case 4:
                if (network != nullptr)
                {
                    printf_s( "\r\n%s\r\n", network->toString().c_str() );
                }
                else
                {
                    printf_s( NeuralNetwork::Constants::Messages::Errors::NetworkIsNotSet.c_str() );
                }
            break;
            case 5:
                 system("cls");
            break;
            case 6:
                finished = true;
            break;
            default:
                printf_s( NeuralNetwork::Constants::Messages::Errors::InvalidOption.c_str() );
            break;
        }

    }

    return 0;
}
