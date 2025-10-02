// AlgorithmAssignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <chrono>

//Initializing arrays of sizes for the sort
// 1000
// 10000
// 100000
float* bigArray = new float[1000];
float* biggerArray = new float[10000];
float* biggestArray = new float[100000];

void swap(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;

}
void simpleSort(float* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                swap(a[j], a[i]);
            }
        }
    }
}
float GetRandomFloat() {
    return ((float)rand() / (float)rand());
}
void InitializeArrayWithData(float* a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = GetRandomFloat();
    }
}
int main()
{
    srand(time(NULL));
    InitializeArrayWithData(bigArray, 1000);
    InitializeArrayWithData(biggerArray, 10000);
    InitializeArrayWithData(biggestArray, 100000);


    std::cout << "Sorting the array with 1000 values" << std::endl;
    auto start = std::chrono::steady_clock::now();
    simpleSort(bigArray, 1000);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting finished. It took " << elapsed.count() << "milliseconds." << std::endl;

    delete[] bigArray;

    std::cout << "Sorting the array with 10 000 values" << std::endl;
    start = std::chrono::steady_clock::now();
    simpleSort(biggerArray, 10000);
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting finished. It took " << elapsed.count() << "milliseconds." << std::endl;

    delete[] biggerArray;

    std::cout << "Sorting the array with 100 000 values" << std::endl;
    start = std::chrono::steady_clock::now();
    simpleSort(biggestArray, 100000);
    end = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting finished. It took " << elapsed.count() << "milliseconds." << std::endl;

    delete[] biggestArray;

    //RESULTS
    // Array with 1000 values took 10 milliseconds
    // 10 000 took 111 milliseconds
    // 100 000 took 10577 milliseconds
    //This implies O(n^2). The algorithm is really slow for sorting arrays with many values
}
