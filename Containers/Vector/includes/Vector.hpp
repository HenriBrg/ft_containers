#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../../Utils/Iterator.hpp"
# include <cstddef>
# include <string>
# include <stdio.h>
# include <limits>
# include <memory>
# include <iostream>
# include <string>

/*
** Summary:
** --- Random Access Iterator			class
** --- Reverse Random Access Iterator	class
** --- Vector                      		class
** --- Non member functions				nm
*/

namespace ft
{

	/*
	** --- Random Access Iterator
	*/

	template <typename T>
	class VectorIterator
	{

		/*
		** --- Member types
		*/

		public:
			typedef T 							value_type;
			typedef T& 							reference;
			typedef T* 							pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef RandomAccessIteratorTag 	iterator_category;

		protected:
			// na

		private:
			T                                  *m_ptr;


		// ----------------------------------------------------------------

		public:

			/*
			** --- Constructors & Destructors
			*/

			VectorIterator(): m_ptr(NULL) { }
			VectorIterator(T *ptr): m_ptr(ptr) { }
			VectorIterator(const VectorIterator<T>& src): m_ptr(src.m_ptr) { }
			VectorIterator<T>& operator=(const VectorIterator<T>& src) { m_ptr = src.m_ptr; return (*this); }
			~VectorIterator() { }

			// ----------------------------------------------------------------

			/*
			** --- Getters and setters
			*/

			T *get_content() const { return (m_ptr); }
			void set_content(T *newPtr) { m_ptr = newPtr; }

			// T *get_prev() const { return (m_ptr->m_prev);  }
			// void set_prev(T *newPrev) { m_ptr->m_prev = newPrev; }

			// T *get_next() const { return (m_ptr->m_next); }
			// void set_next(T *newNext) { m_ptr->m_next = newNext; }

			// ----------------------------------------------------------------

			/*
			** --- Operators
			*/

			reference operator+=(difference_type n)
			{
				m_ptr += n;
				return (*this);
			}

			VectorIterator operator+(difference_type n) const
			{
				return (VectorIterator(m_ptr + n));
			};

			difference_type operator+(VectorIterator it)
			{
				return (m_ptr + it.m_ptr);
			};

			reference operator-=(difference_type n)
			{
				m_ptr -= n;
				return (*this);
			}

			VectorIterator operator-(difference_type n) const
			{
				VectorIterator it;

				it.m_ptr = m_ptr - n;
				return (it);
			};

			difference_type operator-(VectorIterator it)
			{
				return (m_ptr - it.m_ptr);
			};

			reference operator[](difference_type n) const
			{
				return (*(m_ptr + n));
			};

			T& operator*() const
			{
				return (*m_ptr);
			}

			bool operator==(const VectorIterator<T>& src)
			{
				return (get_content() == src.get_content());
			}

			bool operator!=(const VectorIterator<T>& src)
			{
				return (get_content() != src.get_content());
			}

			VectorIterator<T> operator++()
			{
				m_ptr++;
				return (*this);
			}

			VectorIterator<T> operator++(int)
			{
				VectorIterator<T> postIncrement = *this;
				m_ptr++;
				return (postIncrement);
			}

			reference operator--()
			{
				m_ptr--;
				return (*this);
			}

			VectorIterator<T> operator--(int)
			{
				VectorIterator<T> postDecrement = *this;
				m_ptr--;
				return (postDecrement);
			}

	};


	template <typename T>
	class ReverseVectorIterator
	{
		/*
		** --- Member types
		*/

		public:
			typedef T 							value_type;
			typedef T& 							reference;
			typedef T* 							pointer;
			typedef std::ptrdiff_t				difference_type;
			typedef RandomAccessIteratorTag 	iterator_category;

		protected:
			// na

		private:
			T                                  *m_ptr;


		// ----------------------------------------------------------------

		public:

			/*
			** --- Constructors & Destructors
			*/

			ReverseVectorIterator(): m_ptr(NULL) { }
			ReverseVectorIterator(T *ptr): m_ptr(ptr) { }
			ReverseVectorIterator(const ReverseVectorIterator<T>& src): m_ptr(src.m_ptr) { }
			ReverseVectorIterator<T>& operator=(const ReverseVectorIterator<T>& src) { m_ptr = src.m_ptr; return (*this); }
			~ReverseVectorIterator() { }

