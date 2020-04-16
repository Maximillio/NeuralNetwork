TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Layers/Layer.cpp \
    Links/Link.cpp \
    Network/Network.cpp \
    Types/NeuronType.cpp \
    Neurons/Neuron.cpp \
    Neurons/InputNeuron.cpp \
    Neurons/MiddleNeuron.cpp

HEADERS += \
    Constants.hpp \
    Interface/Printable.hpp \
    Layers/Layer.hpp \
    Links/Link.hpp \
    Network/Network.hpp \
    Types/NeuronType.hpp \
    Neurons/Neuron.hpp \
    Neurons/InputNeuron.hpp \
    Neurons/MiddleNeuron.hpp
