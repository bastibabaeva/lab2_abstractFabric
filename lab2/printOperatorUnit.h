#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include <string>
#include <vector>
#include <unit.h>
#include <memory>
using namespace std;

class PrintOperatorUnit : public Unit { // Класс PrintOperatorUnit, наследуемый от Unit, для генерации текста в методах класса на С++
public:
    explicit PrintOperatorUnit(const string& text) : m_text(text) { } // Конструктор неявного преобразования (explicit) принимает строку текста text
    // и член класса m_text инициализируется этим параметром
    string compile(unsigned int level = 0) const; // переопределение метода, генерирующего код на с++ и возвращающего строку.

private:
    string m_text; // Строка текста, которая будет выводиться оператором вывода
};

#endif // PRINTOPERATORUNIT_H