			// ----------------------------------------------------------------

			/*
			** --- Getters and setters
			*/

			T *get_content() const { return (m_ptr); }
			void set_content(T *newPtr) { m_ptr = newPtr; }

			// T *get_prev() const { return (m_ptr->m_prev);  }
			// void set_prev(T *newPrev) { m_ptr->m_prev = newPrev; }

			// T *get_next() const { return (m_ptr->m_next); }
			// void set_next(T *newNext) { m_ptr->m_next = newNext; }

			// ----------------------------------------------------------------

			/*
			** --- Operators
			*/

			reference operator+=(difference_type n)
			{
				m_ptr -= n;
				return (*this);
			}

			ReverseVectorIterator operator+(difference_type n) const
			{
				return (ReverseVectorIterator(m_ptr - n));
			};

			difference_type operator+(ReverseVectorIterator it)
			{
				return (m_ptr - it.m_ptr);
			};

			reference operator-=(difference_type n)
			{
				m_ptr += n;
				return (*this);
			}

			ReverseVectorIterator operator-(difference_type n) const
			{
				ReverseVectorIterator it;

				it.m_ptr = m_ptr + n;
				return (it);
			};

			difference_type operator-(ReverseVectorIterator it)
			{
				return (m_ptr + it.m_ptr);
			};

			reference operator[](difference_type n) const
			{
				return (*(m_ptr + n));
			};

			T& operator*() const
			{
				return (*m_ptr);
			}

			bool operator==(const ReverseVectorIterator<T>& src)
			{
				return (get_content() == src.get_content());
			}

			bool operator!=(const ReverseVectorIterator<T>& src)
			{
				return (get_content() != src.get_content());
			}

			// https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
			// a < b	contextually convertible to bool	b - a > 0	Strict total ordering relation:
			// !(a < a)
			// if a < b then !(b < a)
			// if a < b and b < c then a < c
			// a < b or b < a or a == b
			// (exactly one of the expressions is true)
			// a > b	contextually convertible to bool	b < a	Total ordering relation opposite to a < b
			// a >= b	contextually convertible to bool	!(a < b)
			// a <= b	contextually convertible to bool	!(a > b)

			ReverseVectorIterator<T> operator++()
			{
				m_ptr--;
				return (*this);
			}

			ReverseVectorIterator<T> operator++(int)
			{
				ReverseVectorIterator<T> postIncrement = *this;
				operator++();
				return (postIncrement);
			}

			reference operator--()
			{
				m_ptr++;
				return (*this);
			}

			ReverseVectorIterator<T> operator--(int)
			{
				ReverseVectorIterator<T> postDecrement = *this;
				operator--();
				return (postDecrement);
			}

	};

	/*
	** --- Vector
	*/

	template <typename T, class Allocator = std::allocator<T> >
	class Vector
	{

		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		protected:

		public:
			typedef VectorIterator			<T> 		iterator;
			typedef VectorIterator			<const T> 	const_iterator;

			typedef ReverseVectorIterator	<T>			reverse_iterator;
			typedef ReverseVectorIterator	<const T>	const_reverse_iterator;

			typedef 						T 			value_type;

			typedef		 					T& 			reference;
			typedef 						const T& 	const_reference;

			typedef 						T*	 		pointer;
			typedef 						const T* 	const_pointer;

			typedef std::ptrdiff_t	 					difference_type;
			typedef size_t 								size_type;

			typedef Allocator 							allocator_type;

		private:
			T*      m_tab;
			size_t  m_size;
			size_t  m_cap;
			allocator_type m_allocator;

		// ----------------------------------------------------------------

		/*
		** --- Private methods
		*/

		private:

			void init_empty_vector(size_type n)
			{
				size_t target_cap = n;
				m_tab = m_allocator.allocate(target_cap);
				m_cap = target_cap;
				m_size = 0;
			}

		// ----------------------------------------------------------------

		public:

			/*
			** --- Coplien form
			*/

			// default
			Vector():
				m_tab(NULL), m_size(0), m_cap(0)
			{
				init_empty_vector(0);
			}


