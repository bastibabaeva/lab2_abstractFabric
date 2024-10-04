#include <QCoreApplication>
#include <printOperatorUnit.h>
#include <memory>
#include <iostream>
#include "classUnit.h"
#include "methodUnit.h"
#include "printOperatorUnit.h"
#include "cplusFactory.h"
#include "csharpFactory.h"
#include "javaFactory.h"
using namespace std;


string generateProgram(const shared_ptr <AbstractFactory>& factory) { // Ф-ция принимает ссылку factory на указатель на абстрактную фабрику,
    // создает класс и его методы и выводит этот код (пока на с++)
    auto myClass = factory->createClass("MyClass"); // Создание экземпляра класса "MyClass" с помощью указателя на фабрику

    myClass->add(factory->createMethod("testFunc1", "void", 0), ClassUnit::PUBLIC); // Добавление в экземпляр myClass публичного метода testFunc1
    //типа void (ничего не возвращает), 0 - без модификатора доступа из перечисления Modifier.
    myClass->add(factory->createMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); //Добавление в экземпляр myClass
    // приватного статического метода testFunc2 типа void
    myClass->add(factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // Добавление в экземпляр
    // myClass публичного виртуального константного метода testFunc3 типа void
    shared_ptr<MethodUnit> method = factory->createMethod("testFunc4", "void", MethodUnit::STATIC); // Инициализируем умный указатель method на
    // объект типа MethodUnit статическим методом testFunc4 типа void, созданным с помощью фабрики.
    method->add(factory->createPrintOperator(R"(Hello, world!\n)")); // Добавляем в эту переменную оператор вывода для строки Hello, world!\n
    myClass->add(method, ClassUnit::PROTECTED); // Добавляем в экземпляр myClass переменную method защищенного типа, которая содержит
    // статический метод testFunc4 типа void и оператор вывода для строки Hello, world!\n

    // Методы 5 и 6 только для C#
    if (dynamic_cast<CSharpFactory*>(factory.get())) { // Если factory имеет тип CSharpFactory, то методы 5 и 6 добавляются в класс
        myClass->add(factory->createMethod("testFunc5", "void", MethodUnit::VIRTUAL), ClassUnit::INTERNAL); // Добавление в экземпляр myClass
            // внутреннего виртуального метода testFunc5 типа void
        //INTERNAL: член-данные доступны в любом месте кода для текущей сборки, но недоступны для других сборок
        myClass->add(factory->createMethod("testFunc6", "void", 0), ClassUnit::PROTECTED_INTERNAL); // Добавление в экземпляр myClass
            //защищённого внутреннего метода testFunc5 типа void
        //PROTECTED_INTERNAL: член-данные класса доступны из любого места в текущей сборке и из производных классов в других сборках
    }
    // Методы 5, 6 и 7 только для C#
    if (dynamic_cast<CSharpFactory*>(factory.get())) { // Если factory имеет тип CSharpFactory, то методы 5, 6 и 7 добавляются в класс
        myClass->add(factory->createMethod("testFunc5", "void", MethodUnit::VIRTUAL), ClassUnit::INTERNAL); // Добавление в экземпляр myClass
            // внутреннего виртуального метода testFunc5 типа void
        //INTERNAL: член-данные доступны в любом месте кода для текущей сборки, но недоступны для других сборок
        myClass->add(factory->createMethod("testFunc6", "void", MethodUnit::STATIC), ClassUnit::PROTECTED_INTERNAL); // Добавление в экземпляр myClass
            //защищённого внутреннего статического метода testFunc6 типа void
        //PROTECTED_INTERNAL: член-данные класса доступны из любого места в текущей сборке и из производных классов в других сборках
        myClass->add(factory->createMethod("testFunc7", "void", 0), ClassUnit::PRIVATE_PROTECTED); // Добавление в экземпляр myClass
            //приватного защищённого метода testFunc7 типа void
        // PRIVATE_PROTECTED: Член-данные доступны в своем классе и в производных для текущей сборки
    }

    // Методы 8, 9, 10 только для Java
    if (dynamic_cast<JavaFactory*>(factory.get())) { // Если factory имеет тип JavaFactory, то методы 8, 9, 10 добавляются в класс
        myClass->add(factory->createMethod("testFunc8", "void", MethodUnit::ABSTRACT), ClassUnit::PUBLIC); // Добавление в экземпляр myClass
            // публичного абстрактного метода testFunc8 типа void
        //ABSTRACT: необходим для создания абстрактных методов
        myClass->add(factory->createMethod("testFunc9", "void", MethodUnit::SYNCHRONIZED), ClassUnit::PRIVATE); // Добавление в экземпляр myClass
            //приватного синхронизированного метода testFunc9 типа void
        //SYNCHRONIZED: используется для указания того, что метод может быть доступен только одним потоком одновременно
        myClass->add(factory->createMethod("testFunc10", "void", MethodUnit::FINAL), ClassUnit::PUBLIC); // Добавление в экземпляр myClass
            //публичного финального метода testFunc10 типа void
        //FINAL: используется для завершения реализации методов
    return myClass->compile(); // Возвращаем результат работы метода compile для экземпляра класса myClass, который генерирует код (пока на с++)
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Enter factory number (1 for C++, 2 for C#, 3 for Java): "; //Вводим номер фабрики для генерации кода на соответствующем языке
    int x; cin >> x;
    switch (x)
    {
    case 1: //Если ввели 1, то программа генерирует код на С++ и выводит на консоль
        cout << "C++ code:\n" << generateProgram(make_shared<CPlusPlusFactory>()) << endl; // Выводим результат ф-ции generateProgram(), которая
        // принимает параметр - умный указатель(результат ф-ции make_shared) на С++ фабрику
        break; //выход из оператора выбора
    case 2:
        cout << "C# code:\n" << generateProgram(make_shared<CSharpFactory>()) << endl; // Выводим результат ф-ции generateProgram(), которая
        // принимает параметр - умный указатель(результат ф-ции make_shared) на С# фабрику
        break;
    case 3:
        cout << "Java code:\n" << generateProgram(make_shared<JavaFactory>()) << endl; // Выводим результат ф-ции generateProgram(), которая
        // принимает параметр - умный указатель(результат ф-ции make_shared) на Java фабрику
        break;
    default: //Если введенное значение не соответствует case
        cout << "Invalid factory number." << endl; //То неверный номер фабрики
        break;
    }
    return a.exec();
}
