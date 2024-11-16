/*
Вам поступают числа из стандартного потока ввода. Первым числом вводится количество элементов, далее сами значения.

Нужно вывести все эти числа без дубликатов в порядке убывания.
*/

#include "Task2.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int size{ enterNumber("Введите количество элементов массива") };    // Размер массива (множества)
    std::set<int> mySet;    // Множество (set)

    // Добавление элементов в множество
    for (int i{}; i < size; ++i)
    {
        mySet.insert(enterNumber("Введите число №" + std::to_string(i + 1)));
    }

    // Вывод результата от большего к меньшему
    std::cout << "\nРезультат:\n";
    auto iter{ mySet.end() };
    while (iter != mySet.begin())
    {
        std::cout << *(--iter) << '\n';
    }

    return EXIT_SUCCESS;
}

// Ввод числа с клавиатуры
int enterNumber(std::string message)
{
    int number{};
    while (true)
    {
        std::cout << message << '\n';
        if (std::cin >> number)
        {
            return number;
        }
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Вы ввели некорректное значение!\n";
    }
}