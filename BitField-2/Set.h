#pragma once
#include <vector>
#include "BitField.h"

class Set
{
private:
  int _maxPower;       // максимальная мощность множества
  BitField _bitField; // битовое поле для хранения характеристического вектора
public:
  Set(int mp);
  Set(const Set &s);       // конструктор копирования
  Set(const BitField &bf); // конструктор преобразования типа
  operator BitField();      // преобразование типа к битовому полю
  // доступ к битам
  int GetMaxPower(void) const;     // максимальная мощность множества
  void InsElem(const int Elem);       // включить элемент в множество
  void DelElem(const int Elem);       // удалить элемент из множества
  int IsMember(const int Elem) const; // проверить наличие элемента в множестве
  // теоретико-множественные операции
  int operator== (const Set &s) const; // сравнение
  int operator!= (const Set &s) const; // сравнение
  Set& operator=(const Set &s);  // присваивание
  Set operator+ (const int Elem); // объединение с элементом
                                   // элемент должен быть из того же универса
  Set operator- (const int Elem); // разность с элементом
                                   // элемент должен быть из того же универса
  Set operator+ (const Set &s);  // объединение
  Set operator* (const Set &s);  // пересечение
  Set operator~ (void);           // дополнение
  std::vector<uint64_t> GetPrimary(); // Выдать простые числа множества
};