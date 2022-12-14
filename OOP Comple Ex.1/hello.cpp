/*
+ Описать тип-структуру «комплексное число», хранящую действительную и мнимую
части комплексного числа.
+ Описать функции для умножения и деления комплексных чисел, которые принимают в
качестве параметров два числа и возвращают число в качестве результата.
+ Описать функцию, принимающую комплексное число в качестве параметра и «красиво»
выводящую его на консоль.
+ Описать перечисление для задания вида комплексного числа: действительное, мнимое,
комплексное. Описать функцию, принимающую комплексное число в качестве параметра
и возвращающую вид числа. 
*/

#include <iostream>
#include "number.cpp"
#include "number.h"
#include "typenum.h"

using namespace std;

int main()
{
    Number parr1;
    parr1.real = 1;
    parr1.imag = 1;

    Number parr2;
    parr2.real = 6;
    parr2.imag = 7;

    Number temp;
    temp = div(parr1,parr2);
    Output(temp); //  z = 0.15 + (-0.01*i)
    
    temp = multi(parr1,parr2);
    Output(temp); //  z = -1.00 + (13.00*i)

    Number parr3;
    parr3.real = 1;
    parr3.imag = 0;

    typeNum tn1;
    tn1 = typeN(parr3);
    

    std::cout << "Type of input number is (REAL = 0 , IMAGINARY = 1, COMPLEX = 2) : " << tn1 << "\n"; // Type of input number is (REAL = 0 , IMAGINARY = 1, COMPLEX = 2) : 0

    return 0;
}