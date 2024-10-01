#include "classUnit.h"

const vector <string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"}; // Инициализация статического константного вектора из строк
// модификаторами доступа: "public", "protected", "private"

ClassUnit::ClassUnit(const string& name) : m_name(name) { // Определение конструктора, который принимает константную строковую ссылку на имя класса
    // и инициализирует поле m_name этим параметром
    m_fields.resize(ACCESS_MODIFIERS.size()); //изменяет размер вектора m_fields на кол-во модификаторов доступа, определенных в ACCESS_MODIFIERS
}

void ClassUnit::add(const shared_ptr <Unit>& unit, Flags flags) { // Метод добавления вложенных элементов unit в вектор
    // который принимает константную ссылку на умный указатель shared_ptr, который указывает на объект типа Unit. (flags - индекс модификатора)

    int accessModifier = PRIVATE; // Инициализируем переменную accessModifier значением PRIVATE по умолчанию
    if (flags < ACCESS_MODIFIERS.size()) { //Если переданный флаг является допустимым индексом модификатора доступа в векторе ACCESS_MODIFIERS (0,1,2), то
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit); //добавляем элемент unit в вектор m_fields для соответствующего модификатора доступа
}

string ClassUnit::compile(unsigned int level) const //Переопределение метода, который генерирует код на C++ и возвращает строку. В качестве аргумента
    // метод принимает параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
{
    string result = generateShift(level) + "class " + m_name + " {\n"; // Создание строки, содержащей объявление класса с его именем и открывающей
    // фигурной скобкой для начала объявления класса. Уровень вложенности определяется с помощью вызова generateShift(level) для кол-ва отступов.
    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) { // Цикл для прохода по всем модификаторам доступа
        if(m_fields[i].empty()) { // Если вектор элементов для текущего модификатора пуст, то
            continue; // переходим к следующему модификатору - на начало цикла for
        }
        result += ACCESS_MODIFIERS[i] + ":\n"; // добавляем строку с индексом на текущий модификатор доступа в результат.
        for(const auto& f : m_fields[i]) { // Цикл по всем элементам вектора для данного модификатора
            result += f->compile(level + 1); //рекурсивный вызов для каждого элемента f метода compile с уровнем вложенности +1 и добавление в результат
        }
        result += "\n"; //добавление пустой строки после элементов текущего модификатора
    }
    result += generateShift(level) + "};\n"; // добавляем закрывающую фигурную скобку для завершения объявления класса
    return result;
}
