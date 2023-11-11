#pragma once
#include <iostream>
using namespace std;
template<typename T>//шаблонные методы должны описываться в .h
class List
{
public:
	List();
	~List();
	void push_back(T data);
	void push_front(T data);
	int GetSize();
	T& operator[] (const int index);//элемент по индексу
	void pop_front();//удалить первый элемент списка
	void clear();//очистка списка
	void insert(T value, int index);
	void removeAt(int index);//удаление элемента по ук. индексу
	void popback();
private:
	template<typename T>
	class Node //узел
	{
	public:

		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)//pNext=nullptr для последнего элемента в списке; data=T()-вызовется конструктор по умолчанию если класс, или значение по умолчанию того типа данных , который передаём
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};
template<typename T>
inline List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;//указатель на первый элмент 
		while (current->pNext != nullptr)//ищем последний элемент 
		{
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
inline int List<T>::GetSize()
{
	return Size;
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter=0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
	// TODO: вставьте здесь оператор return
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
inline void List<T>::insert(T value, int index)
{
	if (index == 0 || index>Size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
	
}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
	}
	Size--;

}

template<typename T>
inline void List<T>::popback()
{
	removeAt(Size - 1);
}

