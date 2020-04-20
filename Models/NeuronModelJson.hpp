#ifndef NEURONMODELJSON_HPP
#define NEURONMODELJSON_HPP

#include <list>
#include "Interface/JsonParsable.hpp"
namespace NeuralNetwork
{
    class NeuronModelJson : public JsonParsable
    {
    public:
        NeuronModelJson() noexcept;
        NeuronModelJson(const Json& json) noexcept;
        const std::list<double>& getLinks() const noexcept;
        void addLinkValue(int value) noexcept;
        Json toJson() const override;
        bool fromJson(const Json& json) override;
    private:
        std::list<double> mLinksValues;
    };
}

#endif // NEURONMODELJSON_HPP
