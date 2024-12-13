#pragma once
#include <iostream>

using namespace std;



template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    size_t Size;       
    size_t StartIndex; 
public:
    TVector(size_t s = 10, size_t si = 0);
    TVector(const TVector& v);                
    TVector(TVector&& moved);
    ~TVector();
    size_t GetSize() { return Size; } 
    size_t GetStartIndex() { return StartIndex; } 
    ValType& operator[](const size_t index);
    bool operator==(const TVector& v) const;  
    bool operator!=(const TVector& v) const;  
    TVector& operator=(const TVector& v);     

    
    TVector  operator+(const ValType& val);   
    TVector  operator-(const ValType& val);   
    TVector  operator*(const ValType& val);   

    TVector  operator+(const TVector& v);   
    TVector  operator-(const TVector& v);     
    ValType  operator*(const TVector& v);     

    
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (size_t i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (size_t i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector(size_t s , size_t si) : Size(s), StartIndex(si), pVector(new ValType[s])
{
    for (int i = 0; i != Size; i++) pVector[i] = ValType();
} /*-------------------------------------------------------------------------*/

template <class ValType> 
TVector<ValType>::TVector(const TVector& v): TVector { v.Size, v.StartIndex } {
   for (int i = 0; i != v.Size; i++) pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/
template <class ValType>
TVector<ValType>::TVector(TVector&& moved) {
    Size = moved.Size;
    pVector = new ValType[Size];
    for (int i = 0; i != moved.GetSize(); i++) pVector[i] = moved.pVector[i];
    StartIndex = moved.StartIndex;
    moved.pVector = nullptr;
    moved.Size = 0;
    moved.StartIndex = 0;
}
template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} 

template <class ValType> // ������
ValType& TVector<ValType>::operator[](const size_t index)
{
    if (index > Size + StartIndex || index < StartIndex) throw "incorrect index";
    return pVector[index - StartIndex];
} 


template <class ValType> // ���������
bool TVector<ValType>::operator==(const TVector<ValType>& v) const
{
    if (Size != v.Size && StartIndex != v.StartIndex) return false;
    for (int i = 0; i != Size; i++) 
    if (pVector[i] != v.pVector[i]) return false;                                   
    return true;
} 

template <class ValType> 
bool TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
} 

template <class ValType> 
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (*this == v) return *this;
    delete[] pVector;
    Size = v.Size;
    pVector = new ValType[Size];
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++) {
        pVector[i] = v.pVector[i];
    }
    return *this;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] += val;
    return res;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] -= val;
    return res;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> res(*this);
    for (int i = 0; i < Size; i++) res.pVector[i] *= val;
    return res;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "vectors of different sizes";
    if (StartIndex != v.StartIndex) throw "vectors of different start indexes";
    TVector res(Size, StartIndex);
    for (int i = 0; i != Size; i++) res.pVector[i] = pVector[i] + v.pVector[i];
    return res;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++) tmp.pVector[i] = pVector[i] - v.pVector[i];
    return tmp;
} 

template <class ValType> 
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    ValType tmp = ValType();
    for (int i = 0; i < Size; i++) {
        tmp += pVector[i] * v.pVector[i];
    }
    return tmp;
} 