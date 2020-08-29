// list::begin
#include <iostream>
#include <list>

int main ()
{
  int myints[] = {75,23,65,42,13};
  std::list<int> mylist (myints,myints+5);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
  std::cout << '\n';
  std::cout << '\n';

  std::list<int> mylist2;
  for (int i=1; i<=5; ++i) mylist2.push_back(i);

  std::cout << "mylist2 backwards:";
  for (std::list<int>::reverse_iterator rit=mylist2.rbegin(); rit!=mylist2.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}