/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 23:23:26 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/14 20:32:51 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../../Utils/Iterator.hpp"
# include <cstddef>
# include <string>
# include <stdio.h>
# include <limits>
# include <memory>
# include <iostream>
# include <string>

# include "BinarySearchTree.hpp"

/*
** Summary:
** --- Map                      	class
** --- Non member functions			nm
*/

/*
** Todo:
** ok all
*/

namespace ft
{
	
	/*
	** --- Map
	*/

	template<
		class Key,
		class T,
		class Compare = std::less<Key>
	> class Map
	{

		// ----------------------------------------------------------------

		/*
		** --- Member types
		*/

		public:

			typedef 			Key									key_type;
			typedef				std::pair<Key,T>					value_type;
			typedef 			Compare								key_compare;
			// https://en.cppreference.com/w/cpp/container/map/value_comp
			// typedef 			Compare								value_compare;
			typedef 			T									T_NULL;
			
			typedef 			BST<Key,
									T,
									key_compare>					tree_type;
									
			typedef typename	BST<Key,
									T,
									Compare>::BSTIterator 			iterator;

			typedef typename	BST<Key const,
									T const,
									Compare>::BSTIterator 			const_iterator;

			typedef typename	BST<Key,
									T,
									Compare>::BSTIterator 			reverse_iterator;

			typedef typename	BST<Key const,
									T const,
									Compare>::ReverseBSTIterator 	const_reverse_iterator;

			typedef typename	tree_type::Elem 					elem_type;
			typedef 			elem_type*							elem_pointer;

			typedef		 					T& 						reference;
			typedef 						const T& 				const_reference;
			
			typedef 						T*	 					pointer;
			typedef 						const T* 				const_pointer;
			
			typedef std::ptrdiff_t	 								difference_type;
			typedef size_t 											size_type;


		protected:
			// na
		
		private:
		
			BST<Key,T,Compare>      								m_tree;
		
		// ----------------------------------------------------------------
		
		private:
		
			void display(void) { m_tree.display(); }
		
		public:
			
			/*
			** --- Coplien form
			*/

			// default
			Map():m_tree() { }

			// range
			Map(iterator first, iterator last):
				m_tree()
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			
			// copy
			Map(Map const &src):
				m_tree()
			{
				m_tree.copyBST(src.m_tree);
			}

			// destructors
			virtual ~Map()
			{
				if (!empty())
					m_tree.clear();
			}

			// assignement
			Map &operator=(Map& src)
			{
				if (!empty())
					clear();
				m_tree = src.m_tree;
				return (*this);
			}
			
			// ----------------------------------------------------------------

			/*
			** --- Element access
			*/

			T& operator[](key_type key)
			{
				elem_pointer e = m_tree.find(key);
				if (e)
					return (e->m_pair.second);
				else
				{
					elem_pointer new_e = m_tree.insert(std::make_pair(key, T_NULL()));
					return (new_e->m_pair.second);
				}
			}

			// ----------------------------------------------------------------

			/*
			** --- Iterators
			*/

			iterator begin() { return (iterator(m_tree.begin(), m_tree.m_root )); }
			iterator end() { return (iterator(m_tree.end(), m_tree.m_root )); }

			const_iterator begin() const { return (const_iterator(m_tree.begin(), m_tree.m_root )); }
			const_iterator end() const { return (const_iterator(m_tree.end(), m_tree.m_root )); }

			reverse_iterator rbegin() { return (reverse_iterator(m_tree.end(), m_tree.m_root )); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(m_tree.end(), m_tree.m_root )); }

