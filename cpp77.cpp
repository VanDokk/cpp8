#include "pch.h"
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>


template<typename T>
class List
{
public:

	List();
	~List();

	void push_back(T data);
	void push_top(T data);
	void removeAt(int index);
	T& operator[](const int index);
	int length() { return size; }	

private:

	template<typename T>
	class  Node
	{
	public:

		Node *pNext;
		Node *pPrev;
		T data;		


		Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int size;
	Node<T> *head;
	Node<T> *tail;

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
	}
	else
	{
		tail->pNext = new Node<T>(data);
		Node<T> *ptr = tail;
		tail = tail->pNext;
		tail->pPrev = ptr;
		tail->pNext = head;		
	}
	size++;
	head->pPrev = tail;
}

template<typename T>
void List<T>::push_top(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);		
		tail = head;
	}
	else
	{
		head->pPrev = new Node<T>(data);
		Node<T> *ptr = head;
		head = head->pPrev;
		head->pNext = ptr;
		head->pPrev = tail;
		tail->pNext = head;
	}
	size++;
}

template<typename T>
void List<T>::removeAt(int index)
{		
	Node<T> *previous = this->head;	
	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->pNext;
	}

	Node<T> *toDelete = previous->pNext;
	Node<T> *Next = toDelete->pNext;
	previous->pNext = Next;
	Next->pPrev = previous;

	delete toDelete;

	size--;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}


 int main()
 {
	 srand(time(0));

	 List<double> lst;

	 for (int i = 1; i < 15; i++)
	 {
		 lst.push_back(rand() % 10);
	 }

	 for (int i = 0; i < lst.length(); i++)
	 {
		 std::cout << lst[i] << std::endl;
	 }

	 for (int i = 0; i < lst.length() ;i++)
	 {
		 if (lst[i] == 3)
		 {
			 lst.removeAt(i - 1);
		 }
	 }

	 std::cout << std::endl;
	 for (int i = 0; i < lst.length(); i++)
	 {
		 std::cout << lst[i] << std::endl;
	 }

	 std::cout << std::endl << lst.length();
 }


