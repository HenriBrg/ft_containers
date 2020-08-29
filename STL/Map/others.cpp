// map::empty
#include <iostream>
#include <map>

int main ()
{

        
  std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
    mymap['a']=10;
  mymap['b']=20;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
    std::cout << mymap.max_size() << std::endl;

// ---------------------

 std::map<char,std::string> mymap2;

  mymap2['a']="an element";
  mymap2['b']="another element";
  mymap2['c']=mymap2['b'];

  std::cout << "mymap2['a'] is " << mymap2['a'] << '\n';
  std::cout << "mymap2['b'] is " << mymap2['b'] << '\n';
  std::cout << "mymap2['c'] is " << mymap2['c'] << '\n';
  std::cout << "mymap2 now contains " << mymap2.size() << " elements.\n";
  std::cout << "mymap2['d'] is " << mymap2['d'] << '\n';
  std::cout << "mymap2 now contains " << mymap2.size() << " elements.\n";




// ---------------------

std::map<char,int> mymap3;

  std::map<char,int>::key_compare mycomp = mymap3.key_comp();

  mymap3['a']=100;
  mymap3['b']=200;
  mymap3['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap3.rbegin()->first;     // key value of last element

std::cout << " highest => " << highest << std::endl;
highest = 'b';


  std::map<char,int>::iterator it = mymap3.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';


// ---------------------
  std::cout << "\n\n\n";

  std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  foo.clear();
  bar.clear();
  return 0;
}