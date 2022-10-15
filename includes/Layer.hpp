#pragma once
#include"../includes/ActivationFunction.hpp"
#include"../includes/matrix.hpp"
#include<vector>
#include<string>

class Layer {

    public:

        //to make a layer, we have to know the number of 
        //neurons and their activation function:

        unsigned int neuronNumber;

        //Storing the inputs from the previous layer, the wieghts and biases
        //into 2Darrays, storing the forward operation in the result one
        matrix **input;
        matrix ** weights;
        matrix **bias;
        matrix **result;
    
        ActivationFunction activationFunction;

        Layer(unsigned int n_neuron, std::string activationFunctionName);
        virtual ~Layer();
 
        
};