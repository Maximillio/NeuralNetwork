#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

namespace NeuralNetwork
{
    namespace Constants
    {
        namespace Strings
        {
            const std::string Empty = R"()";
        }
        namespace Enums
        {
            namespace NeuronType
            {
                const std::string None = R"(None)";
                const std::string Input = R"(Input)";
                const std::string Middle = R"(Middle)";
                const std::string Output = R"(Output)";
            }
        }
    }
}
#endif // CONSTANTS_HPP
