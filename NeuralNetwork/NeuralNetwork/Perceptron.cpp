#include "Perceptron.h"

Perceptron::~Perceptron()
{
    if (_neuron != nullptr)
        delete _neuron;
}

void Perceptron::setActivationFunction(FloatFunction activationFunction)
{
    _activationFunction = activationFunction;
}

Neuron* Perceptron::getNeuron() const
{
    return _neuron;
}

Perceptron::Perceptron(int weightsLength)
{
    _neuron = new Neuron();
    Matrix* weights = new Matrix(1, weightsLength);
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        float randomValue = (float(rand())/float((RAND_MAX)) * 2.0f) - 1.0f; //value in range -1.0/1.0
        weights->set(0,c,randomValue);
    }
    _neuron->setWeights(weights);
    float randomBias = (float(rand())/float((RAND_MAX)) * 0.2f) - 0.1f; //value in range -0.1/0.1
    _neuron->setBias(randomBias);
}

void Perceptron::train(const Matrix& inputs, const float target)
{
    float output = feedforward(inputs);
    float error = (target - output);
    Matrix* weights = _neuron->getWeights();
    for (int c = 0; c < weights->getColumns(); ++c)
    {
        float value = inputs.get(c, 0) * error * _learningRate;
        weights->set(0, c, value);
    }
    float bias = _neuron->getBias();
    bias += error;
    _neuron->setBias(bias);
}

float Perceptron::feedforward(const Matrix& inputs)
{
    assert(_activationFunction);
    assert(_neuron->getWeights()->getColumns() == inputs.getRows());
    _neuron->feedforward(inputs);
    Matrix& outputs = *_neuron->getOutputs();
    float sum =  _neuron->getBias();
    for (int r = 0; r < outputs.getRows(); ++r)
    {
        sum += outputs.get(r,0);
    }
    float result = _activationFunction(sum);
    return result;
}