#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {

	vector<int> vec(5);
	vector<int>::iterator it;
	vector<int>::iterator it2;
	vector<int>::iterator it3;

	for (int i = 0; i < vec.size(); i++)
		vec[i] = i * 2;

	/* 1) */
	cout << "--- 1) iterator operators ---" << endl;
	it = vec.begin();
	cout << *it << endl;
	cout << *(it + 1) << endl;
	cout << *(it + 3) << endl;

	it2 = it;
	cout << *it2 << endl;
	it++;
	cout << *it << endl;
	it2 += 2; /* Same as += *it */
	cout << *it2 << endl;

	/* 2) */
	cout << "--- 2) ::value_type and ::iterator::value_type ---" << endl;

	vector<int>::value_type a;
	cout << typeid(a).name() << endl;
	vector<double>::value_type b;
	cout << typeid(b).name() << endl;

	vector<int>::iterator::value_type iti;
	cout << typeid(iti).name() << endl;
	vector<float>::iterator::value_type itf;
	cout << typeid(itf).name() << endl;

	std::cout << "a = " << a << endl;
	iti = 77;
	a = iti;
	std::cout << "a = " << a << endl;


	/* 3) */
	cout << "--- 3) ::pointer ::reference ---" << endl;

	vector<int>::pointer r;
	int foo [] = { 16, 2, 77, 40, 12071 };
	vector<int>::pointer tabint_ptr;
	tabint_ptr = foo;
	cout << typeid(tabint_ptr).name() << endl;

	int tmp = 3;
	vector<int>::reference tabint_ref(tmp);
	cout << tabint_ref << endl;

	typename allocator<int>::reference test(tmp); /* just test to call from outside of template */
	cout << "typename out of template : " << test << endl; // warning but works

	/* 4) */
	cout << "--- 4) ::difference_type ::size_type ---" << endl;
	vector<int>::difference_type diftype;
	cout << typeid(diftype).name() << endl;
	vector<int> v4(3, 5);
	diftype = distance(v4.begin(), v4.end());
	cout << "diftype = " << diftype << endl;
	vector<int>::iterator v4it1;
	vector<int>::iterator v4it2;
	v4it1 = v4.begin();
	v4it2 = v4it1 + 2;
	diftype = distance(v4it1, v4it2);
	cout << "diftype from it = " << diftype << endl;

	 vector<int>::size_type i;
	 vector<int> stypevec(3, 5);
	 i = stypevec.max_size( );
	 cout << "sizetype from = " << i << endl;
	 i = stypevec.size( );
	 cout << "sizetype from = " << i << endl;
	 i = stypevec[1] + stypevec[2]; /* 5 + 5, inutile en fait --' */
	 cout << "sizetype from = " << i << endl;

	 int aaaa = stypevec.size( );
	 cout << "sizetype = " << aaaa << endl;


}
