#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include <string>
#include <vector>
#include "unit.h"
#include <memory>
using namespace std;

class ClassUnit : public Unit // Класс ClassUnit, наследуемый от Unit, для создания класса и определения типов доступа на С++
{
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
    explicit ClassUnit(const string& name); // Конструктор класса явного преобразования типа (explicit), принимающий константную ссылку на имя класса.
    void add(const shared_ptr <Unit>& unit, Flags flags); // Метод добавления вложенных элементов unit в вектор(flags - индекс модификатора)
    string compile(unsigned int level = 0) const; // Метод, генерирующий код на C++ и возвращающий строку. В качестве аргумента метод принимает
    // параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
private:
    string m_name; // имя класса
    using Fields = vector <shared_ptr <Unit>>; //Создание псевдонима(с помощью ключевого слова using) Fields типа vector,
    // который содержит умные указатели shared_ptr на объекты типа Unit.
    vector <Fields> m_fields; // вектор m_fields, в котором каждый элемент является вектором, содержащим умные указатели на объекты типа Unit.
};
const vector <string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "private protected","internal","protected internal"};
// Инициализация статического константного вектора из строк модификаторами доступа

#endif // CLASSUNIT_H
