#include "BitField.h"


size_t BitField::GetMemIndex(size_t n) const{
    return 0;
}
uint16_t BitField::GetMask(size_t n) const {
    return 0;
}

BitField::BitField(size_t len) {

}

BitField::BitField(const BitField& tmp) {

}

BitField& BitField::operator=(const BitField& tmp) {
    return *this;
}
    
size_t BitField::GetLength() const {
    return 0;
}
void BitField::SetBit(size_t n) {

}
void BitField::ClrBit(size_t n) {

}
uint8_t BitField::GetBit(size_t n) const {
    return 0;
}
BitField BitField::operator|(const BitField& tmp) {
    return *this;
}

BitField BitField::operator&(const BitField& tmp) {
    return *this;
}
BitField BitField::operator^(const BitField& tmp) {
    return *this;
}
bool BitField::operator==(const BitField& tmp) const{
    return false;
}
BitField BitField::operator~(){
    return *this;
}