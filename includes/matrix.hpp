#pragma once
#include <iostream>

class matrix {

    public:

        int xDim;
        int yDim;

        double** head;
        
        matrix(int xdim, int ydim);
        matrix(int xdim, int ydim, double matrixNumber);
        ~matrix();

        static void printMatrix(const matrix &x1);
        static void randomizeMatrix(const matrix &x1);
        static void sum(const matrix &x1, const matrix &x2, matrix &result);
        static void multiply(const matrix &x1, const matrix &x2, matrix &result);
};
