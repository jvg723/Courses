//
// CS2024 Lecture #16, Demo 4
//
// MyArray
//

#include <stdexcept>

// Here's the MyArray template class
template <class T, int size>
class MyArray
{
    public:
        T &operator[](int i);
    
    private:
        T arrayStore[size];
};

// Overload array index operator
template <class T,int size>
T& MyArray<T,size>::operator[](int i)
{
    if ((i < 0) || (i >= size))
    {
        // throw an exception
        throw out_of_range("MyArray index is out of range");
    }

    return (arrayStore[i]);
}