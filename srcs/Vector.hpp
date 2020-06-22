/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henri <henri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 00:38:29 by henri             #+#    #+#             */
/*   Updated: 2020/06/23 00:21:17 by henri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

/* Main documentation : https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=vs-2019 */
/* Source Code : https://code.woboq.org/llvm/libcxx/include/vector.html */
/* CMD + F "TODO" */

# include "iterator.hpp"

namespace ft {

template <class T, class A = std::allocator<T> >

class Vector {

public:

	/* Template parameters */

	typedef T value_type;
	typedef A allocator_type;

	/* Allocator Types Members (and not variables members) */
	/* Typename tells the compiler that ::reference isn't a static member of A
	Ex : A::reference is a type and not a static variable of A
	The use of typename is required when it deals with template parameters
	More information in the markedown courses folder */

	/* The test file stl/Vector.cpp illustrate the purpose
	of the following code */

	typedef typename A::reference				reference;
	typedef typename A::const_reference			const_reference;
	typedef typename A::pointer					pointer;
	typedef typename A::const_pointer			const_pointer;
	typedef typename A::difference_type			difference_type;
	typedef typename A::size_type				size_type;

	class iterator: public IteratorBase<T> {

	public:

		typedef typename A::pointer				pointer;
		typedef typename A::reference			reference;
		typedef typename A::value_type			value_type;
		typedef typename A::difference_type		difference_type;
		/* Here we don't rely on template parameters, so typename isn't required */
		/* STL vector rely on random_access_iterator */
		typedef std::random_access_iterator_tag	iterator_category;

		/* Iterator Constructors */

		iterator(): IteratorBase<T>();
		iterator(const iterator & it): IteratorBase<T>(it._p) {};
		iterator(pointer p) : BaseIter<T>(p){}; /* it = &(arr[0]) */
		virtual ~iterator() {};

		/* Operators functions */

		/* http://ee.usc.edu/~redekopp/cs104/slides/L20b_Iterators.pdf */
		/* Vector Iterator is : random_access_iterator_tag
		/* How to know which operators must be available  for a giving type of iterator : http://www.cplusplus.com/reference/iterator/ */
		/* By the way, theses operators can't be overloaded :  .   ::   sizeof   ?: */

		iterator & operator=(const iterator & it) { this->_p = it._p; return *this; };
		/* To differentiate the designers of C++ arbitrarily said, we'll pass a dummy int to the operator++() for POST-increment */
		/* Pre vs Post incrementation : http://ee.usc.edu/~redekopp/cs104/slides/L20b_Iterators.pdf */
		iterator & operator++() { this->_p++; return *this; }; /* ++ it */
		iterator & operator++(int) { iterator it = *this; this->_p++; return *it; };
		iterator & operator--() { this->_p--; return *this; }; /* -- it */
		iterator & operator--(int) { iterator it = *this; this->_p--; return *it; };
		iterator & operator+=(difference_type n) { this->_p += n; return (*this); };
		iterator & operator-=(difference_type n) { this->_p -= n; return (*this); };

		/* The next 7 functions are specifics to random_access_iterator */
		/* Functions by iterators here : http://www.cplusplus.com/reference/iterator/ */

		iterator   operator+(difference_type n) const { return iterator(this->_p + n); };
		iterator   operator-(difference_type n) const { return iterator(this->_p - n); };
		friend iterator operator+(difference_type n, const iterator &it) { return iterator(it._p + n); };
		difference_type operator-(const BaseIter<T> &other) { return this->_p - other.getIT(); };
		reference operator*() const { return *this->_p; };
		pointer operator->() const { return this->_p; };
		reference operator[](difference_type n) const { return *(this->_p + n); };

	};

private:
	static const float _growth = 1.5; /* https://stackoverflow.com/questions/5232198/about-vectors-growth */
	size_type _size;
	size_type _capacity;
	allocator_type _allocator;
	pointer _arr;

};

};

# endif
