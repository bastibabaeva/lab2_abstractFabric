#include "unit.h"

void Unit::add(const shared_ptr <Unit>&, Flags) { //Виртуальный метод для добавления вложенных элементов, который принимает в качестве параметров:
    // константную ссылку на умный указатель shared_ptr, который указывает на объект типа Unit, и параметр Flags.
    throw runtime_error("Not supported"); // По умолчанию оператор throw генерирует исключение типа runtime_error с сообщением о том,
    // что операция не поддерживается или не может быть выполнена.
}

string Unit::generateShift(unsigned int level) const // Виртуальный метод возвращает строку, состоящую из нужного числа пробелов.
    //Результат зависит от уровня вложенности.
{
    // static - ключевое слово для того, чтобы переменная DEFAULT_SHIFT была общей для всех экземпляров класса, а не привязывалась к каждому объекту.
    static const auto DEFAULT_SHIFT = " "; // Инициализация статической константы для создания отступов при генерации кода,
    // и её тип будет выведен автоматически как const char* с помощью auto, так как она инициализируется строковым литералом " ".
    string result;
    for(unsigned int i = 0; i < level; ++i) { // Цикл для формирования строки result с нужным количеством пробелов.
        result += DEFAULT_SHIFT;
    }
    return result;
}
