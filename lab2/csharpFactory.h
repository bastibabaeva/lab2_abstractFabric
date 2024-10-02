#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H
#include "abstractFactory.h"
#include "csharpClass.h"
#include "csharpMethod.h"
#include "csharpPrintOperator.h"

class CSharpFactory : public AbstractFactory //Конкретная фабрика CSharpFactory, наследуемая от абстрактной, для создания продуктов на C#
{
public:
    shared_ptr<ClassUnit> createClass(const string& name) { // переопределение метода для создания конкретного класса на C# с заданным именем
           return shared_ptr<ClassUnit> (new CSharpClass(name));  //создаем объект CSharpClass с конкретным именем в динамической памяти(new)
        // и возвращаем умный указатель на этот объект
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, Unit::Flags flags) { // переопределение метода для создания
        // конкретного метода на C# с заданным именем, возвращаемым типом и флагом(static, const или virtual)
          return shared_ptr<MethodUnit> (new CSharpMethod(name, returnType, flags));
    }
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& text) { // переопределение метода для создания конкретного оператора вывода на C#
        // с заданным текстом
           return shared_ptr<PrintOperatorUnit> (new CSharpPrintOperator(text));
    }
};

#endif // CSHARPFACTORY_H
