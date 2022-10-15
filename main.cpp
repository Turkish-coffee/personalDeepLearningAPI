#include <iostream>
#include <vector>
#include <string>
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
    network->AddLayer(8,"ReLU");
    network->AddLayer(16,"ReLU");
    network->AddLayer(16,"ReLU");
    network->AddLayer(10,"Softmax");

    std::cout<< network->INPUT_SIZE << std::endl;

    for (auto elm : network->NETWORK_LAYERS)
    {
        std::cout << elm.neuronNumber << std::endl;
    }
    
    
    return EXIT_SUCCESS;
} 