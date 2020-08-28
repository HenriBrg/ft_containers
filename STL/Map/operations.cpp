// map::find
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  std::cout << mymap.size() << '\n';
  if (it != mymap.end())
    mymap.erase (it);
  std::cout << mymap.size() << '\n';

  // print content:

  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';


std::cout << std::endl << "--------------------------" << std::endl << std::endl;
    char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'d'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }


std::cout << std::endl << "--------------------------" << std::endl << std::endl;

std::map<char,int> mymap2;
  std::map<char,int>::iterator itlow,itup;

  mymap2['a']=20;
  mymap2['b']=40;
  mymap2['c']=60;
  mymap2['d']=80;
  mymap2['e']=100;

  itlow=mymap2.lower_bound ('b');  // itlow points to b
  itup=mymap2.upper_bound ('d');   // itup points to e (not d!)

  mymap2.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap2.begin(); it!=mymap2.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';


std::cout << std::endl << "--------------------------" << std::endl << std::endl;

 std::map<char,int> mymap3;

  mymap3['a']=10;
  mymap3['b']=20;
  mymap3['c']=30;
  mymap3['d']=40;
  mymap3['e']=50;

    typedef std::map<char, int>::iterator xx;

  std::pair<xx, xx> ret;
  ret = mymap3.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';


  return 0;
}