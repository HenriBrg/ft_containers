#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace ft
{
    // cf. List::Operations
	
	template <typename T>
	bool is_less_than(T const &lhs, T const &rhs)
	{
		return (lhs < rhs);
	}

	template <typename T>
	bool equals(T const &lhs, T const &rhs)
	{
		return (lhs == rhs);
	}

	template <typename T>
	bool is_more_than(T const &lhs, T const &rhs)
	{
		return (lhs > rhs);
	}
    
}


#endif
