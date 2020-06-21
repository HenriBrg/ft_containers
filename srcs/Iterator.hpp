/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henri <henri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 20:29:31 by henri             #+#    #+#             */
/*   Updated: 2020/06/21 11:58:50 by henri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

/* Vector Iterator Base */

template <typename T>

class IteratorBase {
	private:
		IteratorBase();
	protected:
		T *_p; /* C++ Calling Convention : underscore for private variables */
	public:
		IteratorBase(T *p): _p(p) {};
		virtual ~IteratorBase() {};
		T * getIT() const { return this->_p; };

		/* Comparatives Bool Functions */
		bool operator==(const IteratorBase &rhs) const { return _p == rhs._p; };
		bool operator!=(const IteratorBase &rhs) const { return _p != rhs._p; };
		bool operator<(const IteratorBase &rhs) const { return _p < rhs._p; };
		bool operator>(const IteratorBase &rhs) const { return _p > rhs._p; };
		bool operator<=(const IteratorBase &rhs) const { return _p <= rhs._p; };
		bool operator>=(const IteratorBase &rhs) const { return _p >= rhs._p; };
};

# endif
