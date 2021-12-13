#include "Array.hpp"
#include <cstdlib>

#define INT_SIZE 10
#define CHAR_SIZE 20

int main() {
	srand(time(0));
{
	Array<int> array;

	std::cout << "--------------------------------------" << std::endl;

	array.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	array = Array<int>(INT_SIZE);
	for (size_t i = 0; i < INT_SIZE; i++) {
		array[i] = rand() % 20;
	}
	array.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	Array<int> copy_array = Array<int>(array);
	Array<int> copy_arrayV2(array);

	array.displayArray();
	std::cout << "..." << std::endl;
	copy_array.displayArray();
	std::cout << "..." << std::endl;
	copy_arrayV2.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	array[0] = 100;
	array[1] = 200;
	array[2] = 300;
	array.displayArray(0);
	array.displayArray(1);
	array.displayArray(2);

	std::cout << "--------------------------------------" << std::endl;

	try {
		array[-2] = 123;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		array[100] = 123;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		array.displayArray(200);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}
{
	Array<char>	array;

	std::cout << "--------------------------------------" << std::endl;


	array.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	array = Array<char>(CHAR_SIZE);
	for (size_t i = 0; i < CHAR_SIZE; i++) {
		array[i] = rand() % ('Z' - 'A') + 'A';
	}
	array.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	Array<char> copy_array = Array<char>(array);
	Array<char> copy_arrayV2(array);

	array.displayArray();
	std::cout << "..." << std::endl;
	copy_array.displayArray();
	std::cout << "..." << std::endl;
	copy_arrayV2.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	array[0] = '#';
	array[1] = 'T';
	array[2] = 'E';
	array[3] = 'S';
	array[4] = 'T';
	array[5] = '#';
	array.displayArray();

	std::cout << "--------------------------------------" << std::endl;

	try {
		array[-2] = 123;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		array[100] = 123;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		array.displayArray(200);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
	return 0;
}

template <typename T>
Array<T>::Array() : _array(0), _size(0) {}

template <typename T>
Array<T>::~Array() { delete[] _array; }

template <typename T>
Array<T>::Array( unsigned int n )
	: _array(new T[n]), _size(n) {
	std::memset(_array, 0, sizeof(T) * n);
}

template <typename T>
Array<T>::Array( const Array<T>& obj )
	: _array(0), _size(0) {
	*this = obj;
}

template <typename T>
T&	Array<T>::operator[]( std::size_t i ) const {
	if ( i >= _size ) {
		std::ostringstream	oss;
		oss << "Array size(" << _size << "), index(" << i << ") out of range!";
		throw std::out_of_range(oss.str());
	}
	return _array[i] ;
}

template <typename T>
Array<T>&	Array<T>::operator=( const Array<T>& rhs ) {
	if (this == &rhs) {
		return *this;
	}
	delete[] _array;
	_size = 0;
	_array = 0;
	if (rhs._size) {
		_array = new T[rhs._size];
	}
	for (size_t i = 0; i < rhs._size; i++) {
		_array[i] = rhs.operator[](i);
	}
	_size = rhs._size;
	return *this;
}

template <typename T>
void	Array<T>::displayArray() {
	if (!_size) {
		std::cout << "empty array" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->size() ; i++) {
		displayArray(i);
	}
}

template <typename T>
void	Array<T>::displayArray( std::size_t i ) {
	T& tmp = operator[](i);
	std::cout << "array[" << i << "] = " << tmp << std::endl;
}

template <typename T>
std::size_t	Array<T>::size() const { return _size; }
