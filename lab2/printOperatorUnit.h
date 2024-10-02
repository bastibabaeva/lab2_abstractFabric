#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include <string>
#include <vector>
#include "unit.h"
#include <memory>
using namespace std;

class PrintOperatorUnit : public Unit  // Класс PrintOperatorUnit, наследуемый от Unit, для генерации текста в методах класса на С++
{
    friend class CPlusPlusPrintOperator; //класс CPlusPlusPrintOperator объявляем другом класса PrintOperatorUnit для того, чтобы мы могли
        // обращаться к приватным член-данным текущего класса
public:
    explicit PrintOperatorUnit(const string& text) : m_text(text) { } // Конструктор неявного преобразования (explicit) принимает строку текста text
    // и член класса m_text инициализируется этим параметром

private:
    string m_text; // Строка текста, которая будет выводиться оператором вывода
};

#endif // PRINTOPERATORUNIT_H
