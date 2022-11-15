#include <iostream>
#include <vector>
#include <string>
#include "./includes/matrix.hpp"
#include "./includes/ActivationFunction.hpp"
#include "./includes/NeuralNetwork.hpp"
#include "./includes/Layer.hpp"

/*template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}*/

int main() {
    NN* network = NN::init("ANN");
    network->Flatten(4);
    network->AddLayer(8,"Sigmoid");
    network->AddLayer(16,"ReLU");
    network->AddLayer(16,"ReLU");
    network->AddLayer(10,"Softmax");

    std::cout<< network->INPUT_SIZE << std::endl;

    for (auto elm : network->NETWORK_LAYERS)
    {
        std::cout <<"neuron number : " << elm.neuronNumber << std::endl << std::endl;
        std::cout << "input : " << elm.input->xDim << " x " << elm.input->yDim << std::endl;
        std::cout << "weights : " << elm.weights->xDim << " x " << elm.weights->yDim << std::endl;
        std::cout<< "bias : " << elm.bias->xDim << " x " << elm.bias->yDim << std::endl;
        std::cout << "result : " << elm.result->xDim << " x " << elm.result->yDim << std::endl << std::endl;
    }

    for (auto elem : network->NETWORK_LAYERS)
    {
    std::cout << "input matrix : " << std::endl;
    
    matrix::printMatrix(*elem.input);
    matrix::printMatrix(*elem.weights);
    elem.Calculate();
    matrix::printMatrix(*elem.result);
    
    }
 

    return EXIT_SUCCESS;
} 