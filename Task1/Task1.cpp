// Нужно посчитать, сколько раз каждый символ встречается в заданном тексте, и отсортировать по убыванию частоты.

#include "Task1.h"

int main(int argc, char* argv[])
{
    char str[]{ "Hello world!" };   // Начальные условия / заданная строка

    size_t strLength{ std::strlen(str) };   // Длина строки
    std::map<char, int> myMap;  // map<ключ, значение>
    
    addElementsToMap(myMap, str, strLength);    // Добавление элементов в map
    std::vector<std::pair<char, int>> myVector(myMap.begin(), myMap.end());     // Преобразование map в vector для сортировки
    std::sort(myVector.begin(), myVector.end(), [](std::pair<char, int>& left, std::pair<char, int>& right) {return left.second > right.second; }); // Сортировка

    // Вывод информации в консоль
    for (const std::pair<char, int>& elem : myVector)
    {
        std::cout << elem.first << " : " << elem.second << '\n';
    }

    return EXIT_SUCCESS;
}

// Функция добавления элементов в map
void addElementsToMap(std::map<char, int>& myMap, const char* str, const size_t& strLength)
{
    for (int i{}; i < strLength; ++i)
    {
        if (myMap.empty())
        {
            myMap.insert(std::pair<char, int>(str[i], 1));
        }
        else
        {
            for (const std::pair<char, int>& elem : myMap)
            {
                if (elem.first == str[i])
                {
                    ++myMap[str[i]];
                    break;
                }
            }
            myMap.insert(std::pair<char, int>(str[i], 1));
        }
    }
}