			reverse_iterator rend() { return (reverse_iterator(m_tree.begin(), m_tree.m_root )); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(m_tree.begin(), m_tree.m_root )); }

			// ----------------------------------------------------------------

			/*
			** --- Capacity
			*/

			bool empty() const { return (m_tree.size() == 0); }

			size_t size() const { return (m_tree.size()); }

			size_t max_size() const { return (std::numeric_limits<difference_type>::max()); }

			// ----------------------------------------------------------------

			/*
			** --- Modifiers
			*/

			void clear(void)
			{
				m_tree.clear();
			}

			// insert 1
			std::pair<iterator,bool> insert( const value_type& value )
			{
				elem_pointer e = m_tree.find_pair(value);
				if (e)
					return (std::make_pair(iterator(e, m_tree.m_root), 0));
				else
				{
					elem_pointer new_e = m_tree.insert(value);
					return (std::make_pair(iterator(new_e, m_tree.m_root), 1));
				}
			}
			
			// insert 2
			iterator insert( iterator hint, const value_type& value )
			{
				elem_pointer e = hint.m_elem;
				elem_pointer ret = m_tree.insertPairAtHint(e, value);
				return (iterator(ret, m_tree.m_root));
			}
			
			// insert 3
			void insert( iterator first, iterator last )
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			// erase 1
			void erase( iterator pos )
			{
				m_tree.deleteElem(pos.m_elem);
			}

			// erase 2
			void erase( iterator first, iterator last )
			{
				if (first == begin() && last == end())
					clear();
				else
				{
					while (first != last)
						first = iterator(m_tree.deletePair(first.m_elem->m_pair), first.m_root);
				}
			}

			// erase 3
			size_type erase( const key_type& key )
			{
				size_type count = m_tree.erase(key);
				return (count);
			}

			void swap(Map &src) { m_tree.swap(src.m_tree); }
	
			// ----------------------------------------------------------------

			/*
			** --- Lookup
			*/

			// Returns the number of elements with key that compares equivalent
			// to the specified argument, which is either 1 or 0
			// since this container does not allow duplicates.
			size_type count( const Key& key ) const
			{
				elem_pointer e = m_tree.find(key);
				if (e)
					return (1);
				else
					return (0);
			}

			// Finds an element with key equivalent to key.
			iterator find( const Key& key )
			{
				elem_pointer e = m_tree.find(key);
				if (e)
					return (iterator(e, m_tree.m_root));
				return (end());
			}

			// Finds an element with key equivalent to key.
			const_iterator find( const Key& key ) const
			{
				elem_pointer e = m_tree.find(key);
				if (e)
					return (const_iterator(e, m_tree.m_root));
				return (end());	
			}


			std::pair<iterator,iterator> equal_range( const Key& key )
			{
				// return (std::make_pair(lower_bound(key), upper_bound(key)));
				// http://www.cplusplus.com/reference/utility/pair/pair/
				return (std::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}

			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				// return (std::make_pair(lower_bound(key), upper_bound(key)));
				// http://www.cplusplus.com/reference/utility/pair/pair/
				return (std::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
			}

			// Iterator pointing to the first element that is not less than key.
			// i.e. greater or equal to key.
			// If no such element is found, a past-the-end iterator (see end()) is returned.
			iterator lower_bound( const Key& key )
			{
				iterator it = begin();

				for (; it != end(); it++)
				{
					if (!(key_comp()((*it).first, key)))
						return (iterator(it));
				}
				return (end());
			}

			const_iterator lower_bound( const Key& key ) const
			{
				const_iterator it = begin();

				for (; it != end(); it++)
				{
					if (!(key_comp()((*it).first, key)))
						return (const_iterator(it));
				}
				return (end());
			}
			
			// Iterator pointing to the first element that is greater than key.
			// If no such element is found, past-the-end (see end()) iterator is returned.
			iterator upper_bound( const Key& key )
			{
				iterator it = begin();

				for (; it != end(); it++)
				{
					if (key_comp()(key, (*it).first))
						return (iterator(it));
				}
				return (end());
			}

			const_iterator upper_bound( const Key& key ) const
			{
				const_iterator it = begin();

				for (; it != end(); it++)
				{
					if (!(key_comp()(key, (*it).first)))
						return (const_iterator(it));
				}
				return (end());
			}

			// ----------------------------------------------------------------

			/*
			** --- Observers
			*/

			key_compare key_comp(void) const
			{
				return (m_tree.m_comp);
			}
			
			// Returns a function object that compares objects
			// of type std::map::value_type (key-value pairs)
			// by using key_comp to compare the first components of the pairs.
			key_compare value_comp() const
			{
				return (m_tree.m_comp);
			}
};

	/*
	** --- Non member functions
	*/

	template< class Key, class T, class Compare >
	bool operator==( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		else if(lhs.size() > 0)
		{
			typename ft::Map<Key,T,Compare>::iterator lhs_ite = lhs.begin();
			typename ft::Map<Key,T,Compare>::iterator rhs_ite = rhs.begin();

			for (; lhs_ite != lhs.end(); ++lhs_ite, ++rhs_ite)
			{
				if ((*lhs_ite).first != (*rhs_ite).first
					|| (*lhs_ite).second != (*rhs_ite).second)
				{
					return (false);
				}
			}
		}
		return (true);
	}

	template< class Key, class T, class Compare >
	bool operator!=( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare >
	bool operator<( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		if(lhs.size() > 0 && rhs.size() > 0)
		{
			typename ft::Map<Key,T,Compare>::iterator lhs_ite = lhs.begin();
			typename ft::Map<Key,T,Compare>::iterator rhs_ite = rhs.begin();

			for (; lhs_ite != lhs.end(); ++lhs_ite, ++rhs_ite)
			{
				if ((*lhs_ite).first != (*rhs_ite).first
					|| (*lhs_ite).second != (*rhs_ite).second)
				{
					return (false);
				}
			}
			return (lhs.size() < rhs.size());
		}
		else
			return (lhs.size() < rhs.size());
	}

	template< class Key, class T, class Compare >
	bool operator<=( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	template< class Key, class T, class Compare >
	bool operator>( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		return (!(lhs <= rhs));
	}

	template< class Key, class T, class Compare >
	bool operator>=( ft::Map<Key,T,Compare>& lhs, ft::Map<Key,T,Compare>& rhs )
	{
		return (!(lhs < rhs));
	}


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

}


#endif
