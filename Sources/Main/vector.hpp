#pragma once
#include <utility>
#include <iostream>

template <typename T>
class vector
{
public:
    vector();
    vector(int s);
    vector(const vector& right);
    ~vector();

    class iterator
    {
    public:
        iterator();
        iterator(T* it);
        ~iterator();

        iterator& operator=(const T& it);
        iterator& operator=(const iterator& it);
        T& operator*() { return *m_ptr; }
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);
        iterator& operator+(int n);
        iterator& operator-(int n);
        operator T*() const { return m_ptr; }
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        T* getPointer();
        friend std::ostream& operator<<(std::ostream& os, const iterator& it)
        {
            os << *it.m_ptr;
            return os;
        }

    private:
        T* m_ptr;
    };
    
    T& operator[](int index);
    void push_back(const T& elem);
    void erase(const iterator& it);
    void pop_back();//
    void clear();
    bool empty();
    int capacity() const { return m_capacity; }
    iterator begin() const;
    iterator end();
    vector<T>& operator=(const vector& right);
    bool operator==(const vector& right);
    bool operator!=(const vector& right);
    int size() const { return m_size; }
    const T& at(int index) const;
    
    friend void sort(iterator sortFrom, iterator sortTo){}

private:
    T* m_arr;
    int m_size;
    int m_capacity;

    void countCapacity()
    {
        while (m_capacity <= m_size)
        {
            m_capacity += 1;
        }
    }

    void expandVector(int numToExpand);
};

template <typename T>
vector<T>::vector() : m_size(0), m_capacity(4)
{
    m_arr = new T[m_capacity];
    std::cout << "default constructor (vector)\n";
}

template <typename T>
vector<T>::vector(int s) : m_size(s), m_capacity(4)
{
    countCapacity();
    m_arr = new T[m_capacity];
    std::cout << "size constructor (vector)\n";
}

template <typename T>
vector<T>::vector(const vector<T>& right)
{
    m_size = right.m_size;
    m_capacity = right.m_capacity;
    countCapacity();
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_arr[i] = right.m_arr[i];
    }
    std::cout << "copy constructor (vector)\n";
}

template <typename T>
vector<T>::~vector()
{
    delete[] m_arr;
    std::cout << "destructor (vector)\n";
}

template <typename T>
vector<T>::iterator::iterator()
    : m_ptr(nullptr)
{
    std::cout << "default constructor (iterator)\n";
}

template <typename T>
vector<T>::iterator::iterator(T* it)
{
    m_ptr = it;
    std::cout << "constructor with param (const T* it) (iterator)\n";
}

template <typename T>
vector<T>::iterator::~iterator()
{
    std::cout << "destructor (iterator)\n";
}

template <typename T>
T& vector<T>::operator[](int index)
{
    return m_arr[index];
}

template <typename T>
void vector<T>::push_back(const T& elem)
{
    if (m_size == m_capacity)
    {
        expandVector(1);
        m_arr[m_size - 1] = elem;
    }
    else
    {
        m_arr[m_size++] = elem;
    }
}

template <typename T>
void vector<T>::erase(const iterator& it)
{
    if(m_size == 0)
    {
        throw "error";
    }
    int count = 0;
    iterator iteratorToBegin = this->begin();
    while (iteratorToBegin++ != it)
    {
        if(count == m_size)
        {
            throw "count >=size";
        }
        count++;
    }
    for (int i = count; i < m_size - 1; i++)
    {
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}

template <typename T>
void vector<T>::pop_back()
{
    if(m_size <= 0)
    {
        throw "error";
    }
    m_size--;
}

template <typename T>
void vector<T>::clear()
{
    m_capacity = 4;
    m_size = 0;
    delete m_arr;
    m_arr = new T[m_capacity];
}

template <typename T>
bool vector<T>::empty()
{
    return m_size > 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() const
{
    return std::move(iterator(m_arr));
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
    return std::move(iterator(m_arr + m_size));
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& right)
{
    if (m_arr == right.m_arr)
    {
        return *this;
    }
    m_arr = new T[right.m_capacity];
    m_size = right.m_size;
    m_capacity = right.m_capacity;
    for (int i = 0; i < right.m_size; i++)
    {
        m_arr[i] = right.m_arr[i];
    }
    std::cout << "operator =(const vector&) (vector)\n";
    return *this;
}

template <typename T>
bool vector<T>::operator==(const vector& right)
{
    if (m_size != right.m_size)
    {
        return false;
    }

    for (int i = 0; i < m_size; ++i)
    {
        if (m_arr[i] != right.m_arr[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool vector<T>::operator!=(const vector& right)
{
    if (this == right)
    {
        return false;
    }
    return true;
}

template <typename T>
const T& vector<T>::at(int index) const
{
    if(index < 0 || index >= m_size)
    {
        throw "error";
    }
    return m_arr[index];
}

template <typename T>
T* vector<T>::iterator::getPointer()
{
    return m_ptr;
}

template <typename T>
void vector<T>::expandVector(int numToExpand)
{
    m_size += numToExpand;
    countCapacity();
    T* newVector = new T[m_capacity];
    for (int i = 0; i < m_size - numToExpand; ++i)
    {
        newVector[i] = m_arr[i];
    }
    delete m_arr;
    m_arr = newVector;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(const T& it)
{
    m_ptr = it;
    std::cout << "operator =(const T&) (iterator)\n";
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator& it)
{
    if (m_ptr == it.m_ptr)
    {
        return *this;
    }
    m_ptr = it.m_ptr;
    std::cout << "operator =(const iterator&) (iterator)\n";
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
    ++m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator--()
{
    --m_ptr;
    return *this;
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
    iterator temp = *this;
    ++m_ptr;
    return (temp);
}

template <typename T>
typename vector<T>::iterator vector<T>::iterator::operator--(int)
{
    iterator temp = *this;
    --m_ptr;
    return std::move(temp);
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator+(int n)
{
    m_ptr += n;
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator-(int n)
{
    m_ptr -= n;
    return *this;
}

template <typename T>
bool vector<T>::iterator::operator==(const iterator& right) const
{
    return m_ptr == right.m_ptr;
}

template <typename T>
bool vector<T>::iterator::operator!=(const iterator& right) const
{
    return m_ptr != right.m_ptr;
}

