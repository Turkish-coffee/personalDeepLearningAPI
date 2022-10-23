#include<iostream>
#include"../includes/Layer.hpp"
#include"../includes/ActivationFunction.hpp"


// will be used only for the first layer
Layer::Layer(unsigned int n_neuron, std::string activationFunctionName)
    :activationFunction(activationFunctionName), neuronNumber(n_neuron)
{
    
      
}



Layer ::~Layer() {

} 