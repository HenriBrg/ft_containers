/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:53:19 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/14 20:28:30 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include "../../Utils/Iterator.hpp"
# include "Functions.hpp"
# include <cstddef>
# include <stdio.h>
# include <limits>
# include <stdexcept>

/*
** Summary:
** --- 1. Elem								struct
** --- 2. Bidirectional Iterator			class
** --- 3. Reverse Bidirectional Iterator	class
** --- 4. List                      		class
** --- 5. Non member functions				nm
*/

/*
** Todo:
** ok all
*/

namespace ft
{
	/*
	** --- 1. Elem
	*/

	template <typename T>
	struct Elem
	{
		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		Elem<T>*	m_prev;
		T 			m_content;
		Elem<T>*	m_next;

		// ----------------------------------------------------------------

		/*
		** --- Coplien form
		*/

		// default
		Elem(): m_prev(NULL), m_content(static_cast<T>(NULL)), m_next(NULL) { }
		// overload
		Elem(Elem<T>* p, const T &c, Elem<T>* n): m_prev(p), m_content(c), m_next(n) { }
		// copy
		Elem(Elem<T>* src): m_prev(src->m_prev), m_content(src->m_content), m_next(src->m_next) { }
		// assignation
		Elem operator=(Elem<T>* src)
		{
			m_prev = src->m_prev; 
			m_content = src->m_content; 
			m_next = src->m_next;
		}
		// destructor
		virtual ~Elem() { }

		// ----------------------------------------------------------------

		/*
		** --- Member methods
		*/

		void insert_as_prev(Elem *e)
		{
			if (m_prev)
			{
				e->m_prev = m_prev;
				m_prev->m_next = e;
			}
			e->m_next = this;
			m_prev = e;
		}

		void insert_as_next(Elem *e)
		{
			if (m_next)
			{
				e->m_next = m_next;
				m_next->m_prev = e;
			}
			e->m_prev = this;
			m_next = e;
		}

		void detach(void) {
			if (m_prev)
				m_prev->m_next = m_next;
			if (m_next)
				m_next->m_prev = m_prev;
		}
		
	};

	/*
	** --- 2. Bidirectional Iterator
	*/

	template <typename T>
	class ListIterator
	{
		private:
			// na

		protected:
			// na

		public:
			// ----------------------------------------------------------------

			/*
			** --- Member types
			*/
		
			typedef T 							value_type;
			typedef T& 							reference;
			typedef T* 							pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef BidirectionalIteratorTag	iterator_category;

			Elem	<T>*						m_elem;
			
			// ----------------------------------------------------------------

			/*
			** --- Constructors & Destructors
			*/
		
			ListIterator(): m_elem(NULL) { }
			ListIterator(Elem<T>* e): m_elem(e) { }
			ListIterator(const ListIterator<T>& src): m_elem(src.m_elem) { }
			ListIterator<T>& operator=(const ListIterator<T>& src)
			{
				m_elem = src.m_elem;
				return (*this);
			}
			~ListIterator() { }

			// ----------------------------------------------------------------

			/*
			** --- Getters and setters
			*/

			Elem <T>* get_elem() const { return (m_elem); }
			void set_elem(Elem <T>* newElem) { m_elem = newElem; }

			Elem <T>* get_prev() const { return (m_elem->m_prev);  }
			void set_prev(Elem <T>* newPrev) { m_elem->m_prev = newPrev; }

			Elem <T>* get_next() const { return (m_elem->m_next); }
			void set_next(Elem <T>* newNext) { m_elem->m_next = newNext; }

			// ----------------------------------------------------------------

			/*
			** --- Operators
			*/

			ListIterator<T>& operator++()
			{
				m_elem = m_elem->m_next;
				return (*this);
			}

			ListIterator<T> operator++(int)
			{
				ListIterator<T> postIncrement = *this;
				m_elem = m_elem->m_next;
				return (postIncrement);
			}

			ListIterator<T>& operator--()
			{
				m_elem = m_elem->m_prev;
				return (*this);
			}

			ListIterator<T> operator--(int)
			{
				ListIterator<T> postDecrement = *this;
				m_elem = m_elem->m_prev;
				return (postDecrement);
			}

			T& operator*() const
			{
				return (m_elem->m_content);
			}

