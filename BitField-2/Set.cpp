#include "Set.h"


Set::Set(size_t mp) : _bitField(10) {
    _maxPower = mp;
}
Set::Set(const Set& s) : _bitField(10) {
    _maxPower = s.GetMaxPower();
}
Set::Set(const BitField& bf) : _bitField(10) {

}

size_t Set::GetMaxPower() const {
    return _maxPower;
}
void Set::InsElem(const uint64_t Elem) {
    if ((Elem < _maxPower) & (Elem >= 0))
        _bitField.SetBit(Elem); else throw "Negative n";
}
void Set::DelElem(const uint64_t Elem) {
    if ((Elem < _maxPower) & (Elem >= 0))
        _bitField.ClrBit(Elem); else throw "Negative n";
}
bool Set::IsMember(const uint64_t Elem) const {
    if ((Elem < _maxPower) & (Elem >= 0))
        if (_bitField.GetBit(Elem) == 1) return 1;
        else return 0; else throw "Negative Elem";
}


bool Set::operator== (const Set& s) const {
    if (_maxPower != s.GetMaxPower())
        return 0;

    for (int i = 0; i < _maxPower; ++i)
    {
        if (_bitField.GetBit(i) != s._bitField.GetBit(i))
            return 0;
    }
    return 1;
}
bool Set::operator!= (const Set& s) const {
    return !(*this == s);
}
Set& Set::operator=(const Set& s) {
    return *this;
}
Set Set::operator+ (const uint64_t Elem) {
    Set a(*this);
    if ((Elem < _maxPower) & (Elem >= 0)) {
        a.InsElem(Elem);
    }
    else throw "Negative Elem";
    return a;
}

Set Set::operator- (const uint64_t Elem) {
    Set a(*this);
    if ((Elem < _maxPower) & (Elem >= 0)) {
        a.DelElem(Elem);
    }
    else throw "Negative Elem";
    return a;
}

Set Set::operator+ (const Set& s) {
    Set A(max(_maxPower, s.GetMaxPower()));
    A._bitField = _bitField | s._bitField;
    return A;
}
Set Set::operator* (const Set& s) {
    Set a(_bitField & s._bitField);
    return a;
}
Set Set::operator~ () {
    Set a(~_bitField);
    return a;
}
std::vector<uint64_t> Set::GetPrimary() {
    return std::vector<uint64_t>();
}
istream& operator>>(istream& istr, Set& s)
{
    for (int i = 0; i < s._maxPower; i++) {
        s.DelElem(i);
    }
    cout << "Input your set (enter any negative to stop)" << endl;
    int i;

    while (1) {
        istr >> i;
        if (i < 0) {
            return istr;
        }
        if ((i > s._maxPower)) {
            throw "OUTOFRANGE";
        }
        s.InsElem(i);
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const Set& s)
{
    cout << s._bitField;
    return ostr;
}
