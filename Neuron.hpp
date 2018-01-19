
namespace NeuralNetwork
{
    class Neuron
    {
    public:
        virtual ~Neuron();
        virtual double normalizeValue(double _value);
        double getValue();
    protected:
        Neuron();
    protected:
        double m_value;
    };
}
