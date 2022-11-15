#include "../includes/Optimizer.hpp"
#include "../includes/Loss.hpp"
#include "../includes/Layer.hpp"
#include<iostream>
#include<string>
#include <vector>

#pragma once

class NN {

public:

    std::string NNtype;
    unsigned int INPUT_SIZE;
    unsigned int OUTPUT_SIZE;
    unsigned int NETWORK_SIZE = 0;

    std::vector<Layer> NETWORK_LAYERS;

    Optimizer *optimizer;
    Loss *loss;

    //constructor / destructor 
    NN(std::string NNtype);
    virtual ~NN();
    
    
    static NN* init(std::string NNtype);

    virtual void Flatten(unsigned int inputSize) = 0;

    virtual void AddLayer(unsigned int NEURON_NUMBER, std::string activationFunction) = 0;

    virtual void Compile(std::string optimizer, std::string loss, std::string metric) = 0;

    virtual void FitData(double* inputData, double* target, unsigned int epochs) = 0;

};

class ANN : public NN {


    public: 
        
        ANN(std::string NNtype);

        ~ANN();

        void Flatten(unsigned int inputSize);

        void AddLayer(unsigned int NEURON_NUMBER, std::string activationFunction);

        void Compile(std::string optimizer, std::string loss, std::string metric);

        void FitData(double* inputData, double* target, unsigned int epochs);
 
};
