#include "pch.h"
#include "Heap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int len = 10;
    int v[len];

    std::cout << "[";

    for (int i = 0; i < len; i++)
    {
        v[i] = rand();
        std::cout << v[i] << " ";
    }

    std::cout << "]\n";

    HeapSort(v, len);

    std::cout << "[";

    for (int i = 0; i < len; i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout << "]\n";
}
