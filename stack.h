#pragma once
#include <exception>
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack() : _top(nullptr), _size(0) {}
	struct Node
	{
		Node(T el) : data(el), previous(nullptr) {}
		Node(T el, Node* pr) : data(el), previous(pr) {}
		Node* previous;
		T data;


	};

	void push(const T);
	void pop();
	T& top();
	T& prev();
	int size();
private:
	Node* _top;
	int _size;
};

template <typename T>
void Stack<T>::push(const T el) {
	try {
		if (_top != nullptr) {
			Node* temp = new Node(el, _top);
			_top = temp;
		}
		else
		{
			_top = new Node(el);
		}
		_size++;
	}
	catch (bad_alloc) {
		cerr << "Error: Bad_alloc\n";
	}
}

template <typename T>
void Stack<T>::pop() {
	try {
		if (_top == nullptr)
			throw out_of_range("Error: Out of range\n");
		Node* temp = _top;
		_top = _top->previous;
		delete temp;
		_size--;
	}
	catch (exception& e) {
		cerr << e.what();
	}

}

template <typename T>
T& Stack<T>::top() {
	try {
		if (_top == nullptr)
			throw out_of_range("Erorr: Stack is empty\n");
		return _top->data;
	}
	catch (exception& e) {
		cerr << e.what();
	}
}

template <typename T>
T& Stack<T>::prev() {
	try {
		if (_top == nullptr)
			throw("Erorr: Stack is empty\n");
		return _top->previous->data;
	}
	catch (exception& e) {
		cerr << e.what();
	}
}
template <typename T>
int Stack<T>::size() {
	return _size;
}