			/* -- ICI -- */

			// fill
			Vector(size_type n, const value_type& val = value_type()):
				m_tab(NULL), m_size(0), m_cap(0)
			{
				init_empty_vector(n);
				assign(n, val);
			}

			// range
			Vector(iterator first, iterator last):
				m_tab(NULL), m_size(0), m_cap(0)
			{
				difference_type n = last - first;

				init_empty_vector(n);
				assign(first, last);
			}

			// copy
			Vector(Vector& src):
				m_tab(NULL), m_size(0), m_cap(0)
			{
				init_empty_vector(src.m_cap);
				assign(src.begin(), src.end());
			}

			// destructors
			virtual ~Vector()
			{
				m_allocator.deallocate(m_tab, m_cap);
			}

			// ----------------------------------------------------------------

			/*
			** --- Member functions
			*/

			// assignement
			Vector &operator=(Vector& src)
			{
				assign(src.begin(), src.end());
				return (*this);
			}

			void assign(iterator first, iterator last)
			{
				if (!empty())
					clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign(const_iterator first, const_iterator last)
			{
				if (!empty())
					clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign( size_type count, const T& value )
			{
				if (!empty())
					clear();
				for (size_type i = 0; i < count; i++)
					push_back(value);
			}

			allocator_type get_allocator() const
			{
				return (m_allocator);
			}

			// ----------------------------------------------------------------

			/*
			** --- Element access
			*/

			reference at(size_type pos)
			{
				if (pos >= m_size)
					throw std::out_of_range("out of range: pos >= m_size");
				return (m_tab[pos]);
			}

			const_reference at(size_type pos) const
			{
				if (pos >= m_size)
					throw std::out_of_range("out of range: pos >= m_size");
				return (m_tab[pos]);
			}

			reference operator[](size_type pos)
			{
				// Accessing a nonexistent element through this operator is undefined behavior.
				return (m_tab[pos]);
			}

			const_reference operator[](size_type pos) const
			{
				// Accessing a nonexistent element through this operator is undefined behavior.
				return (m_tab[pos]);
			}

			reference front()
			{
				// Calling front on an empty container is undefined.
				return (m_tab[0]);
			}

			const_reference front() const
			{
				// Calling front on an empty container is undefined.
				return (m_tab[0]);
			}

			reference back()
			{
				// Calling back on an empty container causes undefined behavior.
				return (m_tab[m_size - 1]);
			}

			const_reference back() const
			{
				// Calling back on an empty container causes undefined behavior.
				return (m_tab[m_size - 1]);
			}

			// ----------------------------------------------------------------

			/*
			** --- Iterators
			*/

			iterator begin() { return (iterator(&m_tab[0])); }
			const_iterator begin() const { return (const_iterator(&m_tab[0])); }

			iterator end() { return (iterator(m_tab + m_size)); }
			const_iterator end() const { return (const_iterator(m_tab + m_size)); }

			reverse_iterator rbegin() { return (reverse_iterator(m_tab + m_size - 1)); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(m_tab + m_size - 1); }

			reverse_iterator rend() { return (reverse_iterator(m_tab - 1)); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(m_tab - 1)); }

			// ----------------------------------------------------------------

			/*
			** --- Capacity
			*/

			bool empty() const { return (m_size == 0); }

			size_t size() const { return (m_size); }

			size_t max_size() const { 
				return (std::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
			 }

			void reserve(size_type new_cap)
			{
				if (!new_cap || new_cap <= m_cap)
					return ;
				else if (new_cap > max_size())
					throw(std::length_error("new_cap > max_size()"));
				else
				{
					size_t new_m_cap;

					if (m_cap > 0)
						new_m_cap = m_cap;
					else
						new_m_cap = 1;

					// while (new_m_cap < new_cap)
					// 	new_m_cap *= 2; // next power of 2 increment
					new_m_cap = new_cap;

					T* tmp;
					tmp = m_allocator.allocate(new_m_cap);
					for (size_t i = 0; i < m_size; i++)
					{
						m_allocator.construct(&tmp[i], m_tab[i]);
						m_allocator.destroy(&m_tab[i]);
					}

					m_allocator.deallocate(m_tab, m_cap);

					m_tab = tmp;
					m_cap = new_m_cap;
				}
			}

			size_type capacity(void) const
			{
				return (m_cap);
			}

			// ----------------------------------------------------------------

			/*
			** --- Modifiers
			*/

			void clear(void)
			{
				m_allocator.deallocate(m_tab, m_cap);
				init_empty_vector(0);
			}

			// insert 1
			iterator insert(iterator pos, const T& value)
			{
				insert(pos, 1, value);
				return (pos + 1);
			}

			// insert 2
			void insert(iterator pos, size_type count, const T& value)
			{
				if (!count)
					return ;

				difference_type pos_index = pos - begin();

				if (m_size + count >= m_cap)
					reserve(m_size + count);

				// offset
				for (size_t i = (m_size + count); i >= count; --i)
					m_tab[i] = m_tab[i - count];

				m_size += count;

				for (size_t i = pos_index; i < (pos_index + count); i++)
					m_tab[i] = value;

			}

			// insert 3
			void insert(iterator pos, iterator first, iterator last)
			{
				difference_type pos_index = pos - begin();
				size_t count = static_cast<size_t>(last - first);
				if (!count)
					return ;

				if (m_size + count >= m_cap)
					reserve(m_size + count);

				for (size_t i = (m_size + count - 1); i >= count; i--)
					m_allocator.construct(&m_tab[i], m_tab[i - count]);

				m_size += count;

				for (size_t i = pos_index; i < (pos_index + count); i++)
					m_tab[i] = *first++;
			}

			// erase 1
			iterator erase(iterator pos)
			{
				difference_type pos_index = pos - begin();

				for (size_t i = pos_index; i < m_size - 1; i++)
					m_tab[i] = m_tab[i + 1];
				m_size -= 1;
				return (pos + 1);
			}

			// erase 2
			iterator erase(iterator first, iterator last)
			{
				difference_type first_index = first - begin();
				difference_type last_index = last - begin();
				difference_type offset = last - first;

				for (; first_index < last_index; first_index++)
					m_tab[first_index] = m_tab[first_index + offset];
				m_size -= offset;
				return (iterator(m_tab + first_index));
			}

			void push_back(const value_type& val)
			{
				if (m_size + 1 == m_cap)
					reserve(m_cap + 1);

				m_tab[m_size] = val;
				m_size += 1;
			}

			void pop_back(void)
			{
				erase(end() - 1);
			}

			void resize(size_type count, value_type val = value_type())
			{
				if (m_size > count)
					m_size = count;
				else if (m_size < count)
				{
					for (size_t i = m_size; i < count; i++)
						push_back(val);
				}
				else
					; // m_size == count
			};

			void swap(Vector &src)
			{
				std::swap(m_cap, src.m_cap);
				std::swap(m_size, src.m_size);
				std::swap(m_tab, src.m_tab);
			}

	};

	/*
	** --- Non member functions
	*/

	template<class T>
	bool operator==( Vector<T>& lhs, Vector<T>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
		{
			for (size_t i = 0; i < lhs.size(); i++)
				if (lhs[i] != rhs[i])
					return (false);
			return (true);
		}
	}

	template<class T>
	bool operator!=( Vector<T>& lhs, Vector<T>& rhs ) { return (!(lhs == rhs)); }

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
	bool operator<( Vector<T>& lhs, Vector<T>& rhs )
	{
		for (size_t i = 0, j = 0; i < lhs.size() && j < rhs.size(); i++, j++)
		{
			if (lhs[i] > rhs[j])
				return (false);
		}
		if (lhs.size() == rhs.size())
			return (false);
		else if (lhs.size() < rhs.size())
			return (true);
		else
			return (false);
	}

	template<class T>
	bool operator<=( Vector<T>& lhs, Vector<T>& rhs ) { return ((lhs < rhs) || (lhs == rhs)); }

	template<class T>
	bool operator>( Vector<T>& lhs, Vector<T>& rhs ) { return (!(lhs <= rhs)); }

	template<class T>
	bool operator>=( Vector<T>& lhs, Vector<T>& rhs ) { return (!(lhs < rhs)); }
}


#endif
