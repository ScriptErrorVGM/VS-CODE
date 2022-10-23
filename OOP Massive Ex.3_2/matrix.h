#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

const int MAX = 2;

class Matrix
{
public:
    std::string text;
    double matrix[MAX][MAX];
    Matrix();
    Matrix(float x);
    void info();
    operator double();
    operator std::string();


};

#endif