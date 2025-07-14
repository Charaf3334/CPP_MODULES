#include <iostream>
#include <fstream>

int main(int ac, char **av)
{

    // std::ofstream file;
    // file.open("file.txt");
    // file << "Hey from cpp\n";
    // file.close();

    if (ac != 4) {
        std::cerr << "Number of args is not valid" << std::endl;
        return 1;
    }
    
    std::ifstream file;
    std::string s1 = av[2];
    std::string s2 = av[3];


    return (0);
}