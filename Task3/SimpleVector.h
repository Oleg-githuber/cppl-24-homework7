#pragma once

#include <exception>

template<class MyType>
class SimpleVector
{
private:
	unsigned int capacity_{};	// Потенциальная ёмкость вектора
	unsigned int size_{};		// Размер "массива"
	MyType* arr_{ nullptr };	// Указатель на массив

	// Изменение ёмкости
	void changeCapacity()
	{
		MyType* newArr{ new MyType[capacity_] };
		copyArray(arr_, newArr);
		delete[] arr_;
		arr_ = newArr;
	}

	// Копирование массива
	void copyArray(MyType* oldArr, MyType* newArr)
	{
		for (int i{}; i < size_; ++i)
		{
			newArr[i] = oldArr[i];
		}
	}

public:

	/// <summary>
	/// Конструктор
	/// </summary>
	SimpleVector() : capacity_{ 1 }, arr_{new MyType[capacity_]}
	{}

	// Геттеры

	unsigned int size() const
	{
		return size_;
	}

	unsigned int capacity() const
	{
		return capacity_;
	}

	MyType at(int index) const
	{
		if (index < 0 || index >= size)
		{
			throw std::exception("Недопустимый индекс!");
		}
		return arr_[index];
	}

	/// <summary>
	/// Добавление элемента в конец вектора
	/// </summary>
	/// <param name="value">значение</param>
	void push_back(MyType value)
	{
		if (size_ == capacity_)
		{
			capacity_ *= 2;
			changeCapacity();
		}
		arr_[size_++] = value;
	}

	/// <summary>
	/// Удаление последнего элемента вектора
	/// </summary>
	void delete_back()
	{
		--size_;
		if (size_ == (capacity_ / 3))
		{
			capacity_ /= 3;
			changeCapacity();
		}
	}

	/// <summary>
	/// Деструктор
	/// </summary>
	~SimpleVector()
	{
		delete[] arr_;
	}
};

