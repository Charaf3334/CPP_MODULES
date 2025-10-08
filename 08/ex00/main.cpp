#include "easyfind.hpp"

int main(void)
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    try
    {
        const int target = 400;
        int index = easyfind(v, target);
        std::cout << "Target " << target << " found at: " << index << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}