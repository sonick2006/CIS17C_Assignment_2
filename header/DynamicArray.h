#pragma once
#include <iostream>
#include <stdexcept>

//assignment operator : overload '=' operator, copy code from copy constructor
template <typename T>
class DynamicArray {
private:
	T* data;
	size_t m_size;
	size_t m_capacity;

public:
	//Construction
	DynamicArray(size_t initial_capacity = 2) : data(new T[initial_capacity]), m_size(0), m_capacity(initial_capacity){}
	~DynamicArray() { delete[] data; }
	DynamicArray(const DynamicArray& other)
		: data(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity) {
		for (size_t i = 0; i < m_size; ++i) {
			data[i] = other.data[i];
		}
	}


	// operator overload 
	DynamicArray& operator=(DynamicArray& other) {
		if (this == &other) { return *this; }

		T* newData = new T[other.m_capacity];
		for (size_t i = 0; i < other.m_size; ++i) {
			newData[i] = other.data[i];
		}

		delete[] data;
		data = newData;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		return *this;
			
	}




	//Member funcs
	void resize(size_t new_capacity);
	size_t getSize() const;
	size_t getCapacity() const;
	T at(size_t index);
	void push_back(const T& val);
	void pop_back();


	//iterators
	T* begin();
	T* end();

	

};