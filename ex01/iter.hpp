#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

template <typename T, typename F>
void	iter( T* array, std::size_t len, F func );

template <typename T>
void	print( const T& x ) { std::cout << x << std::endl; return; }

template <typename T>
void	add_one( T& n ) { n++; }

class Awesome {
	public:
		Awesome( void ): _n(42) { return; }
		int	get( void ) const { return this->_n; }

	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

#endif
