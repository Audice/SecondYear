#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

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
        _count = 0;
    }

    void AppendElem(T elem) {
        if (_count == 0){
            _max = elem;
            _min = elem;
        }
        if (_count == _size) {
            _size = _size * 4;
            T* new_arr = new T[_size];
            std::memcpy(new_arr, _array, _count*sizeof(T));
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = elem;
        if(elem < _min)
            _min = elem;
        if(elem > _max)
            _max = elem;
        _count++;
    }

    bool IsContains(T elem) {
        std::sort(_array, _array + _count);

        int left = 0;
        int right  = _count - 1;
        while (left <= right ) {
            int index = left + (right  - left) / 2;
            if (_array[index] == elem) {
                return true;
            } else if (_array[index] < elem) {
                left = index + 1;
            } else {
                right  = index - 1;
            }
        }
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