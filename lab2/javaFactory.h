#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H
#include "abstractFactory.h"

class JavaFactory : public AbstractFactory //Конкретная фабрика JavaFactory, наследуемая от абстрактной, для создания продуктов на Java
{
public:
    shared_ptr<ClassUnit> createClass(const string& name) { // переопределение метода для создания конкретного класса на Java с заданным именем
        //   return shared_ptr<ClassUnit> (new JavaClass(name));
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, Unit::Flags flags) { // переопределение метода для создания
        // конкретного метода на Java с заданным именем, возвращаемым типом и флагом(static, const или virtual)
        //   return shared_ptr<MethodUnit> (new JavaMethod(name, returnType, flags));
    }
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& text) { // переопределение метода для создания конкретного оператора вывода на Java
        // с заданным текстом
        //   return shared_ptr<PrintOperatorUnit> (new JavaPrintOperator(text));
    }
};

#endif // JAVAFACTORY_H
