/*
Для лучшего понимания работы std::vector в этом задании вам нужно написать собственную шаблонную упрощённую реализацию std::vector.

У вашего контейнера должны работать функции:

at(int index) — доступ к элементу контейнера по индексу;
push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
size () — количество элементов в контейнере;
capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.
*/
#include <iostream>
#include <clocale>
#include "SimpleVector.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    SimpleVector<int> simpleVector;

    std::cout << "\nПустой вектор\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    simpleVector.push_back(12);

    std::cout << "\nДобавлен один элемент\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    simpleVector.push_back(13);

    std::cout << "\nДобавлен ещё один элемент\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    simpleVector.push_back(14);

    std::cout << "\nДобавлен ещё один элемент\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    simpleVector.push_back(15);
    simpleVector.push_back(17);

    std::cout << "\nДобавлено два элемента\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    simpleVector.delete_back();
    simpleVector.delete_back();
    simpleVector.delete_back();

    std::cout << "\nУдалено три элемента\n";
    std::cout << "Size: " << simpleVector.size() << '\n';
    std::cout << "Capacity: " << simpleVector.capacity() << '\n';

    return EXIT_SUCCESS;
}

