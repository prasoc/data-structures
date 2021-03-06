#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>
#include <stdexcept>

#include "array_list.h"

namespace structures {

/**
@brief Implements a stack(data structure), using arrays.
@details This data structure works just like a real 'stack', you add elements
to the top of the stack (push), and you remove from the top (pop).
It follows the 'LIFO' (last in, first out) principle.

@tparam T Data type of the elements
*/
template<typename T>
class ArrayStack : private ArrayList<T> {

public:

	using ArrayList<T>::clear;
	using ArrayList<T>::size;
	using ArrayList<T>::max_size;
	using ArrayList<T>::empty;
	using ArrayList<T>::full;

	ArrayStack(): ArrayList<T>{} {}

	/**
	@brief Constructor with a given maximum size of the stack

	@param max Maximum size of the stack
	*/
	explicit ArrayStack(std::size_t max): ArrayList<T>{max} {}

	/**
	@brief Adds 'data' to the top of the stack

	@param data The element that'll be added to the stack
	*/
	void push(const T& data) {
		if (this->full()) {
			throw std::out_of_range("Stack is full");
		} else {
			ArrayList<T>::push_back(data);
		}
	}

	/**
	@brief Removes the element at the top of the stack

	@return The element that was removed
	*/
	T pop() {
		if (this->empty()) {
			throw std::out_of_range("Stack is empty");
		} else {
			return ArrayList<T>::pop_back();
		}
	}

	/**
	@brief Returns a reference to the top element of the stack

	@return A reference to the top element of the stack
	*/
	const T& top() const {
		if (empty()) {
			throw std::out_of_range("Stack is empty");
		} else {
			return this->at(this->size() - 1);
		}
	}

};

}  // namespace structures

#endif
