#include "whatever.hpp"
#include <iostream>

int main() {


	std::cout << "-------------------------------------------------" << std::endl;

	int a = 10;
	int b = 20;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap<int>(a, b);
	std::cout << "swap<int>(a, b);" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "max: " << max<int>(a, b) << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;

	a = b;
	std::cout << "a = b;" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "&a: " << &a << std::endl;
	std::cout << "&b: " << &b << std::endl;
	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "max: " << max<int>(a, b) << std::endl;
	std::cout << "&min: " << &min<int>(a, b) << std::endl;
	std::cout << "&max: " << &max<int>(a, b) << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	Awesome x = 50;
	Awesome y = 100;

	std::cout << "x: " << x.get_n() << std::endl;
	std::cout << "y: " << y.get_n() << std::endl;
	swap<Awesome>(x, y);
	std::cout << "swap<int>(x, y);" << std::endl;
	std::cout << "x: " << x.get_n() << std::endl;
	std::cout << "y: " << y.get_n() << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "min: " << min<Awesome>(x, y).get_n() << std::endl;
	std::cout << "max: " << max<Awesome>(x, y).get_n() << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;

	x = y;
	std::cout << "x = y;" << std::endl;
	std::cout << "x: " << x.get_n() << std::endl;
	std::cout << "y: " << y.get_n() << std::endl;
	std::cout << "&x: " << &x << std::endl;
	std::cout << "&y: " << &y << std::endl;
	std::cout << "min: " << min<Awesome>(x, y).get_n() << std::endl;
	std::cout << "max: " << max<Awesome>(x, y).get_n() << std::endl;
	std::cout << "&min: " << &min<Awesome>(x, y) << std::endl;
	std::cout << "&max: " << &max<Awesome>(x, y) << std::endl;

	std::cout << "-------------------------------------------------" << std::endl;

	return 0;
}

template< typename T >
void		swap( T& t1, T& t2 ) {
	T tmp = t1;

	t1 = t2;
	t2 = tmp;
}

template< typename T >
const T&	min( const T& t1, const T& t2 ) {
	return ( t1 < t2 ? t1 : t2 );
}

template< typename T >
const T&	max( const T& t1, const T& t2 ) {
	return ( t1 > t2 ? t1 : t2 );
}
