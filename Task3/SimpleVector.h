#pragma once

#include <exception>

template<class MyType>
class SimpleVector
{
private:
	unsigned int capacity_{};	// ������������� ������� �������
	unsigned int size_{};		// ������ "�������"
	MyType* arr_{ nullptr };	// ��������� �� ������

	// ��������� �������
	void changeCapacity()
	{
		MyType* newArr{ new MyType[capacity_] };
		copyArray(arr_, newArr);
		delete[] arr_;
		arr_ = newArr;
	}

	// ����������� �������
	void copyArray(MyType* oldArr, MyType* newArr)
	{
		for (int i{}; i < size_; ++i)
		{
			newArr[i] = oldArr[i];
		}
	}

public:

	/// <summary>
	/// �����������
	/// </summary>
	SimpleVector() : capacity_{ 1 }, arr_{new MyType[capacity_]}
	{}

	// �������

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
			throw std::exception("������������ ������!");
		}
		return arr_[index];
	}

	/// <summary>
	/// ���������� �������� � ����� �������
	/// </summary>
	/// <param name="value">��������</param>
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
	/// �������� ���������� �������� �������
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
	/// ����������
	/// </summary>
	~SimpleVector()
	{
		delete[] arr_;
	}
};