			bool operator==(const ListIterator<T>& src)
			{
				return (get_elem()->m_content == src.get_elem()->m_content
					&& get_elem()->m_prev == src.get_elem()->m_prev)
					&& get_elem()->m_next == src.get_elem()->m_next;
			}

			bool operator!=(const ListIterator<T>& src)
			{
				return (get_elem()->m_content != src.get_elem()->m_content
						|| get_elem()->m_prev != src.get_elem()->m_prev)
						|| get_elem()->m_next != src.get_elem()->m_next;
			}

	};

	/*
	** --- 3. Reverse Bidirectional Iterator
	*/

	template <typename T>
	class ReverseListIterator
	{
		private:
			// na

		protected:
			// na

		public:
			// ----------------------------------------------------------------

			/*
			** --- Member types
			*/
		
			typedef T 							value_type;
			typedef T& 							reference;
			typedef T* 							pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef BidirectionalIteratorTag	iterator_category;

			Elem	<T>*						m_elem;
			
			// ----------------------------------------------------------------

			/*
			** --- Constructors & Destructors
			*/
		
			ReverseListIterator(): m_elem(NULL) { }
			ReverseListIterator(Elem<T>* e): m_elem(e) { }
			ReverseListIterator(const ReverseListIterator<T>& src): m_elem(src.m_elem) { }
			ReverseListIterator(const ListIterator<T>& src): m_elem(src.m_elem) { }
			ReverseListIterator<T>& operator=(const ReverseListIterator<T>& src)
			{
				m_elem = src.m_elem;
				return (*this);
			}
			~ReverseListIterator() { }

			// ----------------------------------------------------------------

			/*
			** --- Getters and setters
			*/

			Elem <T>* get_elem() const { return (m_elem); }
			void set_elem(Elem <T>* newElem) { m_elem = newElem; }

			Elem <T>* get_prev() const { return (m_elem->m_prev);  }
			void set_prev(Elem <T>* newPrev) { m_elem->m_prev = newPrev; }

			Elem <T>* get_next() const { return (m_elem->m_next); }
			void set_next(Elem <T>* newNext) { m_elem->m_next = newNext; }

			// ----------------------------------------------------------------

			/*
			** --- Operators
			*/

			ReverseListIterator<T>& operator++()
			{
				m_elem = m_elem->m_prev;
				return (*this);
			}

			ReverseListIterator<T> operator++(int)
			{
				ReverseListIterator<T> postIncrement = *this;
				m_elem = m_elem->m_prev;
				return (postIncrement);
			}

			ReverseListIterator<T>& operator--()
			{
				m_elem = m_elem->m_next;
				return (*this);
			}

			ReverseListIterator<T> operator--(int)
			{
				ReverseListIterator<T> postDecrement = *this;
				m_elem = m_elem->m_next;
				return (postDecrement);
			}

			T& operator*() const
			{
				return (m_elem->m_content);
			}

			bool operator==(const ReverseListIterator<T>& src)
			{
				return (get_elem()->m_content == src.get_elem()->m_content
					&& get_elem()->m_prev == src.get_elem()->m_prev)
					&& get_elem()->m_next == src.get_elem()->m_next;
			}

			bool operator!=(const ReverseListIterator<T>& src)
			{
				return (get_elem()->m_content != src.get_elem()->m_content
						|| get_elem()->m_prev != src.get_elem()->m_prev)
						|| get_elem()->m_next != src.get_elem()->m_next;
			}

	};

	/*
	** --- 4. List
	*/

	template <typename T>
	class List
	{

		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		private:
			Elem<T>*	m_begin;
			Elem<T>*	m_end;
			size_t		m_len;
		
		protected:
			// na

		public:
			typedef ListIterator			<T> 		iterator;
			typedef ListIterator			<const T> 	const_iterator;

			typedef ReverseListIterator		<T>			reverse_iterator;
			typedef ReverseListIterator		<const T>	const_reverse_iterator;

			typedef 						T 			value_type;

			typedef		 					T& 			reference;
			typedef 						const T& 	const_reference;
			
			typedef 						T*	 		pointer;
			typedef 						const T* 	const_pointer;
			
			typedef std::ptrdiff_t	 					difference_type;
			typedef size_t 								size_type;

		// ----------------------------------------------------------------

		/*
		** --- Private methods
		*/

		private:

