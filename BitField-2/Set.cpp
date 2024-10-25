#include "Set.h"


Set::Set(size_t mp) : _bitField(10) {

}
Set::Set(const Set &s) : _bitField(10){

} 
Set::Set(const BitField &bf) : _bitField(10){

}

size_t Set::GetMaxPower() const{
    return 0;
}    
void Set::InsElem(const uint64_t Elem){

}
void Set::DelElem(const uint64_t Elem){

}
bool Set::IsMember(const uint64_t Elem) const{
    return 0;
}


bool Set::operator== (const Set &s) const{
    return 0;
}
bool Set::operator!= (const Set &s) const{
    return 0;
}
Set& Set::operator=(const Set &s){
    return *this;
}
Set Set::operator+ (const uint64_t Elem){
    return *this;
}
                                  
Set Set::operator- (const uint64_t Elem){
    return *this;
}
                                   
Set Set::operator+ (const Set &s){
    return *this;
}
Set Set::operator* (const Set &s){
    return *this;
}
Set Set::operator~ (){
    return *this;
}
std::vector<uint64_t> Set::GetPrimary(){
    return std::vector<uint64_t>();
}