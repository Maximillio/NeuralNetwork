#include "InputModelJson.hpp"

NeuralNetwork::InputModelJson::InputModelJson() noexcept {}

NeuralNetwork::InputModelJson::InputModelJson(const Json& json) noexcept
{
    fromJson(json);
}

Json NeuralNetwork::InputModelJson::toJson() const
{
    return Json();
}

bool NeuralNetwork::InputModelJson::fromJson(const Json& json)
{
    if ( json.contains("input_values") )
    {
        if ( json["input_values"].is_array() )
        {
            for ( const auto& value : json["input_values"] )
            {
                if ( value.is_number() )
                {
                    mValues.push_back( value.get<double>() );
                }
            }
            return true;
        }
    }
    return false;
}

const std::list<double>& NeuralNetwork::InputModelJson::getValues() const noexcept
{
    return mValues;
}

