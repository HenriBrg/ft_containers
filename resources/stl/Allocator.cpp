#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {

	vector<int> vec(5);
	for (int i = 0; i < vec.size(); i++)
		vec[i] = i;

	cout << "--- 1) ::allocator_type ---" << endl;

	vector<int>::allocator_type at1;
	cout << typeid(at1).name() << endl;
	vector<double>::allocator_type at2;
	cout << typeid(at2).name() << endl;

	at1.allocate(10);
	cout << at1.max_size() << endl;


	typedef vector<int>::allocator_type viat;
	/* typename word isn't required since we are not inside any template */

	viat::pointer ptr;
	int a[] = {1, 2};
	cout << typeid(ptr).name() << endl;
	ptr = a;
	int b = 1;
	ptr = &b;

	viat::reference ref(b);
	viat::difference_type diff;
	diff = vec[1] - vec[2]; // valeur, simple soustraction
	cout << "diff = " << diff << endl;
	diff = vec.end() - vec.begin(); // index, soustraction des index des iérateurs
	cout << "diff = " << diff << endl;



	std::allocator<int> alloc;
	int* arr = alloc.allocate(10);
	alloc.construct(arr, 100);
	arr[3] = 10;
	alloc.deallocate(arr, 5);

	std::cout << alloc.address(5) << std::endl;
	std::cout << "--------type-------" << std::endl;

	std::cout << typeid(alloc.address(5)).name() << std::endl;
	std::cout << typeid(arr).name() << std::endl;
	std::cout << typeid(alloc).name() << std::endl;
	typedef vector<int>::allocator_type xxx;
	xxx myvar;
	std::cout << typeid(myvar).name() << std::endl;



	std::allocator<int*> gf;
	int **dd = gf.allocate(2);



}
