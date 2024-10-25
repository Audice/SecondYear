#pragma once
#include <iostream>
#include <stdint.h>

class BitField {
private:
    size_t _sizeBit;
    uint16_t* _mem;
    size_t _memSize;

    size_t GetMemIndex(size_t n) const;
    uint16_t GetMask(size_t n) const;
public:
    BitField(size_t len);
    BitField(const BitField& tmp);
    BitField& operator=(const BitField& tmp);
    
    size_t GetLength() const;
    void SetBit(size_t n);
    void ClrBit(size_t n);
    uint8_t GetBit(size_t n) const;


    BitField operator|(const BitField& tmp);
    BitField operator&(const BitField& tmp);
    BitField operator^(const BitField& tmp);
    bool operator==(const BitField& tmp) const;
    BitField operator~();

    ~BitField(){

    }
};