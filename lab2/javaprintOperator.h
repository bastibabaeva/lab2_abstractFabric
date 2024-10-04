#ifndef JAVAPRINTOPERATOR_H
#define JAVAPRINTOPERATOR_H
#include "printoperatorunit.h"

class JavaPrintOperator : public PrintOperatorUnit // Класс для создания конкретного продукта - оператора вывода на java
{
public:
    JavaPrintOperator(const string& text) : PrintOperatorUnit(text) {} //Определение пустого конструктора, который принимает строку текста
    // и передает ее в конструктор PrintOperatorUnit
    string compile(unsigned int level = 0) const { // переопределение метода для генерации текста на java, который хранится в объекте PrintOperatorUnit
        return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n"; // генерация отступа с заданным уровнем вложенности и
        // текста m_text. System.out.println используется вместо printf на java
    }
};


#endif // JAVAPRINTOPERATOR_H
