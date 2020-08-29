// splicing lists
#include <iostream>
#include <list>


bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};


int main ()
{

    // ---------- SPLICE

// The first version (1) transfers all the elements of x into the container.
// The second version (2) transfers only the element pointed by i from x into the container.
// The third version (3) transfers the range [first,last) from x into the container.


  std::list<int> mylist1, mylist2;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                          
  mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
  it = mylist1.begin();
  std::advance(it,3);           // "it" points now to 30

  mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

  std::cout << "mylist1 contains:";
  for (it=mylist1.begin(); it!=mylist1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';


    // ------------------ remove

    int myints[]= {17,89,7,14};
  std::list<int> mylist3 (myints,myints+4);

  mylist3.remove(89);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist3.begin(); it!=mylist3.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // ---------------------------- remove if 

  int myintsSSS[]= {15,36,7,17,20,39,4,1};
  std::list<int> mylist5 (myintsSSS,myintsSSS+8);   // 15 36 7 17 20 39 4 1

  mylist5.remove_if (single_digit);           // 15 36 17 20 39

  mylist5.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist5.begin(); it!=mylist5.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}