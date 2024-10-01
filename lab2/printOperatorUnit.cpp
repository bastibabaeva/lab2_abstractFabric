#include "printOperatorUnit.h"

string PrintOperatorUnit::compile(unsigned int level) const { // метод для генерации текста на с++, который хранится в объекте PrintOperatorUnit
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n"; // генерация отступа с заданным уровнем вложенности и текста m_text
}