			void connect_past_the_end(void)
			{
				m_end = new Elem<value_type>();
				init_list_bounds();
			}
			
			void init_list_bounds(void)
			{
				m_begin = m_end;
				m_end->m_prev = NULL;
				m_end->m_next = NULL;
			}
			
			void push_back_list(List& src)
			{
				if (src.empty())
					return ;
				else if (!empty())
				{
					m_end->m_prev->m_next = src.m_begin;
					src.m_begin->m_prev = m_end->m_prev;
					m_end = src.m_end;
				}
				else
				{
					m_begin = src.m_begin;
					m_end = src.m_end;
				}
				m_len += src.size();
				src.m_len = 0;
				src.connect_past_the_end();
			}

			T& operator[](size_t index)
			{
				if (index < 0 || index >= m_len)
					throw (std::out_of_range("operator [] : index out of range"));
				Elem<T> *e;
				e = m_begin;
				for (size_t i = 0; i != index; i++)
					e = e->m_next;
				return (e->m_content);
			}

		// --------------------------------------------------------------------
			
		public:
			// ----------------------------------------------------------------
			
			/*
			** --- Coplien form
			*/

			// default: Constructs an empty list with zero elements.
			List():
				m_begin(NULL), m_end(NULL), m_len(0) { connect_past_the_end(); }

		    // fill: Constructs a new list with n elements and assigns val to each element of list.
			List(size_type n, const value_type& val = value_type()):
				m_begin(NULL), m_end(NULL), m_len(0) { connect_past_the_end(); assign(n, val); }

		    // range: Constructs a list with as many elements as in range of first to last.
			List(iterator first, iterator last):
				m_begin(NULL), m_end(NULL), m_len(0) { connect_past_the_end(); assign(first, last); }
			
		    // copy: Constructs the container with the copy of the contents of src.
			// If alloc is not provided, allocator is obtained as if by calling
			List(List& src):
				m_begin(NULL), m_end(NULL), m_len(0) { connect_past_the_end(); assign(src.begin(), src.end()); }
			
			// destructors
			virtual ~List() { clear(); delete m_end; }

			// ----------------------------------------------------------------
			
			/*
			** --- Member functions
			*/

			void assign(iterator first, iterator last) 
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			
			void assign(const_iterator first, const_iterator last) 
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			
			void assign(size_type size, const_reference val) 
			{
				clear();
				for (size_type i = 0; i < size; i++)
					push_back(val);
			}

			// assignement
			List &operator=(List& src) { assign(src.begin(), src.end()); return (*this); }

			// ----------------------------------------------------------------

			/*
			** --- Element access
			*/
		
			reference front() { return (m_begin->m_content); }
			const_reference front() const { return (m_begin->m_content); }

			reference back() 
			{
				if (empty())
					return (front());
				else
					return (m_end->m_prev->m_content);
			}
			const_reference back() const 
			{
				if (empty())
					return (front());
				else
					return (m_end->m_prev->m_content);
			}
			
			// ----------------------------------------------------------------

			/*
			** --- Iterators
			*/

			iterator begin() { return (iterator(m_begin)); }
			const_iterator begin() const { return (const_iterator(m_begin)); }

			iterator end() { return (iterator(m_end)); }
			const_iterator end() const { return (const_iterator(m_end)); }

			reverse_iterator rbegin() { return (reverse_iterator(m_end->m_prev)); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(m_end->m_prev)); }

