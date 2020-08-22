#ifndef ITERATOR_HPP
#define ITERATOR_HPP

struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag: public InputIteratorTag {};
struct BidirectionalIteratorTag: public ForwardIteratorTag {};
struct RandomAccessIteratorTag: public BidirectionalIteratorTag {};

#endif
