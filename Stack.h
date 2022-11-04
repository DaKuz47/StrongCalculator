#pragma once
#include <array>
#include <cassert>
#include <iostream>


template<typename T, int size>
class Stack {
private:
	T* stack;
	int m_size{0};
	int m_full_size{ size };

public:
	Stack() {
		stack = new T[size];
	}
	~Stack() { delete[] stack; }

	T top() {
		assert(m_size != 0 && "Stack is empty");
		return stack[m_size - 1];
	}
	T pop() {
		assert(m_size != 0 && "Underflow");
		return stack[--m_size];
	}
	void push(T el) {
		assert(m_size != m_full_size && "Overflow");
		stack[m_size++] = el;
	}
	bool empty() {
		return !m_size;
	}
	void print() {
		for (int i{ 0 }; i < m_size - 1; i++) {
			std::cout << stack[i] << ", ";
		}
		std::cout << stack[m_size - 1] << "\n";
	}

	int getSize() const {
		return m_size;
	}
};

