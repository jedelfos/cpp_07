#ifndef WHATEVER_HPP
# define WHATEVER_HPP

class Awesome {

	private:
		int _n;

	public:
		Awesome( int n ) : _n(n) {}

		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator> ( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator< ( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

		int get_n() const { return _n; }
};

template< typename T >
void		swap( T& t1, T& t2 );

template< typename T >
const T&	min( const T& t1, const T& t2 );

template< typename T >
const T&	max( const T& t1, const T& t2 );

#endif
