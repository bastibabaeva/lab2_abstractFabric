#include "methodUnit.h"

void MethodUnit::add(const shared_ptr <Unit>& unit, Flags) { // метод для добавления элементов типа Unit в конец вектора m_body
    m_body.push_back(unit);
}

string MethodUnit::compile(unsigned int level) const { // метод, который генерирует код на с++ и возвращает строку.
    // параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
    string result = generateShift(level); // создание отступа в зависимости от заданного уровня вложенности
    if(m_flags & STATIC) { // Если флаг содержит STATIC, т.е. если результат побитовой операции истина (не равен 0), то
        result += "static ";
    }
    else if(m_flags & VIRTUAL) { // Иначе при проверке на наличие VIRTUAL в переменной m_flags добавляем в результат virtual
        result += "virtual ";
    }
    result += m_returnType + " "; // после static или virtual добавляем в строку тип возвращаемого значения (void)
    result += m_name + "()"; // добавляем имя метода и скобки
    if(m_flags & CONST) { // Если флаг содержит CONST, т.е. если результат побитовой операции истина (не равен 0), то
        result += " const";
    }
    result += " {\n"; // Открываем фигурную скобку для начала тела метода
    for(const auto& b : m_body) { // Перебор всех элементов вектора m_body для рекурсивного вызова метода compile
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n"; // добавление отступа и закрывающей фигурной скобки для завершения тела метода.
    return result;
}
