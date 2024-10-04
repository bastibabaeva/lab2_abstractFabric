#ifndef JAVAMETHOD_H
#define JAVAMETHOD_H
#include "methodunit.h"

class JavaMethod : public MethodUnit // Класс для создания конкретного продукта - метода на java
{
public:
    JavaMethod(const string& name, const string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {} //Определение пустого конструктора,
    // который принимает имя функции, тип возвращаемого значения и флаги(name, returnType, flags) и передает эти параметры в конструктор MethodUnit
    string compile(unsigned int level = 0) const // переопределение метода, который генерирует метод на с++ и возвращает строку.
    // параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
    {
        string result = generateShift(level); // создание отступа в зависимости от заданного уровня вложенности
        if(m_flags & STATIC) { // Если флаг содержит STATIC, т.е. если результат побитовой операции истина (не равен 0), то
            result += "static ";
        }
        //В Java final используется вместо const, только перед именем метода. Если не final, то метод автоматически virtual
        else if(m_flags & FINAL) { // Иначе при проверке на наличие FINAL в переменной m_flags добавляем в результат final
            result += "final "; // Модификатор final используется для завершения реализации методов
        }
        else if(m_flags & ABSTRACT) { // Иначе при проверке на наличие ABSTRACT в переменной m_flags добавляем в результат abstract
            result += "abstract "; // Модификатор abstract необходим для создания абстрактных методов
        }
        else if(m_flags & SYNCHRONIZED) { // Иначе при проверке на наличие SYNCHRONIZED в переменной m_flags добавляем в результат synchronized
            result += "synchronized "; // Модификатор synchronized используется для указания того, что метод может быть доступен только одним потоком одновременно
        }

        result += m_returnType + " "; // после модификатора доступа добавляем в строку тип возвращаемого значения (void)
        result += m_name + "()"; // добавляем имя метода и скобки
        result += " {\n"; // Открываем фигурную скобку для начала тела метода
        for(const auto& b : m_body) { // Перебор всех элементов вектора m_body для рекурсивного вызова метода compile
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n"; // добавление отступа и закрывающей фигурной скобки для завершения тела метода.
        return result;
    }
};

#endif // JAVAMETHOD_H
