Memento [Markdown](https://openclassrooms.com/fr/courses/1304236-redigez-en-markdown#/id/r-1304420)

## Introduction à la STL : Standard Template Library

Tous les containers de la STL incluent déjà le header \<iterator\> qui
fournit toutes les classes d'itérateurs possibles.

Il y a deux types de containers :

- Sequence containers : implement data structures which can be accessed sequentially.
- Associative containers : implement sorted data structures that can be quickly searched.

Plus d'infos sur cette [page](http://cs.stmarys.ca/~porter/csc/ref/stl/headers.html).
La STL et ses fonctions en détails [ici](http://www.cplusplus.com/reference/stl/).

## Explication de ce qu'est l'Allocator

Allocators are a very important concept in the STL. Every container is capable to take an allocator as argument. Then allocations will be performed using this allocator, and not the standard one.

L'opérateur new et malloc sont differents, chaque allocateur possède ses propres fonctions. La fonction **malloc** retourne une data non initialisée, **calloc** retourne une "zero-ed data", **new** appelle le constructeur, **delete** appelle le destructeur, contrairement à **free**.

The steps of allocating and constructing are separate because sometimes you want to separate allocation / construction or destruction / deallocation (into two steps).

La STL utilise par défaut **std::allocator**.

On recode notre propre classe allocator lorsque lorsque l'on a des besoins spécifiques lors du développement de nos propres containers.

- T\* allocate(size_t n) : malloc memroy size and return begin address. "n" is number of T object
- void deallocate(T\* begin, size_t n) : deallocate memory. "n" has to be same as the "n" which is used for allocate
- void construct(T\* pos, const T& ele) : put "ele" into "pos" which is uninitialized memory space.
- void destroy(T\* pos) : call destructor of ele located in "pos".

Plus d'infos sur cette [page](https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c/31358990).

Documentation de std::allocator sur cette [page](https://en.cppreference.com/w/cpp/memory/allocator)
