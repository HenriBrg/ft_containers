// map::begin/end
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  std::map<char,int>::iterator it;
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

std::cout << std::endl << std::endl;
*it--;
std::cout << it->first << " => " << it->second << '\n';
it--;
std::cout << it->first << " => " << it->second << '\n';
std::cout << std::endl << std::endl;

std::map<char,int>::reverse_iterator rit;
 for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';


  return 0;
}