#pragma once
#include<iostream>
using namespace std;

template<typename T>
void removeItem(T*& arr, int& size, int index) {
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
	T* temp = new T[size];
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template<typename T>
void addItemBack(T*& arr, int& size, T value) {
	//1. ��������� ����� ����� �� 1 ��-� �����
	T* tmp = new T[size + 1];

	//2. ���������� ��� � ������� ������ �� ������
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}

	//3. ������� �������� � ������� �������
	tmp[size] = value;

	//4. ��������� ���'��� ������� �������
	if (arr != nullptr) delete[] arr;

	//5.��������'����� �������� �� ���� ���'���
	arr = tmp;

	//6. ��������� ��������� ������
	size++;
}

template<typename T>
void showSortedPages(T* arr, int size)
{
	T* sortedArr = new T[size];
	for (int i = 0; i < size; i++)
	{
		sortedArr[i] = arr[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sortedArr[i].pages<sortedArr[j].pages)
			{
				T temp = sortedArr[i];
				sortedArr[i] = sortedArr[j];
				sortedArr[j] = temp;
			}
		}
	}
	cout << "\n\n";
	for (int i = 0; i < size; i++) 
	{
		sortedArr[i].showBook();
	}
	cout << "\n\n";
	delete[] sortedArr;
}

template<typename T>
void showSortedDateWriten(T* arr, int size)
{
	T* sortedArr = new T[size];
	for (int i = 0; i < size; i++)
	{
		sortedArr[i] = arr[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sortedArr[i].existed.year<=sortedArr[j].existed.year)
			{
				T temp = sortedArr[i];
				sortedArr[i] = sortedArr[j];
				sortedArr[j] = temp;
			}
		}
	}
	cout << "\n\n";
	for (int i = 0; i < size; i++) 
	{
		sortedArr[i].showBook();
	}
	cout << "\n\n";
	delete[] sortedArr;
}

template<typename T>
void showSortedDateAdded(T* arr, int size)
{
	T* sortedArr = new T[size];
	for (int i = 0; i < size; i++)
	{
		sortedArr[i] = arr[i];
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sortedArr[i].added.year<=sortedArr[j].added.year)
			{
				T temp = sortedArr[i];
				sortedArr[i] = sortedArr[j];
				sortedArr[j] = temp;
			}
		}
	}
	cout << "\n\n";
	for (int i = 0; i < size; i++) 
	{
		sortedArr[i].showBook();
	}
	cout << "\n\n";
	delete[] sortedArr;
}
