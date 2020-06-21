#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

/* Fonctionne avec les 5 types d'itérateurs */

// input_iterator_tag	Input Iterator
// output_iterator_tag	Output Iterator
// forward_iterator_tag	Forward Iterator
// bidirectional_iterator_tag	Bidirectional Iterator
// random_access_iterator_tag	Random-access Iterator

class MyIterator : public std::iterator<std::random_access_iterator_tag /* <-- Remplacer ici */, int>
{
	int* p;

	public:
	  MyIterator(int* x) :p(x) {}
	  MyIterator(const MyIterator& mit) : p(mit.p) {}
	  MyIterator& operator++() {++p;return *this;}
	  MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
	  bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
	  bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
	  int& operator*() {return *p;}

};

int main () {

	int numbers[]={10,20,30,40,50};
	MyIterator from(numbers);
	MyIterator until(numbers+5);
	for (MyIterator it=from; it!=until; it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	return 0;
}
