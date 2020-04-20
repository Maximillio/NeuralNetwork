#ifndef JSONPARSABLE_HPP
#define JSONPARSABLE_HPP

#include "External/JsonParser/Json.hpp"

using Json = nlohmann::json;

class JsonParsable
{
public:
    virtual ~JsonParsable() = default;
    virtual Json toJson() const = 0;
    virtual bool fromJson(const Json& json) = 0;
};

#endif // JSONPARSABLE_HPP
