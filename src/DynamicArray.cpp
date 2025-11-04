#include "DynamicArray.h"

template <typename T>
void DynamicArray<T> ::resize(size_t new_capacity) {
	T* newData = new T[new_capacity];
	size_t elemetsToCopy = (m_size < new_capacity) ? m_size : new_capacity;
	for (size_t i = 0; i < elemetsToCopy; ++i) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	m_capacity = new_capacity;
}

template <typename T>
size_t DynamicArray<T> :: getSize () const{
	return m_size;
}

template <typename T>
size_t DynamicArray<T>::getCapacity() const{
	return m_capacity;
}

template <typename T>
T DynamicArray<T> ::at(size_t index) {
	if (index >= m_size) {
		throw std::out_of_range("INDEX OUT OF RANGE");
	}
	return data[index];
}

template <typename T>
void DynamicArray<T> ::push_back(const T& value) {
	if (m_size == m_capacity) {
		resize(m_capacity * 2);
	}
	data[m_size++] = value;
}

template <typename T>
void DynamicArray<T> ::pop_back() {
	if (m_size == 0) {
		throw std::out_of_range("THIS ARRAY IS EMPTY NOTHING TO ERASE IDIOT");
	}
	--m_size;
}

template <typename T>
T* DynamicArray<T> ::begin() {
	if (m_size == 0) {
		throw std::out_of_range("Array empty");
	}
	return data;
}

template <typename T>
T* DynamicArray<T> ::end() {
	if (m_size == 0) {
		throw std::out_of_range("Array empty");
	}
	return data + m_size;
}

