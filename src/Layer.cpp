#include <iostream>
#include"../includes/Layer.hpp"
#include "../includes/matrix.hpp"
#include"../includes/ActivationFunction.hpp"


// will be used only for the first layer
Layer::Layer(unsigned int n_neuron, std::string acvFunName)   
{
    
    this->neuronNumber = n_neuron;
    this->activationFunction = new ActivationFunction(acvFunName);


}



Layer ::~Layer() {

} 


void Layer::Calculate() {
    matrix::multiply(*this->input, *this->weights, *this->result);
    matrix::sum(*this->result, *this->bias, *this->result);
    //segmentation fault 
    this->activationFunction->ActivationForward(*this->result);
    
    return;
}