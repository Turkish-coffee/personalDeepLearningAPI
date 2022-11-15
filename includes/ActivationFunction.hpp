#pragma once
#include<iostream>
#include <string>
#include "../includes/matrix.hpp"
#include"../includes/ActivationFunction.hpp"

class ActivationFunction{

    public:

    std::string Name;
    
    ActivationFunction(std::string ActvFunName);
    ~ActivationFunction();

    void ActivationForward(matrix &x1);
    void ActivationDerivative(matrix &x1);
    
};
