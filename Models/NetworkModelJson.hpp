#ifndef NETWORKMODELJSON_HPP
#define NETWORKMODELJSON_HPP

#include "Interface/JsonParsable.hpp"
#include "LayerModelJson.hpp"
#include <list>

namespace NeuralNetwork
{
    class NetworkModelJson : public JsonParsable
    {
    public:
        NetworkModelJson() noexcept;
        NetworkModelJson(const Json& json) noexcept;
        const std::list<LayerModelJson>& getLayers() const noexcept;
        Json toJson() const;
        bool fromJson(const Json& json);
    private:
        std::list<LayerModelJson> mLayers;
    };
}

#endif // NETWORKMODELJSON_HPP
