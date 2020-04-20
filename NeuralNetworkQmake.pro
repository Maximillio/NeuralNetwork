TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

TARGET = NeuralNetworkSimulator

SOURCES += main.cpp \
    Constructor/NetworkConstructor.cpp \
    Layers/Layer.cpp \
    Links/Link.cpp \
    Models/InputModelJson.cpp \
    Models/LayerModelJson.cpp \
    Models/NetworkModelJson.cpp \
    Models/NeuronModelJson.cpp \
    Network/Network.cpp \
    Types/NeuronType.cpp \
    Neurons/Neuron.cpp \
    Neurons/InputNeuron.cpp \
    Neurons/MiddleNeuron.cpp

HEADERS += \
    Constants.hpp \
    Constructor/NetworkConstructor.hpp \
    External/JsonParser/Json.hpp \
    Interface/JsonParsable.hpp \
    Interface/Printable.hpp \
    Layers/Layer.hpp \
    Links/Link.hpp \
    Models/InputModelJson.hpp \
    Models/LayerModelJson.hpp \
    Models/NetworkModelJson.hpp \
    Models/NeuronModelJson.hpp \
    Network/Network.hpp \
    Types/NeuronType.hpp \
    Neurons/Neuron.hpp \
    Neurons/InputNeuron.hpp \
    Neurons/MiddleNeuron.hpp
