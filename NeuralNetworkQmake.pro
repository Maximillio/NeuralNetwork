TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Neuron.cpp \
    InputNeuron.cpp

HEADERS += \
    Neuron.hpp \
    InputNeuron.hpp
