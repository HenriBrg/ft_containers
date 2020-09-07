# Les itérateurs

Plusieurs programmes de tests dans training/

La manière d'accéder aux données des conteneurs dépend bien entendu de leur nature et de leur structure.
Il existe une hiérarchie dans la classification des itérateurs.

`std::iterator` is the base class provided to simplify definitions of the required types for iterators.

1. Les itérateurs de la catégorie « Output »
2. Les itérateurs de la catégorie « Input »
3. Les itérateurs de la catégorie « Forward »
4. Les itérateurs de la catégorie « Bidirectionnal »
5. Les itérateurs de la catégorie « RandomAccess »

Each category define an exact set of operations that are supported, efficiently, by the iterator.

Ce [schéma](http://www.cplusplus.com/reference/iterator/) résumé parfaitement les différences entre ces 5 catégories

Parmi les cinq types d'itérateurs, seuls deux sont utilisés pour les conteneurs :

- les bidirectional iterators
- les random access iterators

Vector = random access iterator
List = bidirectional iterator
Deque = random access iterator
Stack = aucun
Map = bidirectional iterator

Le template iterator comprend :

    typedef T         value_type		--> le type T passé au conteneur (ex: int si vector<int>)
    typedef Distance  difference_type	--> the type that results from a difference - of two such iterators
    typedef Pointer   pointer			--> the type pointer to the element that the iterator refers to
    typedef Reference reference			--> the type reference to the element that iterator refers to
    typedef Category  iterator_category	--> le type (parmi les 1/2/3/4/5)

La difference_type d'un int\* est donc ptrdiff_t puisque si p1 et p2 sont des pointeurs, p1 - p2 est égal à ptrdiff_t

**Différence iterator / const iterator**

There is no performance difference. A const_iterator is an iterator that points to const value. Dereferencing it returns a reference to a constant value and prevents modification of the referenced value.

**Reverse iterators**

Reverse iterators iterate backwards : increasing them moves them towards the beginning of the container.

For Vector, the rbegin function points to the element right before the one that would be pointed to by member end.
Notice that unlike member vector::back, which returns a reference to this same element, this function returns a reverse random access iterator.
