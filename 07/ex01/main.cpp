#include "iter.hpp"

static void printing(int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
}

int main(void)
{
    const int size = 5;
    int arr1[size] = {10, 20, 30, 40, 50};

    std::cout << "Array elements before applying function:" << std::endl;
    printing(arr1, size);

    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Array elements after applying function multiply:" << std::endl;
    iter(arr1, size, multiply_by_2);
    printing(arr1, size);

    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Array elements after applying function divide:" << std::endl;
    iter(arr1, size, divide_by_2);
    printing(arr1, size);

    std::cout << "----------------------------------------" << std::endl;

    const std::string arr2[size] = {"1337", "Khouribga", "Akasec", "Ansamble", "Common-core"};
    iter(arr2, size, print_styled);

    return 0;
}