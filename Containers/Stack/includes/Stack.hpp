#ifndef STACK_HPP
#define STACK_HPP

# include "../../List/includes/List.hpp"

/*
** LIFO data structure
**
** The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
** The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.
*/

/*
** Summary:
** --- 1. Member stuff
** --- 2. Non member stuff
*/

namespace ft
{
	/*
	** --- 1. Member stuff
	*/

	template <
		class T,
		class Container = ft::List<T>
	> class Stack
	{
		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		public:

			typedef Container 	container_type;
			typedef size_t 		size_type;
			typedef T 			value_type;
			typedef T& 			reference;
			typedef T const & 	const_reference;

		protected:
			// na

		private:

			container_type m_list; // the underlying container (need to be SequenceContainer)
				
		// ----------------------------------------------------------------

		public:

			/*
			** --- Constructors & Destructors
			*/

			explicit Stack(void) { };
			Stack(const container_type& container): m_list(container) { };
			void operator=(const Stack& src) { m_list = src.m_list; };
			virtual ~Stack() { };

			// ----------------------------------------------------------------

			/*
			** --- getter
			*/

			Container &get_m_list(void) { return (m_list); }

			// ----------------------------------------------------------------

			/*
			** --- Capacity
			*/

			bool empty() { return (m_list.empty()); }

			size_type size() { return (m_list.size()); }

			// ----------------------------------------------------------------

			/*
			** --- Element access
			*/

			T& top() { return (m_list.back()); }
			const T& top() const { return (m_list.back()); }
			
			// ----------------------------------------------------------------

			/*
			** --- Modifiers
			*/

			void push(T value) { m_list.push_back(value); }

			void pop() { m_list.pop_back(); }
			
	};


	/*
	** --- 2. Non member stuff
	*/

	template< class T, class Container>
	bool operator==( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() == rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator!=( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() != rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator<( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() < rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator<=( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() <= rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator>( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() > rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator>=( Stack<T,Container>& lhs, Stack<T,Container>& rhs )
	{
		return (lhs.get_m_list() >= rhs.get_m_list());
	}

}

#endif
