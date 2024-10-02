#ifndef CSHARPMETHOD_H
#define CSHARPMETHOD_H
#include "methodUnit.h"

class CSharpMethod : public MethodUnit // Класс для создания конкретного продукта - метода на с#
{
public:
    CSharpMethod(const string& name, const string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {} //Определение пустого конструктора,
    // который принимает имя функции, тип возвращаемого значения и флаги(name, returnType, flags) и передает эти параметры в конструктор MethodUnit
    string compile(unsigned int level = 0) const // переопределение метода, который генерирует метод на с# и возвращает строку.
    // параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
    {
        string result = generateShift(level); // создание отступа в зависимости от заданного уровня вложенности
        if(m_flags & STATIC) { // Если флаг содержит STATIC, т.е. если результат побитовой операции истина (не равен 0), то
            result += "static ";
        }
        else if(m_flags & VIRTUAL) { // Иначе при проверке на наличие VIRTUAL в переменной m_flags добавляем в результат virtual
            result += "virtual ";
        }
        result += m_returnType + " "; // после static или virtual добавляем в строку тип возвращаемого значения (void)
        result += m_name + "()"; // добавляем имя метода и скобки
        // В C# нет модификатора const
        result += " {\n"; // Открываем фигурную скобку для начала тела метода
        for(const auto& b : m_body) { // Перебор всех элементов вектора m_body для рекурсивного вызова метода compile
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n"; // добавление отступа и закрывающей фигурной скобки для завершения тела метода.
        return result;
    }
};
#endif // CSHARPMETHOD_H
