#include "Array.hpp"

template <class T>
static void print(T &arr, size_t size)
{
    std::cout << "[";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
            std::cout << "," << " ";
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    try
    {
        Array<int> arr1(5);
        for (size_t i = 0; i < arr1.size(); i++)
            arr1[i] = i;
        print(arr1, arr1.size());

        std::cout << "--------------------------" << std::endl;

        Array<int> arr2 = arr1;
        print(arr2, arr2.size());
    
        std::cout << "--------------------------" << std::endl;

        arr1 = arr2;
        print(arr1, arr1.size());
        
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}