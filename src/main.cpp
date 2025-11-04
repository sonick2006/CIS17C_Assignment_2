#include "DynamicArray.cpp"

int main() {
	DynamicArray<int> arr;
	DynamicArray<int> arr2;


	// push_back test
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	std::cout << "Push back test:" << std::endl;
	for (auto& x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	
	// pop_back test
	arr.pop_back();
	std::cout << "Pop back test:" << std::endl;
	for (auto& x : arr) {
		std::cout << x << " ";
	}
\
	std::cout << std::endl;
	std::cout << std::endl;

	// begin and end tests (should be memory addresses)

	std::cout << "Begining of arr: " << arr.begin() << std::endl;
	std::cout << "End of arr: " << arr.end() << std::endl;


	// get size,capacity,at tests
	std::cout << "Size: " << arr.getSize() << std::endl;
	std::cout << "Capacity: " << arr.getCapacity() << std::endl;
	std::cout << "At index 1: " << arr.at(1) << std::endl;
	std::cout << std::endl;

	// Operator overloading test
	arr2.push_back(7);
	arr2.push_back(6);
	arr2.push_back(9);
	arr2.push_back(2);

	arr = arr2;
	std::cout << "Operator overloading test:" << std::endl;
	// Should be 7 6 9 2
	for (auto& x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}