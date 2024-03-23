#pragma once
#include <string>
#include <iostream>
using namespace std;


// Creating queue as a template class
template<typename T>
class queue {
private:
	static const size_t DEFAULT_CAPACITY = 10;
	size_t capacity;
	size_t num_items;
	size_t front_index;
	size_t rear_index;
	T* the_data;
public:
	queue();
	void push(const T& item);
	T& front();
	const T& front() const;
	void pop();
	bool empty() const;
	size_t size() const;
	void reallocate();
	void move_to_rear();
};


// Default constructor
template<typename T>
queue<T>::queue() : capacity(DEFAULT_CAPACITY), num_items(0), front_index(0), rear_index(DEFAULT_CAPACITY - 1), the_data(new T[DEFAULT_CAPACITY]) {
}


// Push function
template<typename T>
void queue<T>::push(const T& item) {
	if (num_items == capacity) {
		reallocate();
	}
	num_items++;
	rear_index = (rear_index + 1) % capacity;
	the_data[rear_index] = item;
}


// Front function
template<typename T>
T& queue<T>::front() {
	return the_data[front_index];
}


// Front function but constant
template<typename T>
const T& queue<T>::front() const{
	return the_data[front_index];
}


// Pop function
template<typename T>
void queue<T>::pop() {
	front_index = (front_index + 1) % capacity;
	num_items--;
}

// Empty function
template<typename T>
bool queue<T>::empty() const {
	return num_items == 0;
}

// Size function
template<typename T>
size_t queue<T>::size() const {
	return num_items;
}


// Reallocate function
template<typename T>
void queue<T>::reallocate() {
	size_t new_capacity = 2 * capacity;
	T* new_data = new T[new_capacity];
	size_t j = front_index;
	for (size_t i = 0; i < num_items; i++) {
		new_data[i] = the_data[j];
		j = (j + 11) % capacity;
	}
	front_index = 0;
	rear_index = num_items - 1;
	capacity = new_capacity;
	std::swap(the_data, new_data);
	delete[] new_data;
}

// Move to rear function
template<typename T>
void queue<T>::move_to_rear() {
	if (num_items <= 1) {
		return;
	}
	T temp = front();
	pop();
	push(temp);
}

