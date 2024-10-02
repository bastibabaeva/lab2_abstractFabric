#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "classUnit.h"
#include "methodUnit.h"
#include "printOperatorUnit.h"
using namespace std;

class AbstractFactory //Класс Абстрактная фабрика для создания конкретных фабрик, содержит 3 чисто виртуальных метода, которые будут переопределены в наследниках
{
public:
    virtual shared_ptr<ClassUnit> createClass(const string& name) = 0; // чисто виртуальный метод для создания класса с заданным именем
    virtual shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, Unit::Flags flags) = 0; // чисто виртуальный метод
    // для создания метода с заданным именем, типом возвращаемого значения и флагом (индексом модификатора доступа)
    virtual shared_ptr<PrintOperatorUnit> createPrintOperator(const string& text) = 0; // чисто виртуальный метод для оператора вывода с заданным текстом
    virtual ~AbstractFactory() {} //виртуальный деструктор
};
#endif // ABSTRACTFACTORY_H
