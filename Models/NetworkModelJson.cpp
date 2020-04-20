#include "NetworkModelJson.hpp"


NeuralNetwork::NetworkModelJson::NetworkModelJson() noexcept {}

NeuralNetwork::NetworkModelJson::NetworkModelJson(const Json& json) noexcept
{
    fromJson(json);
}

const std::list<NeuralNetwork::LayerModelJson>& NeuralNetwork::NetworkModelJson::getLayers() const noexcept
{
    return mLayers;
}

Json NeuralNetwork::NetworkModelJson::toJson() const
{
    Json json;
    for (const auto& layer : mLayers)
    {
        json["network"].push_back( layer.toJson() );
    }
    return json;
}

bool NeuralNetwork::NetworkModelJson::fromJson(const Json& json)
{
    if ( json.is_object() )
    {
        if ( json.contains("network") )
        {
            Json network = json["network"];
            if ( network.is_object() )
            {
                if ( network.contains("layers") )
                {
                    Json layers = network["layers"];
                    for (const auto& layer : layers)
                    {
                        mLayers.push_back( LayerModelJson(layer) );
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
