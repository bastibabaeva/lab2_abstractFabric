#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include <string>
#include <vector>
#include "unit.h"
#include <memory>
using namespace std;
class ClassUnit : public Unit // Класс ClassUnit, наследуемый от Unit, для создания класса и определения типов доступа
{
    friend class CPlusPlusClass; //класс CPlusPlusClass объявляем другом класса ClassUnit для того, чтобы мы могли обращаться к приватным член-данным
    friend class CSharpClass; //класс CSharpClass объявляем другом класса ClassUnit для того, чтобы мы могли обращаться к приватным член-данным
    friend class JavaClass; //класс JavaClass объявляем другом класса ClassUnit для того, чтобы мы могли обращаться к приватным член-данным
public:
    enum AccessModifier { // Определение перечисления(enum) AccessModifier для модификаторов (уровней) доступа: PUBLIC, PROTECTED, PRIVATE
        PUBLIC, //значение = 0, а последующие значения увеличиваются на 1.
        PROTECTED, // = 1
        PRIVATE, // = 2
        // Типы доступа: PRIVATE_PROTECTED, INTERNAL, PROTECTED_INTERNAL используются в С#
        PRIVATE_PROTECTED, // = 3. Член-данные доступны в своем классе и в производных для текущей сборки
        INTERNAL, // = 4. Член-данные доступны в любом месте кода для текущей сборки, но недоступны для других сборок
        PROTECTED_INTERNAL // = 5. Член-данные класса доступны из любого места в текущей сборке и из производных классов в других сборках
    };
    static const vector <string> ACCESS_MODIFIERS; // Объявление статического константного вектора из строк, содержащего модификаторы доступа типа string

public:
    explicit ClassUnit(const string& name) : m_name(name) { // Конструктор класса явного преобразования типа (explicit), принимающий константную
        // ссылку на имя класса и инициализирует поле m_name этим параметром
        m_fields.resize(ACCESS_MODIFIERS.size()); //изменяет размер вектора m_fields на кол-во модификаторов доступа, определенных в ACCESS_MODIFIERS
    }
    void add(const shared_ptr <Unit>& unit, Flags flags) { // Метод добавления вложенных элементов unit в вектор
        // который принимает константную ссылку на умный указатель shared_ptr, который указывает на объект типа Unit. (flags - индекс модификатора)
        int accessModifier = PRIVATE; // Инициализируем переменную accessModifier значением PRIVATE по умолчанию
        if (flags < ACCESS_MODIFIERS.size()) { //Если переданный флаг является допустимым индексом модификатора доступа в векторе ACCESS_MODIFIERS (0,1,2), то
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit); //добавляем элемент unit в вектор m_fields для соответствующего модификатора доступа
    }

private:
    string m_name; // имя класса
    using Fields = vector <shared_ptr <Unit>>; //Создание псевдонима(с помощью ключевого слова using) Fields типа vector,
    // который содержит умные указатели shared_ptr на объекты типа Unit.
    vector <Fields> m_fields; // вектор m_fields, в котором каждый элемент является вектором, содержащим умные указатели на объекты типа Unit.
};

const vector <string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "private protected","internal","protected internal"};
// Инициализация статического константного вектора из строк модификаторами доступа

#endif // CLASSUNIT_H
