#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    throw std::runtime_error("Error: Can't work with an empty object.");
}

PmergeMe::PmergeMe(char **sequence)
{
    this->size = this->countSize(sequence);
    this->storeAtContainers(sequence);
}

PmergeMe::PmergeMe(const PmergeMe &theOtherObject)
{
    this->size = theOtherObject.size;
    this->V = theOtherObject.V;
    this->D = theOtherObject.D;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &theOtherObject)
{
    if (this != &theOtherObject)
    {
        this->size = theOtherObject.size;
        this->V = theOtherObject.V;
        this->D = theOtherObject.D;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{

}

size_t PmergeMe::countSize(char **sequence)
{
    size_t count = 0;
    for (size_t i = 1; sequence[i]; i++)
        count++;
    return count;
}

void PmergeMe::storeAtContainers(char **sequence)
{
    this->checkInput(sequence);

    for (size_t i = 1; i < this->size + 1; i++)
    {
        long num = atol(sequence[i]);
        if (num < 0)
            throw std::runtime_error("Error: " + std::string(sequence[i]) + " is a negative value.");
        if (num > INT_MAX)
            throw std::runtime_error("Error: " + std::string(sequence[i]) + " can't be stored as int.");
        std::vector<int>::iterator it = std::find(V.begin(), V.end(), num);
        if (it != V.end())
            throw std::runtime_error("Error: " + std::string(sequence[i]) + " is duplicated.");
        this->V.push_back(num);
        this->D.push_back(num);
    }
}

void PmergeMe::validNumber(std::string n)
{
    for (size_t i = 0; i < n.length(); i++)
    {
        if (i == 0 && (n[i] == '-' || n[i] == '+'))
            continue;
        else
        {
            if (!isdigit(n[i]))
                throw std::runtime_error("Error: " + n + " not a valid number.");
        }
    }
}

void PmergeMe::checkInput(char **sequence)
{
    for (size_t i = 1; i < this->size + 1; i++)
    {
        std::string placeholder = sequence[i];
        size_t length = placeholder.length();

        if (!length)
            throw std::runtime_error("Error: " + placeholder + " not a valid number.");
        if (length == 1)
        {
            if (!isdigit(placeholder[0]))
                throw std::runtime_error("Error: " + placeholder + " not a valid number.");
        }
        else
            this->validNumber(placeholder);
    }
}

bool PmergeMe::alreadySorted(void) const
{
    for (size_t i = 0; i < this->size - 1; i++)
    {
        if (this->V[i] > this->V[i + 1])
            return false;
    }
    return true;
}

void PmergeMe::printing(const std::string expression) const
{
    std::cout << expression + ": ";
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << this->V[i];
        if (i != this->size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector(void)
{
    this->printing("Before");
    std::clock_t time_start = std::clock();
    Algos<std::vector<int> >::mergeInsertSortingVector(this->V, this->size);
    this->printing("After");
    std::clock_t time_end = std::clock();
    double period = static_cast<double>(time_end - time_start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to sort a sequence of " << this->size << " numbers with a vector is: " << period << " microseconds!" << std::endl;
}

void PmergeMe::sortDeque(void)
{
    std::clock_t time_start = std::clock();
    Algos<std::deque<int> >::mergeInsertSortingDeque(this->D, this->size);
    std::clock_t time_end = std::clock();
    double period = static_cast<double>(time_end - time_start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to sort a sequence of " << this->size << " numbers with a deque is: " << period << " microseconds!" << std::endl;
}