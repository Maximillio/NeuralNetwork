#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP

#include <string>

namespace NeuralNetwork
{
    class Printable
    {
    public:
        Printable() noexcept = default;
        virtual ~Printable() noexcept = default;
        virtual std::string toString() const noexcept = 0;
    };
}
#endif // PRINTABLE_HPP
