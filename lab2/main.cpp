#include <QCoreApplication>
#include <printOperatorUnit.h>
#include <memory>
#include <iostream>
#include "classUnit.h"
#include "methodUnit.h"
#include "printOperatorUnit.h"
#include "cplusFactory.h"
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
    return myClass->compile(); // Возвращаем результат работы метода compile для экземпляра класса myClass, который генерирует код (пока на с++)
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //сделать case для каждого языка
    cout << generateProgram(make_shared<CPlusPlusFactory>()) << endl; // Выводим на консоль сгенерированный код из ф-ции generateProgram(), которая
    // принимает параметр - умный указатель(результат ф-ции make_shared) на С++фабрику
    return a.exec();
}
