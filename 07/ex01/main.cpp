#include "iter.hpp"

template <typename T, size_t Length>
static void print(T (&arr)[Length])
{
    std::cout << "[";
    for (size_t i = 0; i < Length; i++)
    {
        std::cout << arr[i];
        if (i != Length - 1)
            std::cout << "," << " ";
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    int arr1[] = {10, 20, 30, 40, 50};
    const size_t size = sizeof(arr1) / sizeof(arr1[0]);

    std::cout << "Array elements before applying function:" << std::endl;
    print(arr1);

    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Array elements after applying function multiply:" << std::endl;
    iter(arr1, size, multiply_by_2);
    print(arr1);

    std::cout << "----------------------------------------" << std::endl;

    std::cout << "Array elements after applying function divide:" << std::endl;
    iter(arr1, size, divide_by_2);
    print(arr1);

    std::cout << "----------------------------------------" << std::endl;

    const std::string arr2[size] = {"1337", "Khouribga", "Akasec", "Ansamble", "Common-core"};
    iter(arr2, size, print_styled);

    return 0;
}