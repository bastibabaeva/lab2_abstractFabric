#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <string>
#include <vector>
#include <unit.h>
#include <memory>
using namespace std;

class MethodUnit : public Unit  // Класс MethodUnit, наследуемый от Unit, для создания методов и определения их типов доступа в классе на С++
{

    friend class CPlusPlusMethod; //класс CPlusPlusMethod объявляем другом класса MethodUnit для того, чтобы мы могли обращаться к приватным член-данным
    friend class CSharpMethod; //класс CSharpMethod объявляем другом класса MethodUnit для того, чтобы мы могли обращаться к приватным член-данным

public:
    enum Modifier { // Определение перечисления(enum) Modifier, определяющее модификаторы доступа: STATIC, CONST и VIRTUAL в виде битовых флагов.
        STATIC = 1,
        CONST = 1 << 1, //сдвиг бита на 1 влево: = 10
        VIRTUAL = 1 << 2, //сдвиг бита на 2 влево: = 100.
    };

public:
    MethodUnit(const string& name, const string& returnType, Flags flags) : m_name(name), m_returnType(returnType), m_flags(flags) { }
    // Конструктор класса MethodUnit принимает имя функции, тип возвращаемого значения и флаги(name, returnType, flags)

    void add(const shared_ptr <Unit>& unit, Flags /* flags */ = 0 ) { // метод для добавления элементов типа Unit в конец вектора m_body
        m_body.push_back(unit);
    }
private:
    string m_name; // имя класса
    string m_returnType; //возвращаемый тип
    Flags m_flags; //индекс модификатора доступа
    vector <shared_ptr <Unit>> m_body; // вектор умных указателей на объекты типа Unit
};

#endif // METHODUNIT_H
