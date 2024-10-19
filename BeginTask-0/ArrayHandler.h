#include <iostream>
using namespace std;

template<typename T>
class ArrayHandler {
private:
    size_t _size;
    size_t _count;
    T* _array;
    T _max;
    T _min;
public:
    ArrayHandler(size_t size = 10){
        _size = size;
    _array = new T[_size];
    _count = 0;
    };

    void AppendElem(T elem){
        if(_count == _size){
            T *array = new T[_size * 2];
            for(int i = 0; i < _size; i++){
                array[i] = _array[i];
            }
            delete []_array;
            _array = array;
            _size = _size*2;
        }

        _array[_count] = elem;
        _count ++;



        if(_count == 1){
            _max = elem;
            _min = elem;
        } else {
            if(elem > _max){
                _max = elem;
            }
            if(elem < _min){
                _min = elem;
            }
        }
    };

    bool IsContains(T elem){
        for(int i = 0; i < _count; i++){
            if(elem == _array[i]){
                return true;
            }
        }
        return false;
    };

    T GetMax(){
        return _max;
    };

    T GetMin(){
        return _min;
    };

    ~ArrayHandler(){
         delete []_array;
    };

};