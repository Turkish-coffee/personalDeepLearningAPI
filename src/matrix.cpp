#include <iostream>
#include "../includes/matrix.hpp"
#include<random>
#include<iomanip>
#include<exception>


matrix::matrix(int xdim, int ydim)
    :xDim(xdim), yDim(ydim)
{
    this->head = (double **)malloc(sizeof(double*) * this->xDim);
    for (int i = 0; i < this->xDim; i++)
    {
        this->head[i] = (double *)malloc(sizeof(double) * this->yDim);
    }
    
}


matrix::matrix(int xdim, int ydim, double matrixNumber) 
    :xDim(xdim), yDim(ydim)
{
    this->head = (double **)malloc(sizeof(double*) * this->xDim);
    for (int i = 0; i < this->xDim; i++)
    {
        this->head[i] = (double *)malloc(sizeof(double) * this->yDim);
        for (int j = 0; j < this->yDim; j++)
        {
            this->head[i][j] = matrixNumber;
        }
        
    }

}


matrix::~matrix() {

    for (int i = 0; i < this->xDim; i++)
    {
        free(this->head[i]);
    }
    free(this->head);
}


void matrix::printMatrix(const matrix &x1) {

    for (int i = 0; i < x1.xDim; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < x1.yDim; j++)
        {
            std::cout << x1.head[i][j] << " ";
        }
      std::cout << " |" << std::endl;  
    }
    return;
}


void matrix::randomizeMatrix(const matrix &x1) {

    constexpr int MIN = 0;
    constexpr int MAX = 3;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    for (int i = 0; i < x1.xDim; i++)
    {
        for (int j = 0; j < x1.yDim; i++)
        {
            x1.head[i][j] = distr(eng)/(10 * MAX);
        }
        
    }
    return;
}


void matrix::sum(const matrix &x1, const matrix &x2, matrix &result) {

    try
    {
        if(x1.xDim != x2.xDim || x1.yDim != x2.yDim)
            throw "matrices dimensions not suitable to perform matrix addition";
        
        for (int i = 0; i < x1.xDim; i++)
        {
            for (int j = 0; j < x2.yDim; j++)
            {
                result.head[i][j] = x1.head[i][j] + x2.head[i][j];
            }
            
        }
    }
    catch(const char *array)
    {
        std::cerr << array << '\n';
        exit(EXIT_FAILURE);
    }
    

}


void matrix::multiply(const matrix &x1, const matrix &x2, matrix &result) {

    try
    {
        if(x1.yDim != x2.xDim)
            throw "matrices dimensions not suitable to perform matrix multiplication";

            for (int i = 0; i < x1.xDim; i++)
            {
                for (int j = 0; j < x2.yDim; j++)
                {
                    double sum = 0;
                    for (int k = 0; k < x2.xDim; k++)
                    {
                        sum += x1.head[i][k] * x2.head[k][j];
                    }
                    result.head[i][j] = sum;
                }
                
            }
    }
    catch(const char *array)
    {
        std::cerr << array << '\n';
        exit(EXIT_FAILURE);
    }
    
    
}