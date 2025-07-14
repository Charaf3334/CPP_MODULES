#include "Zombie.hpp"

int main(void)
{
    int N = 4;
    Zombie *arr = zombieHorde(N, "Messi");

    if (arr)
    {
        for (int i = 0; i < N; i++)
            arr[i].announce();
        delete[] arr;
    }
    return (0);
}