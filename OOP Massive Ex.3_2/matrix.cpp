#include "matrix.h"

Matrix::Matrix()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int y = 0; y < MAX; y++)
        {
            matrix[i][y] = 0;
        }
        
    }
}

Matrix::Matrix(float x)
{
    for(int i = 0; i < MAX; i++)
    {
        for(int y = 0; y < MAX; y++)
        {
            matrix[i][y] = x;
        }
        
    }
}

void Matrix::info()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int y = 0; y < MAX; y++)
        {
            std::cout << matrix[i][y] << " ";
        }
        std::cout << "\n";
    }    
}

Matrix::operator double()
{   
    return (matrix[0][0] * matrix[1][1] - matrix[1][0]*matrix[0][1]);
}

Matrix::operator std::string()
{
    std::cout << " TEST text " << "\n"; 
    for(int i = 0; i < MAX; i++)
    {
        for(int y = 0; y < MAX; y++)
        {
            text += std::to_string(matrix[i][y]);
        }
        
    }    
    return text;
}