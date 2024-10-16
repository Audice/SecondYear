#include "Set.h"
#include "BitField.h"
#include <vector>


Set::Set(const Set& set) : _bitField(set._maxPower){
    _maxPower = set._maxPower;
    _bitField = set._bitField;
}

void Set::InsertElem(uint64_t elem){
    _bitField.SetBit(elem);
}

void Set::DeleteElem(uint64_t elem){
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem){
    return _bitField.GetBit(elem);
}

std::vector<uint64_t> Set::GetPrimary(){
    std::vector<uint64_t> prost;
    Set copy(*this);

    for(size_t i = 2; i < _maxPower; i++){
        if(IsMember(i)){
            for(size_t p = i*i; p <= _maxPower; p += i){
                DeleteElem(p);
            }
        }
    }
    for(size_t i = 2; i < _maxPower; i++){
        if(IsMember(i))
            prost.push_back(i);
    }  
    return prost;      

}
