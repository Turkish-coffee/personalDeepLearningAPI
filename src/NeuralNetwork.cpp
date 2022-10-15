#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../includes/ActivationFunction.hpp"
#include "../includes/NeuralNetwork.hpp"
#include "../includes/Layer.hpp"



NN::NN(std::string NNtype)
    :NNtype(NNtype)
{
    std::cout << "new "<< NNtype << " created" <<std::endl;
}

NN::~NN() {
    
}

std::map<std::string, int> my_map = {
    { "ANN", 1 },
    { "CNN", 2 },
    { "RNN", 3 },
    { "LSTM", 4 }
};

NN* NN::init(std::string NNtype) {
   
    try {

        switch (my_map[NNtype]) {

            case 1:
                return new ANN(NNtype);
                

            case 2:
                //return new CNN(NNtype);
                

            case 3:
                //return new RNN(NNtype);
                

            case 4:
                //return new LSTM(NNtype);
                

            default:
                throw "this NN type isn't currently supported";

                break;
            }
        
    }
    catch(const char *a)
    {
        std::cerr << a << '\n';
        exit(EXIT_FAILURE);
    }
    

    
}




ANN::ANN(std::string NNtype)
    :NN(NNtype)
{


}


ANN::~ANN() {

}

void ANN::Flatten(unsigned int inputSize) {
    this->INPUT_SIZE = inputSize;
}


void ANN::AddLayer(unsigned int NEURON_NUMBER, std::string activationFunction) {
    // we need to specifiy the layers to add with addLayer();
    this->NETWORK_LAYERS.push_back(Layer(NEURON_NUMBER, activationFunction));
    this->NETWORK_SIZE ++;
}

void ANN::Compile(std::string optimizer, std::string loss, std::string metric) {
    //we need to compile the ANN by calling the constructor
}

void ANN::FitData(double* inputData, double* target, unsigned int epochs) {
    //fit data with forward backward gradient descent ... 
}
