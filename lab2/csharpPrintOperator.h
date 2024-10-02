#ifndef CSHARPPRINTOPERATOR_H
#define CSHARPPRINTOPERATOR_H
#include "printOperatorUnit.h"

class CSharpPrintOperator : public PrintOperatorUnit // Класс для создания конкретного продукта - оператора вывода на C#
{
public:
    CSharpPrintOperator(const string& text) : PrintOperatorUnit(text) {} //Определение пустого конструктора, который принимает строку текста
    // и передает ее в конструктор PrintOperatorUnit
    string compile(unsigned int level = 0) const { // переопределение метода для генерации текста на C#, который хранится в объекте PrintOperatorUnit
        return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n"; // генерация отступа с заданным уровнем вложенности и
        // текста m_text. Console.WriteLine используется вместо printf на C#
    }
};
#endif // CSHARPPRINTOPERATOR_H
