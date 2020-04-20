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
        namespace Messages
        {
           const std::string Greeting = "Welcome to the neural network simulator!\r\n";
           const std::string Status = "Is the network set: %s.\r\n";
           const std::string Options = "Options:\r\n"
                                        "\t1. Read a network from a file.\r\n"
                                        "\t2. Read an input from a file.\r\n"
                                        "\t3. Process the network input.\r\n"
                                        "\t4. Print the network to the console.\r\n"
                                        "\t5. Clear the console.\r\n"
                                        "\t6. Exit.\r\n"
                                        "Input: ";
           const std::string InputFilename = "Enter a absolute(250 chars max) or "
                                             "relative(to folder when executabe was called) path(with extesion if present)"
                                             " to a JSON-format file with an info: \r\n";
           const std::string NetworkModelParsed = "A network model has been parsed successfully.\r\n";
           const std::string InputModelParsed = "A input values have been parsed successfully.\r\n";
           namespace Errors
           {
               const std::string NetworkIsNotSet = "The network is not set.\r\n";
               const std::string FileCannotBeOpen = "Unable to open the file with the path: %s\r\n"
    "\tPossbile reasons:\r\n"
    "\t- The path is incorrect.\r\n"
    "\t- The file does not exist.\r\n"
    "\t- File is open by an another process.\r\n";
               const std::string ParsingError = "An error has occured during parsing:\r\n%s\r\n";
               const std::string InvalidOption = "An invalid option selected.\r\n";
           }
        }
    }
}
#endif // CONSTANTS_HPP
