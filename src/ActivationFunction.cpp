#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include "../includes/matrix.hpp"
#include "../includes/ActivationFunction.hpp"


std::map<std::string, int> someMap = {
    { "ReLU", 1 },
    { "Sigmoid", 2 },
    { "Softmax", 3 },
};

ActivationFunction::ActivationFunction(std::string ActvFunName) 
    :Name(ActvFunName) {

}

ActivationFunction::~ActivationFunction() {

}

void ActivationFunction::ActivationForward(matrix &x1) {

        
    for (int i = 0; i < x1.xDim; i++)
    {
        
        for (int j = 0; j < x1.yDim; j++)
        {
            switch (someMap[this->Name])
            {
                
            case 1: //ReLU
                if (x1.head[i][j] < 0)
                {  
                    x1.head[i][j] = 0;
                }
                
                break;
            
            case 2: //sigmoid

                x1.head[i][j] = 1 / (1 + exp(-x1.head[i][j]));

                break;
            
            case 3:
                    //TODO : make the softmax activation 
                    
                break;
            
            default:
                break;
            
            }

        }
        
    }
    
}
void ActivationFunction::ActivationDerivative(matrix &x1) {

}