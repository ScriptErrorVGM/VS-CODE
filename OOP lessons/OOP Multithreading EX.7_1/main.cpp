// Найти количество элементов матрицы равных нулю. 
// Количество нулевых элементов по
// каждой строке матрицы рассчитывается отдельным потоком.

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

void equal_null(vector<int> arr, int& count) 
{                                   
    int result = 0;
    for (int element : arr) {
        if(element == 0){
            result += 1;
            //cout << result << "-- --" << endl;
        }
    }
    count = result;
}

int main()
{
    int vectorNumber = 10; // Число строк матрицы
    int vectorSize = 1000; // Число столбцов

    vector<vector<int> > matrix(vectorNumber);
    for (vector<int>& element : matrix)
    {
        element = vector<int>(vectorSize);
    }

    for(int i = 0; i < vectorNumber; i++)
    {
        for(int j = 0; j < vectorSize; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    vector<int> vectorOfNull(vectorNumber);
    vector<thread> vectorOfTreads(vectorNumber);

    for(int i = 0; i < vectorNumber; i++)
    {
        vectorOfTreads[i] = thread(equal_null, matrix[i], ref(vectorOfNull[i]));
    }

    for(int i = 0; i < vectorNumber; i++)
    {
        vectorOfTreads[i].join();
    }

    for(int i = 0; i < vectorNumber; i++)
    {
        cout << vectorOfNull[i] << "\n";
    }

    return 0;
}