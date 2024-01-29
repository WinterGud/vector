#pragma once

template <typename T>
class vector
{
public:
    vector();
    vector(int s);
    vector(const vector<T>& right);
    ~vector();

    class iterator
    {
    public:
        iterator()
            : m_ptr(nullptr)
        {
        }

        iterator& operator=(const T& it);
        iterator& operator=(const iterator& it);
        T& operator*() { return *m_ptr; }
        iterator& operator++();
        iterator& operator--();
        iterator& operator+(int n);
        iterator& operator-(int n);
        bool operator!=(const iterator& right);
        bool operator==(const iterator& right);
        bool operator!=(const T& right);
        bool operator==(const T& right);
        operator T*() const { return m_ptr; }
        friend std::ostream& operator<<(std::ostream& os, const iterator& it)
        {
            os << *it.m_ptr;
            return os;
        }

    private:
        T* m_ptr;
    };

    const T& operator[](int index);
    void push_back(const T& elem);
    void erase(const iterator& it);
    int capacity() { return m_capacity; }
    iterator& begin();
    iterator& end() { return m_arr + m_size; }
    vector<T>& operator=(const vector& right);
    bool operator==(const vector& right);
    bool operator!=(const vector& right);
    int size() { return m_size; }

private:
    T* m_arr;
    int m_size;
    int m_capacity;

    void countCapacity()
    {
        while (m_capacity <= m_size)
        {
            m_capacity <<= 1;
        }
    }

    void expandVector(int numToExpand);
};

template <typename T>
vector<T>::vector() : m_size(0), m_capacity(4)
{
    m_arr = new T[m_capacity];
}

template <typename T>
vector<T>::vector(int s) : m_size(s), m_capacity(4)
{
    countCapacity();
    m_arr = new T[m_capacity];
}

template <typename T>
vector<T>::vector(const vector<T>& right)
{
    if (this == right)
    {
        return *this;
    }
    m_size = right.m_size;
    m_capacity = right.m_capacity;
    countCapacity();
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_arr[i] = right.m_arr[i];
    }
    return *this;
}

template <typename T>
vector<T>::~vector()
{
    delete[] m_arr;
}

template <typename T>
const T& vector<T>::operator[](int index)
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
    int count = 0;
    while (begin()++ != it)
    {
        count++;
    }
    for (int i = count; i > m_size - 1; ++i)
    {
        m_arr[i] = m_arr[i + 1];
    }
}

template <typename T>
typename vector<T>::iterator& vector<T>::begin()
{
    return iterator(m_arr);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& right)
{
    if (m_arr == right.m_arr)
    {
        return *this;
    }
    m_arr = new T[right.m_capacity];
    for (size_t i = 0; i < right.m_size; i++)
    {
        m_arr[i] = right.m_arr[i];
    }
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
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator& it)
{
    if(m_ptr == it.m_ptr)
    {
        return *this;
    }
    m_ptr = it.m_ptr;
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
bool vector<T>::iterator::operator!=(const iterator& right)
{
    if (m_ptr == right.m_ptr)
    {
        return false;
    }
    return true;
}

template <typename T>
bool vector<T>::iterator::operator==(const iterator& right)
{
    if (m_ptr == right.m_ptr)
    {
        return true;
    }
    return false;
}

template <typename T>
bool vector<T>::iterator::operator!=(const T& right)
{
    if (m_ptr == right)
    {
        return false;
    }
    return true;
}

template <typename T>
bool vector<T>::iterator::operator==(const T& right)
{
    if (m_ptr == right)
    {
        return true;
    }
    return false;
}