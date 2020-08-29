// erasing from map
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

    std::cout << mymap.size() << std::endl;
  mymap.erase ('c');                  // erasing by key
    std::cout << mymap.size() << std::endl;

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range
    std::cout << mymap.size() << std::endl;

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}