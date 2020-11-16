#include <algorithm>
#include <cstdint>
using namespace std;

template <typename T>
class MyVector {
public:
    MyVector() = default;
    explicit MyVector(size_t size);
    MyVector(const MyVector<T> &vector);
    ~MyVector();

    T& operator[](size_t index);
    T& operator[](size_t index) const;
    MyVector<T> &operator=(const MyVector &v);

    T* begin();
    T* end();
    T* begin() const;
    T* end() const;

    size_t Size() const;

    void PushBack(T value);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void ExpandIfNeeded();
};

template <typename T>
MyVector<T>::MyVector(size_t size)
        : data(new T[size])
        , size(size)
        , capacity(size)
{
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &vector) {
    this->data = vector.data;
    this->size = vector.size;
    this->capacity = vector.capacity;
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
T &MyVector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
size_t MyVector<T>::Size() const {
    return size;
}

template <typename T>
void MyVector<T>::PushBack(T value) {
    ExpandIfNeeded();
    data[size++] = move(value);
}

template <typename T>
void MyVector<T>::ExpandIfNeeded() {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        // используем перемещение
        move(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
}

template <typename T>
T* MyVector<T>::begin() {
    return data;
}

template <typename T>
T* MyVector<T>::end() {
    return data + size;
}

template <typename T>
T* MyVector<T>::begin() const {
    return data;
}

template <typename T>
T* MyVector<T>::end() const {
    return data + size;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &v) {
    delete[] this->data;
    this->data = new T[v.capacity];
    for (int i = 0; i < v.size; i++) {
        data[i] = v.data[i];
    }
    this->size = v.size;
    this->capacity = v.capacity;
}
