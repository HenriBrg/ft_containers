// list::empty
#include <iostream>
#include <list>

int main ()
{

    // ---------------------------------------------

  std::list<int> mylist;
  int sum (0);

  for (int i=1;i<=10;++i) mylist.push_back(i);

  while (!mylist.empty())
  {
     sum += mylist.front();
     mylist.pop_front();
  }

  std::cout << "total: " << sum << '\n';

  std::cout << "size: " << mylist.size() << '\n';

// ---------------------------------------------

std::list<int> mylist2;

  mylist2.push_back(77);
  mylist2.push_back(22);

  // now front equals 77, and back 22

  mylist2.front() -= mylist2.back();

  std::cout << "mylist.front() is now " << mylist2.front() << '\n';


// ---------------------------------------------

std::list<int> first (3,100);   // three ints with a value of 100
  std::list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  std::cout << "first contains:";
  for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';


// ---------------------------------------------


 std::list<int> mylist3;

  // set some initial content:
  for (int i=1; i<10; ++i) mylist3.push_back(i);

  mylist3.resize(5);
  std::cout << mylist3.size() << std::endl;
  mylist3.resize(8,100);
    std::cout << mylist3.size() << std::endl;
  mylist3.resize(12);
  std::cout << mylist3.size() << std::endl;

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist3.begin(); it!=mylist3.end(); ++it)
    std::cout << ' ' << *it;
    mylist3.clear();
      std::cout << "\n--> " << mylist3.size() << std::endl;

  std::cout << '\n';


  return 0;
}