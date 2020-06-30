#include <cstdio>
#include <exception>
#include <climits>
#include <limits>
#include <stdexcept>
#include <iostream>

template <typename T>
class Vector
{
public:
    explicit Vector();
    explicit Vector(size_t size,size_t value);
    Vector(Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    size_t size() const;
    size_t max_size(const Vector& vector)const;
    void resize(size_t size,T value=T(0));
    size_t capacity()const;
    bool empty()const;
    void reserve(size_t capacity);
    T& operator[](size_t index);
    const T& operator[](size_t index)const;
    T& at(size_t index);
    const T& at(size_t index)const;
    T& front();
    const T& front()const;
    T& back();
    const T& back()const;
    T* data();
    const T* data()const;
    void assign(size_t size,const T& value);
	void insert(size_t index,const T& val);
	void pushBack(const T& val);
	T& erase(size_t index);
	T& popBack();
	void  swap(Vector& vec);
	void clear();
	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

private:
    T* m_arr;
    size_t m_size;
    size_t m_capacity;
template<class U>
friend std::ostream& operator<<(std::ostream& out,const Vector& vec);
};

template <typename T>
inline Vector<T>::Vector():m_arr(NULL),m_size(0),m_capacity(0)
{
}

template <typename T>
inline Vector<T>::Vector(size_t size,size_t value):m_arr(NULL),m_size(size),m_capacity(size)
{
    m_arr = new T[size];
    for(size_t i=0;i<size;i++)
        m_arr[i]=value;
}

template <typename T>
inline Vector<T>::Vector(Vector& other):m_arr(NULL),m_size(other.m_size),m_capacity(other.m_capacity)
{
    m_arr = new T[other.m_capacity];
    for(size_t i=0;i<other.m_size;i++)
        m_arr[i]=other.m_arr[i];
}

template <typename T>
inline Vector<T>::~Vector()
{
    delete [] m_arr;
    m_arr=NULL;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    T* tmp=m_arr;
    m_arr = new T[other.m_capacity];
    delete [] tmp;
    for(int i=0;i<other.m_size;i++)
        m_arr[i]=other.m_arr[i];
    return *this;
}


template <typename T>
inline size_t Vector<T>::size() const
{
    return m_size;
}

template <typename T>
inline size_t Vector<T>::max_size(const Vector<T>& vector) const
{
    return std::numeric_limits<size_t>::max();
}

template <typename T>
void Vector<T>::resize(size_t size,T value)
{
    /*if(size==m_size)
        return;
    else if(size<m_size)
        m_size=size;
    else
    {
        m_size=size;
        m_capacity=size*2;
        T* tmp= m_arr;
        m_arr= new T[m_capacity];
        for(size_t i=0;i<m_size;i++)
            m_arr[i]=tmp[i];
        delete [] tmp;
        for(size_t i=m_size;i<size;i++)
            m_arr[i]=value;
    }*/
	size_t temp=m_size;
	if(size<m_size)
	{
		for(size_t i=size+1; i<temp;i++)
			popBack();
	}
	else if(size>m_size)
	{
		for(size_t i=size+1; i<temp;i++)
			pushBack(value);
	}
}

template <typename T>
inline size_t Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
inline bool Vector<T>::empty() const
{
    return m_size==0;
}

template <typename T>
void Vector<T>::reserve(size_t capacity)
{
    if(m_capacity<capacity)
    {
        /*T* tmp=m_arr;
        m_arr=new T[capacity];
        for(size_t i=0;i<m_size;i++)
            m_arr[i]=tmp[i];
        m_capacity=capacity;*/
	m_capacity=capacity;
	T* m_arr2=new T[m_capacity];
	for(size_t i; i<=m_size;i++)
		m_arr2[i]=m_arr[i];
	m_arr=m_arr2;
	delete [] m_arr;
	
    }
}

template <typename T>
inline T&  Vector<T>::operator[](size_t index)
{
    return m_arr[index];
}

template <typename T>
inline T&  Vector<T>::at(size_t index)
{
    if(index>=m_size)
        throw std::out_of_range("out of range");
    return m_arr[index];
}


template <typename T>
inline const T&  Vector<T>::operator[](size_t index)const
{
    return m_arr[index];
}

template <typename T>
inline const T&  Vector<T>::at(size_t index) const
{
    if(index>=m_size)
        throw std::out_of_range("out of range");
    return m_arr[index];
}

template <typename T>
inline T& Vector<T>::front()
{
    return m_arr[0];
}

template <typename T>
inline const T& Vector<T>::front()const
{
    return m_arr[0];
}

template <typename T>
inline T& Vector<T>::back()
{
    return m_arr[m_size-1];
}

template <typename T>
inline const T& Vector<T>::back()const
{
    return m_arr[m_size-1];
}

template <typename T>
inline T* Vector<T>::data()
{
    return m_arr;
}

template <typename T>
inline const T* Vector<T>::data()const
{
    return m_arr;
}

template <typename T>
inline void Vector<T>::assign(size_t size,const T& value)
{
	delete[] m_arr;  
	Vector(size,value);
}

template <typename T>
void Vector<T>::insert(size_t index,const T& val)
{
	if(index>=m_size||index<0)
		throw std::invalid_argument("BAD INDEX");
	if(m_size==m_capacity)
		m_capacity*=2;
	size_t i;
	for(i = index; i < m_size; i++)
	{
		m_arr[i+1]=m_arr[i];
	}
	m_arr[index]=val;
	m_size++;
}

template <typename T>
inline void Vector<T>::pushBack(const T& val)
{
	m_arr[m_size]=val;
	m_size++;
}

template <typename T>
T& Vector<T>::erase(size_t index)
{
	if(index>=m_size||index<0)
		throw std::invalid_argument("BAD INDEX");
	T temp=m_arr[index];
	size_t i;
	for(i=index;i<m_size;i++)
	{
		m_arr[i]=m_arr[i+1];
	}
	m_size--;
	~T(m_arr[m_size]);
	return temp;
}

template <typename T>
T& Vector<T>::popBack()
{
	T temp=m_arr[m_size-1];
    	m_size--;
	~T(m_arr[m_size]);
	return temp;
}

template <typename T>
void  Vector<T>::swap(Vector& vec)
{
	Vector v1(vec);
	vec.m_size=m_size;
	vec.m_capacity=m_capacity;
    vec.m_arr = new T[vec.m_capacity];
    for(size_t i=0;i<vec.m_size;i++)
	{
        vec.m_arr[i]=m_arr[i];
	}
	m_size=v1.m_size;
	m_capacity=v1.m_capacity;
    m_arr = new T[v1.m_capacity];
	for(size_t i=0;i<v1.m_size;i++)
        m_arr[i]=v1.m_arr[i];
	delete v1;
}

template <typename T>
inline void Vector<T>::clear()
{
	for(size_t i; i<m_size;i++)	
	{
		~T(m_arr[i]);
	}
	m_size=0;
}

template <typename T>
T* Vector<T>::begin()
{
	T* iterator=&(m_arr[0]);
}

template <typename T>
const T* Vector<T>::begin() const
{
	
	T* iterator=&(m_arr[0]);
}

template <typename T>
T* Vector<T>::end()
{
	if(empty())
		return begin();
	T* iterator=&(m_arr[m_size-1]);
	return iterator;
}

template <typename T>
const T* Vector<T>::end() const
{
	if(empty())
		return begin();
	T* iterator=&(m_arr[m_size-1]);
	return iterator;
}

//------------------------------------------------------------global funcs
template <typename T>
Vector<T> operator+(const Vector<T>& vec1, const Vector<T>& vec2)
{
	Vector<T> vec3(vec1);
	size_t i;
	for (i = 0; i <vec2.size(); i++)
	{
		vec3.pushBack(vec2.data()[i]);
	}
	return vec3;
}

template <typename T>
Vector<T>& operator+=(Vector<T>& vec1, const Vector<T>& vec2)
{
	size_t i;
	for (i = vec1.size(); i <vec2.size(); i++)
	{
		vec1.pushBack(vec2.data()[i]);
	}
	return vec1;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,const Vector<T>& vec)
{
	size_t i;
	for(i = 0; i <vec.m_size(); i++)
		os<<vec.m_arr[i]<<" ";
	os<<std::endl;
	return os;
}


