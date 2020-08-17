/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:59:16 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/13 19:26:28 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
