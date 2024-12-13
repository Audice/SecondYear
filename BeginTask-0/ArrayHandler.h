
template<typename T>
class ArrayHandler {
private:
    size_t _size;
    T* _array;
    size_t count;
    int min;
	int max;
public:
    ArrayHandler(size_t size = 10) {
        if (size < 0) throw "error";
_size = size;
	count = 0;
	_array = new T[_size];
    }

    void AppendElem(T elem) {
if (count == 0) {
		min = elem;
		max = elem;
	}
	if (max < elem)
		max = elem;
	if (min > elem)
		min = elem;
	if (count == _size) {
		_size*=2;
		T* newArray = new T[_size];

		for (int i = 0; i < count; ++i) {
			newArray[i] = _array[i];
		}

		delete[] _array;
		_array = newArray;
	}

	_array[count++] = elem;
    }

    bool IsContains(T elem) {
        for (int i = 0; i < _size; i++) {
		if (elem == _array[i]) return true;
	}
        return false;
    }

    T GetMax() {
        return max;
    }

    T GetMin() {
        return min;
    }

    ~ArrayHandler() {
delete[] _array;
    }

};