			reverse_iterator rend() { return (reverse_iterator(m_begin)); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(m_begin)); }

			// ----------------------------------------------------------------

			/*
			** --- Capacity
			*/

			bool empty() const { return (m_len == 0); }

			size_t size() const { return (m_len); }
			
			size_type max_size() const { return (std::numeric_limits<difference_type>::max()); }
			
			// ----------------------------------------------------------------

			/*
			** --- Modifiers
			*/

			void clear(void) { erase(begin(), end()); init_list_bounds(); }

			// insert 1 - iterator insert( iterator pos, const T& value );
			iterator insert(iterator pos, const value_type& val)
			{
				if (pos == begin())
				{
					push_front(val);
					return (begin());
				}
				else if (pos == end())
				{
					push_back(val);
					return (end());
				}
				else
				{
					Elem<T> *newElem = new Elem<T>(NULL, val, NULL);
					pos.get_elem()->insert_as_prev(newElem);
					m_len++;
					return (iterator(newElem));
				}
			}

			// insert 2 - void insert( iterator pos, size_type count, const T& value );
			void insert(iterator pos, size_type count, const value_type& val)
			{
				for (size_type i = 0; i < count; i++)
					insert(pos, val);
			}
			
			// insert 3
			void insert(iterator pos, iterator first, iterator last)
			{
				while (first != last)
				{
					insert(pos, *first);
					first++;
				}
			}

			// erase 1
			iterator erase(iterator pos)
			{
				if (pos == begin())
				{
					pop_front();
					return (begin());
				}
				else if (pos == end())
				{
					pop_back();
					return (end());
				}
				else
				{
					Elem<T> *next = pos.get_elem()->m_next;
					pos.get_elem()->detach();
					m_len--;
					delete pos.get_elem();
					return (iterator(next));
				}				
			}

			// erase 2
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				return (first);
			}
			
			void push_back(const value_type& val)
			{
				Elem<T> *e = new Elem<T>(NULL, val, NULL);
				m_end->insert_as_prev(e);
				if (empty())
					m_begin = e;
				++m_len;
			}

			void pop_back(void)
			{
				if (empty())
					;
				else if (m_len == 1)
					pop_front();
				else if (m_len >= 1)
				{
					Elem<T> *e = m_end->m_prev;
					m_end->m_prev->detach();
					delete e;
					--m_len;
				}
			}

			void push_front(const value_type& val)
			{
				Elem<T> *tmp = new Elem<T>(NULL, val, NULL);
				if (empty())
					m_end->insert_as_prev(tmp);
				else
					m_begin->insert_as_prev(tmp);
				m_begin = tmp;
				m_len++;
			}

			void pop_front(void)
			{
				if (empty())
					;
				else if (m_len == 1)
				{
					delete m_begin;
					m_begin = m_end;
					m_end->m_prev = NULL;
					m_len--;
				}
				else if (m_len >= 1)
				{
					Elem<T> *tmp = m_begin->m_next;
					m_begin->detach();
					delete m_begin;
					m_begin = tmp;
					m_len--;
				}
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n >= m_len)
					insert(end(), n - m_len, val);
				else
				{
					iterator ite = begin();
					for (size_t i = 0; i < n; i++)
						++ite;
					erase(ite, end());
				}
			}

			void swap(List& src)
			{
				std::swap(m_begin, src.m_begin);
				std::swap(m_end, src.m_end);
				std::swap(m_len, src.m_len);
			}

			/*
			** --- Operations
			*/
		
			// splice 1 - transfers all elements from list x to *this. The container x becomes empty after the operation.
			void splice( iterator pos, List& src )
			{
				splice(pos, src, src.begin(), src.end());
			}

			// splice 2 - transfers the element pointed to by iterator i from list x into *this. The element is inserted before the element pointed to by position.
			void splice( iterator pos, List& src, iterator src_pos )
			{
				splice(pos, src, src_pos, src_pos.get_next());
			}

			// splice 3 - transfers the elements in the range of first to last from x to *this. The elements are inserted before the element pointed to by position.
			void splice( iterator pos, List& src, iterator first, iterator last)
			{
				insert(pos, first, last);
				src.erase(first, last);
				if (src.m_len == 0)
					src.init_list_bounds();
			}

			// remove - Remove elements with specific value (public member function )
			void remove(const value_type& val)
			{
				if (m_len)
				{
					iterator ite = begin();
					iterator it_end = end();
					
					while (ite != it_end)
					{
						if (*ite == val)
							ite = erase(ite);
						else
							++ite;
					}
				}
			}

		    // remove_if - Remove elements fulfilling condition (public member function template )
			template <typename Predicate>
			void remove_if(Predicate pred)
			{
				if (m_len)
				{
					iterator ite = begin();
					iterator it_end = end();
					
					while (ite != it_end)
					{
						if (pred(*ite))
							ite = erase(ite);
						else
							++ite;
					}
				}
			}

			// unique 1 - Remove duplicate values (public member function )
			void unique(void)
			{
				if (m_len)
				{
					Elem<T> *e = m_begin;
					Elem<T> *next;

					for (size_t i = 0; i < m_len; i++)
					{
						next = e->m_next;
						if (e->m_prev && e->m_prev->m_content == e->m_content)
							erase(iterator(e));
						e = next;
					}
				}
			}
			
			// unique 2 - Remove duplicate values (public member function )
			template <typename BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				if (m_len)
				{
					Elem<T> *e = m_begin;
					Elem<T> *next;
					for (size_t i = 0; i < m_len; i++)
					{
						next = e->m_next;
						if (e->m_prev && (*binary_pred)(e->m_prev->m_content, e->m_content))
							erase(iterator(e));
						e = next;
					}
				}
			}
		
			// merge 1 - Merge sorted lists (public member function )
			void merge(List& x)
			{
				push_back_list(x);
				sort();
			}
			
			// merge 2 - Merge sorted lists (public member function )			
			template <typename Compare>
			void merge(List& x, Compare comp)
			{
				push_back_list(x);
				sort(comp);
			}
			
			// sort 1 - Sort elements in container (public member function )
			void sort(void)
			{
				if (m_len > 1)
					sort(&is_less_than<T>);
			}
			
			// sort 2 - Sort elements in container (public member function )
			template<class Compare>
			void sort(Compare comp)
			{
				if (m_len > 1)
				{
					T e;
										
					for (size_t i = 0; i < m_len; i++)
					{
						for (size_t j = 0; j < m_len - 1; j++)
						{
							if (comp((*this)[j + 1], (*this)[j]))
							{
								e = (*this)[j + 1];
								(*this)[j + 1] = (*this)[j];
								(*this)[j] = e;
							}
						}
					}
				}
			};
			
			// reverse - Reverse the order of elements (public member function )
			void reverse()
			{
				if (m_len > 1)
				{
					T e;
					for (size_t i = 0, j = m_len - 1; i < j; i++, j--)
					{
						e = (*this)[i];
						(*this)[i] = (*this)[j];
						(*this)[j] = e;
					}
				}
			}

	};

	/*
	** --- 5. Non member functions
	*/

	template<class T>
	bool operator==( List<T>& lhs, List<T>& rhs )
	{
		if (lhs.empty() && rhs.empty())
			return (true);
		else if (lhs.size() != rhs.size())
			return (false);
		else
		{
			typename List<T>::iterator lhs_ite = lhs.begin();
			typename List<T>::iterator rhs_ite = rhs.begin();
			for (; lhs_ite != lhs.end() && rhs_ite != rhs.end(); lhs_ite++, rhs_ite++)
			{
				if (*lhs_ite != *rhs_ite)
					return (false);
			}
		}		
		return (true);		
	}

	template<class T>
	bool operator!=( List<T>& lhs, List<T>& rhs ) { return (!(lhs == rhs)); }

