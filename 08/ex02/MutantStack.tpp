#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &theOtherObject) : std::stack<T>(theOtherObject)
{

}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &theOtherObject)
{
    if (this != &theOtherObject)
        std::stack<T>::operator=(theOtherObject);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T>::iterator::iterator()
{
    this->pointer = NULL;
}

template <typename T>
MutantStack<T>::iterator::iterator(T* pointer)
{
    this->pointer = pointer;
}

template <typename T>
T& MutantStack<T>::iterator::operator*()
{
    return *this->pointer;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++()
{
    ++this->pointer;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++this->pointer;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--()
{
    --this->pointer;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
    iterator tmp = *this;
    --this->pointer;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator-(int num)
{
    iterator tmp = *this;
    tmp.pointer = tmp.pointer - num;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator+(int num)
{
    iterator tmp = *this;
    tmp.pointer = tmp.pointer + num;
    return tmp;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator &theOtherObject) const
{
    return this->pointer == theOtherObject.pointer;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &theOtherObject) const
{
    return this->pointer != theOtherObject.pointer;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    T *add = &(*this->c.begin());
    return iterator(add);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    T* add = &(*this->c.begin()) + this->c.size();
    return iterator(add);
}

#endif