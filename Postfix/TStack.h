#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class TStack{
protected:
vector<T> _mem;
public:
virtual void Push(const T& data){
    if(IsFull()) throw "out of memory";
    _mem.push_back(data);
}
void Pop(){
    if(!IsEmpty())
    _mem.pop_back();
}
bool IsEmpty(){
    return _mem.size()==0 ? true : false;
}
bool IsFull(){
    return _mem.size() == 255 ? true:false;
}
virtual T Top() const{
    return _mem.back();
}
};