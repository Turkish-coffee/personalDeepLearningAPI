#include <iostream>
#include <string>
#include <map>
#include "../includes/ActivationFunction.hpp"


std::map<std::string, int> someMap = {
    { "ReLU", 1 },
    { "Sigmoid", 2 },
    { "Softmax", 3 },
};

ActivationFunction::ActivationFunction(std::string activationFunctionName) 
    :ActivationFunctionName(activationFunctionName)
{



}

ActivationFunction::~ActivationFunction() {


}