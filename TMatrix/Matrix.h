#pragma once
#include "Vector.h"


template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
    TMatrix(size_t s = 10);
    TMatrix(const TMatrix& mt);                   
    TMatrix(const TVector<TVector<ValType> >& mt);
    bool operator==(const TMatrix& mt) const;     
    bool operator!=(const TMatrix& mt) const;      
    const TMatrix& operator= (const TMatrix& mt);        
    TMatrix  operator+ (const TMatrix& mt);        
    TMatrix  operator- (const TMatrix& mt);        
    TMatrix  operator* (const TMatrix& mt);        
    TVector<ValType> operator* (const TVector<ValType>& vc) {
        TVector<TVector<ValType>> mt = *this;
        TVector<ValType> tmp(vc);
        if (tmp.GetSize() != mt.GetSize()) throw "gg";
        TVector<ValType> res(tmp.GetSize());
        size_t count = 0;
        for (size_t i = 0; i != tmp.GetSize(); i++) {
            for (size_t j = 0; j != tmp.GetSize()-count; j++) {
                res[i] += mt[i][j+count] * tmp[j+count];
            }
            count++;
        }
        return res;
    }
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};

template <class ValType>
TMatrix<ValType>::TMatrix(size_t s) : TVector<TVector<ValType> >(s)
{
    for (int i = 0; i < s; i++) {
        this->pVector[i] = TVector<ValType>(s - i, i);
    }
} 

template <class ValType> 
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> 
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> 
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    return TVector<TVector<ValType>>::operator==(mt);
} 

template <class ValType> 
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
} 

template <class ValType> 
const TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    return TVector <TVector<ValType>>::operator=(mt);
} 

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    if (this->Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator+(mt);
} 

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    if (this->Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator-(mt);
}
template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{

    if (this->Size != mt.Size) throw "Not equal sizes";
    if (this->StartIndex != mt.StartIndex) throw "Not equal index";
    TMatrix<ValType> tmp(mt), res(this->Size);
    for (int i = 0; i < this->Size; i++)
    {
        for (int j = i; j < this->Size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                res[i][j] += (*this)[i][k] * tmp[k][j];
            }
        }

    }
    return res;
}


