/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:37:15 by francisberg       #+#    #+#             */
/*   Updated: 2020/07/08 17:40:06 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag: public InputIteratorTag {};
struct BidirectionalIteratorTag: public ForwardIteratorTag {};
struct RandomAccessIteratorTag: public BidirectionalIteratorTag {};

#endif