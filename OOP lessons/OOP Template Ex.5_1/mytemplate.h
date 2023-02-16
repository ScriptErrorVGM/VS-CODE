#ifndef MYTEMPLATES
#define MYTEMPLATES

#include "cmath"

template <class T>
float average(T *arr, int n,float averg)
{
    float sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        sum = sum + arr[i].height;
        std::cout << i << " SUM " << sum << "\n";
        std::cout << i << " W " << arr[i].height << "\n";
    }
    
    return averg = (sum/n);
    //return averg;
}

template <class T>
float standartDeviation(T *arr, int n, float averg, float answer)
{
    float sum = 0;
    for(int i = 0; i < n-1; i++)
    { 
        sum = sum + pow((arr[i].height - averg),2);
        std::cout << i << " H " << arr[i].height << "\n";
    }
    return answer = pow(sum/n,0.5);
}
#endif // MYTEMPLATES

