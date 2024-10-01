#include <QCoreApplication>
#include <classUnit.h>
#include <methodUnit.h>
#include <printOperatorUnit.h>
#include <memory>
#include <iostream>
using namespace std;

string generateProgram() { // Функция создает класс и его методы и выводит этот код на С++
    ClassUnit myClass("MyClass"); // Создание экземпляра класса MyClass
    myClass.add(make_shared <MethodUnit> ("testFunc1", "void", 0), ClassUnit::PUBLIC); // Добавление в экземпляр myClass публичного метода testFunc1
    //типа void (ничего не возвращает), 0 - без модификатора доступа из перечисления Modifier.
    // Тут make_shared - ф-ция создает объект типа MethodUnit и возвращает умный указатель shared_ptr, который управляет временем жизни этого объекта.

    myClass.add(make_shared <MethodUnit> ("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); //Добавление в экземпляр myClass
    // приватного статического метода testFunc2

    myClass.add(make_shared <MethodUnit> ("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // Добавление в экземпляр
    // myClass публичного виртуального константного метода testFunc3 типа void

    auto method = make_shared <MethodUnit> ("testFunc4", "void", MethodUnit::STATIC); // Создаем объект типа MethodUnit с помощью функции make_shared
    // для создания статического метода testFunc4 типа void и инициализируем переменную method типа auto этим объектом.
    // Тут тип будет shared_ptr<MethodUnit>, так как make_shared возвращает умный указатель на объект MethodUnit.

    method->add(make_shared <PrintOperatorUnit> (R"(Hello, world!\n)")); // Добавляем в эту переменную оператор вывода для строки Hello, world!\n
    myClass.add(method, ClassUnit::PROTECTED); // добавляем в экземпляр myClass переменную method защищенного типа, которая содержит
    // статический метод testFunc4 типа void и оператор вывода для строки Hello, world!\n
    return myClass.compile(); // Возвращаем результат работы метода compile для экземпляра класса myClass, который генерирует код на с++
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << generateProgram() << endl; // Выводим на консоль результат работы ф-ции generateProgram() на С++
    return a.exec();
}
