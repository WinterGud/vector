template <typename T>
class vector
{
public:
    vector();
    vector(int s);
    ~vector();
    class iterator;
    T& operator[](int index);
    void push_back(T& elem);
    int capacity() { return m_capacity; }
    T* begin() { return m_arr; }
    vector<T>& operator=(const vector<T>& right);
    int size() { return m_size; }

    class iterator
    {
    public:
        iterator(): m_ptr(nullptr)
        {
        }

        iterator& operator=(T* it);
        T& operator*() { return *m_ptr; }

        vector<T>::iterator& operator++()
        {
            ++m_ptr;
            return *this;
        }

        vector<T>::iterator& operator--()
        {
            --m_ptr;
            return *this;
        }

        bool operator!=(const vector<T>::iterator& right)
        {
            if (m_ptr == &*right)
            {
                return false;
            }
            return true;;
        }

        bool operator!=(T* right)
        {
            if (m_ptr == right)
            {
                return false;
            }
            return true;
        }

        bool operator==(T* right)
        {
            if (m_ptr == right)
            {
                return true;
            }
            return false;;
        }

        friend std::ostream& operator<<(std::ostream& os, const iterator& it)
        {
            os << *it.m_ptr;
            return os;
        }

    private:
        T* m_ptr;
    };

private:
    T* m_arr;
    int m_size;
    int m_capacity;


    void countCapacity()
    {
        while (m_capacity <= m_size)
            m_capacity <<= 1;
    }
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
vector<T>::~vector()
{
    delete[] m_arr;
}

template <typename T>
T& vector<T>::operator[](int index)
{
    return m_arr[index];
}

template <typename T>
void vector<T>::push_back(T& elem)
{
    if (m_size < m_capacity)
    {
        m_arr[m_size] = elem;
    }
    else
    {
        countCapacity();
        m_arr[m_size] = elem;
    }
    m_size++;
    countCapacity();
}

template <typename T>
auto vector<T>::operator=(const vector<T>& right) -> vector<T>&
{
    if (m_arr == right.m_arr)
    {
        return *this;
    }
    this->m_arr = new T[right.m_capacity];
    for (size_t i = 0; i < right.m_size; i++)
    {
        this->m_arr[i] = right.m_arr[i];
    }
    return *this;
}

template <typename T>
typename vector<T>::iterator& vector<T>::iterator::operator=(T* it)
{
    m_ptr = it;
    return *this;
}
