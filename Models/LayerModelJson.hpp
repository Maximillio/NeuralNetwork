#ifndef LAYERMODELJSON_HPP
#define LAYERMODELJSON_HPP

#include "Interface/JsonParsable.hpp"
#include "Models/NeuronModelJson.hpp"
#include <list>

namespace NeuralNetwork
{
    class LayerModelJson : public JsonParsable
    {
    public:
        LayerModelJson() noexcept;
        LayerModelJson(const Json& json) noexcept;
        const std::list<NeuronModelJson>& getNeurons() const noexcept;
        Json toJson() const;
        bool fromJson(const Json& json);
    private:
        std::list<NeuronModelJson> mNeurons;
    };
}

#endif // LAYERMODELJSON_HPP
