#pragma once

#include <memory>
#include "../../Miscellaneous/ISerializable.h"
#include "../Neuron.h"

class Perceptron final : public ISerializable
{
private:
    double _bias;
    std::unique_ptr<Neuron> _neuron;

public:
    Perceptron(int weights);
    double feedforward(const std::vector<double> inputs);
    void train(const std::vector<double> inputs, double target, double learningRate);
    void setActivationFunction(activationfunction::function activationFunction);
    void randomizeWeights();
    void serialize(std::ostream &stream) const override;
    void deserialize(std::istream &stream) override;
};
