#include <cstdint>
#include <cstring>
#include <iostream>

template<typename T>  //pupupu
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    long long int _count;
    T _max;
    T _min;
public:
    ArrayHandler(size_t size = 10) {
        _size = size;
        _array = new T[_size];
        _max = INT8_MIN;
        _min = INT8_MAX;
        _count = 0;
    }

    void AppendElem(T elem) {
        if (_count == _size) {
            _size = _size * 4;
            T* new_arr = new T[_size];
            std::memcpy(new_arr, _array, _count*sizeof(int8_t));
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = elem;
        _count++;
    }

    bool IsContains(T elem) {
        return false;
    }

    T GetMax() {
        return _max;
    }

    T GetMin() {
        return _min;
    }

    ~ArrayHandler() {
        delete [] _array;
    }

};