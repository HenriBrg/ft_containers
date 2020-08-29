#include <iostream>
#include <list>
#include <string>
#include <cctype>

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main ()
{
  std::list<std::string> mylist;
  std::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // reverse 

  std::list<int> mylist2;

  for (int i=1; i<10; ++i) mylist2.push_back(i);

  mylist2.reverse();

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}