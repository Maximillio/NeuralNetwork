#ifndef INPUTMODELJSON_HPP
#define INPUTMODELJSON_HPP

#include "Interface/JsonParsable.hpp"
#include <list>
namespace NeuralNetwork
{
    class InputModelJson : public JsonParsable
    {
    public:
        InputModelJson() noexcept;
        InputModelJson(const Json& json) noexcept;
        Json toJson() const;
        bool fromJson(const Json& json);
        const std::list<double>& getValues() const noexcept;
    private:
        std::list<double> mValues;
    };
}

#endif // INPUTMODELJSON_HPP
