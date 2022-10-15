#pragma once
#include<iostream>
#include <string>
#include"../includes/ActivationFunction.hpp"

class ActivationFunction{

    public:

    std::string ActivationFunctionName;
    
    ActivationFunction(std::string activationFunctionName);
    ~ActivationFunction();

};
