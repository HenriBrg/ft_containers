/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:53:19 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/13 22:11:13 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

# include "../../List/includes/List.hpp"

/*
** FIFO data structure
**
** The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
** The queue pushes the elements on the back of the underlying container and pops them from the front.
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
		class Container = List<T>
	> class Queue
	{
		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		public:
			// ----------------------------------------------------------------

			typedef Container 	container_type;
			typedef size_t 		size_type;
			typedef T 			value_type;
			typedef T& 			reference;
			typedef T const & 	const_reference;
		
		protected:
			// na

		private:
		
			container_type m_list; // the underlying container (need to be SequenceContainer)

		public:
		
			// ----------------------------------------------------------------

			/*
			** --- Constructors & Destructors
			*/

			Queue() { };
			explicit Queue(const container_type& container): m_list(container) { };
			void operator=(const Queue& src) { m_list = src.m_list; };
			virtual ~Queue() { };

			// ----------------------------------------------------------------

			/*
			** --- getter
			*/

			container_type &get_m_list(void) { return (m_list); }

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

			T& front() { return (m_list.front()); }
			const T& front() const { return (m_list.front()); }

			T& back() { return (m_list.back()); }
			const T& back() const { return (m_list.back()); }
			
			// ----------------------------------------------------------------

			/*
			** --- Modifiers
			*/
		
			void push(T value) { m_list.push_back(value); }
			
			void pop() { m_list.pop_front(); }

	};

	/*
	** --- 2. Non member stuff
	*/

	template< class T, class Container>
	bool operator==( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() == rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator!=( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() != rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator<( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() < rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator<=( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() <= rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator>( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() > rhs.get_m_list());
	}

	template< class T, class Container>
	bool operator>=( Queue<T,Container>& lhs, Queue<T,Container>& rhs )
	{
		return (lhs.get_m_list() >= rhs.get_m_list());
	}

}

#endif
