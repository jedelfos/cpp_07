#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <cstring>

template <typename T>
class Array {

	private:
		T*			_array;
		std::size_t	_size;

	public:
		Array<T>();
		~Array<T>();
		Array<T>( unsigned int n );
		Array<T>( const Array<T>& obj );


		T&			operator[]( std::size_t i ) const;
		Array<T>&	operator=( const Array<T>& rhs );

		std::size_t	size() const;

		void		displayArray();
		void		displayArray( std::size_t i );

};


#endif
