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
        static matrix sum(const matrix &x1, const matrix &x2);
        static matrix multiply(const matrix &x1, const matrix &x2);
};
