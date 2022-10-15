#include<iostream>
#include"../includes/Layer.hpp"
#include"../includes/ActivationFunction.hpp"


Layer::Layer(unsigned int n_neuron, std::string activationFunctionName)
    :activationFunction(activationFunctionName)
{
    this->neuronNumber = n_neuron;
    

    
}

Layer ::~Layer() {

} 