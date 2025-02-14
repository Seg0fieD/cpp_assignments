#include "simple_matrix.hpp"
#include <iostream>

void printMatrix(SimpleMatrix simple_matrix);

int main(int, char *[]) {
    // The following should compile
    SimpleMatrix m1(50, 10);
    SimpleMatrix m2 = {{1, 2, 3}, {4, 5, 6}};
    SimpleMatrix m3(m2);
    m3 = m1;
    SimpleMatrix m4(std::move(m1));
    m4 = std::move(m2);
    m4.ncols();
    m4.nrows();
    m4(1, 1);
    const auto m5 = m4;
    std::cout<< m5(0, 1) << std::endl ;
    m4(0,1) = 111.0;
    
    
    printMatrix(m1);
    std::cout << "\n=======================================================\n";
    printMatrix(m2);
    std::cout << "\n=======================================================\n";
    printMatrix(m3);
    std::cout << "\n=======================================================\n";
    printMatrix(m4);
    std::cout << "\n=======================================================\n";
    printMatrix(m5);


    return 0;
}

void printMatrix(SimpleMatrix simple_matrix)
{

    for(auto i=0 ; i < simple_matrix.nrows() ; i++)
    {
        for(auto j= 0; j < simple_matrix.ncols(); j++)
        {
            std::cout << simple_matrix(i,j)<<'\t';
        }
        std::cout << '\n';
    }
     
}