/*
** Lexicographical comparison is a operation with the following properties:
** 
** Two ranges are compared element by element.
** The first mismatching element defines which range is lexicographically less or greater than the other.
** If one range is a prefix of another, the shorter range is lexicographically less than the other.
** If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
** An empty range is lexicographically less than any non-empty range.
** Two empty ranges are lexicographically equal.
**
** https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
*/

	template<class T>
	bool operator<( List<T>& lhs, List<T>& rhs )
	{
		if (lhs.empty() && rhs.empty())
			return (false); // equals
		else if (lhs.empty() && !rhs.empty())
			return (true); // lhs inf
		else if (!lhs.empty() && rhs.empty())
			return (false); // lhs sup
		else
		{
			typename List<T>::iterator lhs_ite = lhs.begin();
			typename List<T>::iterator rhs_ite = rhs.begin();

			for (; lhs_ite != lhs.end() && rhs_ite != rhs.end(); lhs_ite++, rhs_ite++)
			{
				if (*lhs_ite != *rhs_ite)
					return (*lhs_ite < *rhs_ite); // lhs inf (true) or sup (false)
			}
		}
		if (lhs.size() == rhs.size())
			return (false); // iterated elements are equals and so size -> equals
		else
			return (lhs.size() < rhs.size()); // lhs inf (true) or sup (false)
	}

	template<class T>
	bool operator<=( List<T>& lhs, List<T>& rhs ) { return ((lhs < rhs) || (lhs == rhs)); }

	template<class T>
	bool operator>( List<T>& lhs, List<T>& rhs ) { return (!(lhs <= rhs)); }

	template<class T>
	bool operator>=( List<T>& lhs, List<T>& rhs ) { return (!(lhs < rhs)); }
}


#endif
