#include "NeuronModelJson.hpp"

NeuralNetwork::NeuronModelJson::NeuronModelJson() noexcept {}

NeuralNetwork::NeuronModelJson::NeuronModelJson(const Json& json) noexcept
{
    fromJson(json);
}

const std::list<double>& NeuralNetwork::NeuronModelJson::getLinks() const noexcept
{
    return mLinksValues;
}

void NeuralNetwork::NeuronModelJson::addLinkValue(int value) noexcept
{
    mLinksValues.push_back(value);
}

Json NeuralNetwork::NeuronModelJson::toJson() const
{
    Json json;
    json.push_back(mLinksValues);
    return json;
}

bool NeuralNetwork::NeuronModelJson::fromJson(const Json& json)
{
    if ( json.is_array() )
    {
        for ( const auto& value : json)
        {
            if ( value.is_number_float() )
            {
                mLinksValues.push_back( value.get<double>() );
            }
        }
        return true;
    }
    return false;
}
