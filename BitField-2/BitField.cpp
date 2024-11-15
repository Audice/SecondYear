#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
    return (n / (sizeof(uint16_t) * 8));
}
uint16_t BitField::GetMask(size_t n) const {
    if ((n > _sizeBit) || (n < 0)) throw "incorrect";
	return 1 << (n & (sizeof(uint16_t) * 8 - 1));
}

BitField::BitField(size_t len) {
if (len < 0) throw "length can`t be negative";
	_sizeBit = len;
	_memSize = _sizeBit / (sizeof(uint16_t) * 8) + 1;
	_mem = new uint16_t[_memSize];
	for (int i = 0; i < _memSize; i++) _mem[i] = 0;
}

BitField::BitField(const BitField& tmp) {
_sizeBit = tmp._sizeBit;
	_memSize = tmp._memSize;
	_mem = new uint16_t[_memSize];
	for (int i = 0; i < _memSize; i++) _mem[i] = tmp._mem[i];
}

BitField& BitField::operator=(const BitField& tmp) {
    if (this == &tmp) {
		return(*this);
    }
	_sizeBit = tmp._sizeBit;
	_memSize = tmp._memSize;
	delete[] _mem;
	_mem = new uint16_t[_memSize];
	for (int i = 0; i < _memSize; i++) 
		_mem[i] = tmp._mem[i];
	return *this;
}
    
size_t BitField::GetLength() const {
    return _sizeBit;
}
void BitField::SetBit(size_t n) {
if ((n > _sizeBit) || (n < 0)) throw "incorrect n";
	_mem[GetMemIndex(n)] = (GetMask(n) | _mem[GetMemIndex(n)]);
}
void BitField::ClrBit(size_t n) {
if ((n > _sizeBit) || (n < 0)) throw "Negative n";
	_mem[GetMemIndex(n)] &= (~GetMask(n));
}
uint8_t BitField::GetBit(size_t n) const {
    if ((n > _sizeBit) || (n < 0)) throw "Negative n";
	if (_mem[GetMemIndex(n)] & GetMask(n)) return 1; else return 0;
}
BitField BitField::operator|(const BitField& tmp) {
    BitField bf(max(_sizeBit, tmp._sizeBit));
	for (int i = 0; i < _sizeBit; i++) {
		if (GetBit(i)) {
			bf.SetBit(i);
		}
	}
	for (int i = 0; i < tmp._memSize; i++) {
		bf._mem[i] = bf._mem[i] |= tmp._mem[i];
	}
	return (bf);
}
BitField BitField::operator&(const BitField& tmp) {
    BitField bf(max(_sizeBit, tmp._sizeBit));
	for (int i = 0; i < min(_memSize, tmp._memSize); i++) {
		bf._mem[i] = _mem[i] & tmp._mem[i];
	}
	return (bf);
}
BitField BitField::operator^(const BitField& tmp) {
    BitField result(_sizeBit);
    for (int i = 0; i < _memSize; i++)
        result._mem[i] = _mem[i] ^ tmp._mem[i];
    return result;
}

bool BitField::operator==(const BitField& tmp) const{
    if (_sizeBit != tmp.GetLength())
		return 0;
	else
	{
		for (int i = 0; i < _sizeBit; ++i)
		{
			if (GetBit(i) != tmp.GetBit(i))
				return 0;
		}
	}
	return 1;
}
BitField BitField::operator~(){
    BitField a(*this);
	for (int i = 0; i < (a._memSize - 1); i++) a._mem[i] = ~(a._mem[i]);
	for (int i = ((a._memSize - 1) * (sizeof(uint16_t) * 8)); i < (a._sizeBit); i++) {
		if (a.GetBit(i) == 1) a.ClrBit(i);
		else a.SetBit(i);
	}
	return a;
}

