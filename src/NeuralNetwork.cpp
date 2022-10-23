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
    //TODO:create the first layer here (no weight or bias rquired in this layer)
    //create a special Layer constructor for this
    //this layer wll only pass the inputs to the vector
}


void ANN::AddLayer(unsigned int NEURON_NUMBER, std::string activationFunction) {
    // we need to specifiy the layers to add with addLayer();

    //ADDING THE FIRST LAYER
    if(this->NETWORK_SIZE == 0) {
        this->NETWORK_LAYERS.push_back(Layer(NEURON_NUMBER, activationFunction));
        this->NETWORK_LAYERS[0].input =  new matrix(1, this->INPUT_SIZE);

        this->NETWORK_LAYERS[0].weights =  new matrix(this->NETWORK_LAYERS[0].input->yDim, NEURON_NUMBER);
        this->NETWORK_LAYERS[0].bias = new matrix(1, NEURON_NUMBER, 0.0);
        this->NETWORK_LAYERS[0].result = new matrix(1, this->NETWORK_LAYERS[0].input->yDim);
        this->NETWORK_SIZE ++;
        return;
    }

    //WE HAVE TO ADD LAYERS CONSIDERING THE PREVIOUS ONES 
    this->NETWORK_LAYERS.push_back(Layer(NEURON_NUMBER, activationFunction));
    this->NETWORK_LAYERS[0].input = new matrix(1, this->NETWORK_LAYERS[NETWORK_SIZE-1].input->yDim);

    this->NETWORK_LAYERS[NETWORK_SIZE].weights = new matrix(this->NETWORK_LAYERS[NETWORK_SIZE-1].input->yDim, NEURON_NUMBER);
    this->NETWORK_LAYERS[NETWORK_SIZE].bias = new matrix(1, NEURON_NUMBER, 0.0);
    this->NETWORK_LAYERS[NETWORK_SIZE].result = new matrix(1, this->NETWORK_LAYERS[NETWORK_SIZE-1].input->yDim);
    this->NETWORK_SIZE ++;
}

void ANN::Compile(std::string optimizer, std::string loss, std::string metric) {
    //we need to compile the ANN by calling the constructor
    
}

void ANN::FitData(double* inputData, double* target, unsigned int epochs) {
    //fit data with forward backward gradient descent ... 
}
