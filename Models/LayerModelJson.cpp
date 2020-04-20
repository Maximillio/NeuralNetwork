#include "LayerModelJson.hpp"

NeuralNetwork::LayerModelJson::LayerModelJson() noexcept {}

NeuralNetwork::LayerModelJson::LayerModelJson(const Json& json) noexcept
{
    fromJson(json);
}

const std::list<NeuralNetwork::NeuronModelJson>& NeuralNetwork::LayerModelJson::getNeurons() const noexcept
{
    return mNeurons;
}

Json NeuralNetwork::LayerModelJson::toJson() const
{
    return Json();
}

bool NeuralNetwork::LayerModelJson::fromJson(const Json& json)
{
    if ( json.is_object() )
    {
        if ( json.contains("neurons") )
        {
            Json neurons = json["neurons"];
            if ( neurons.is_array() )
            {
                for (const auto& neuron : neurons)
                {
                    if ( neuron.contains("links") )
                    {
                        Json links = neuron["links"];
                        mNeurons.push_back( NeuronModelJson(links) );
                    }
                }
                return true;
            }
        }
    }
    return false;
}
