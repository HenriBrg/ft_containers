// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{

  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

// ------------------------------- rbegin

 std::vector<int> myvector2 (5);  // 5 default-constructed ints

  int j=0;

  std::vector<int>::reverse_iterator ritx = myvector2.rbegin();
  for (; ritx!= myvector2.rend(); ++ritx)
    *ritx = ++j;
    std::cout << "myvector contains:";
  for (std::vector<int>::iterator itc = myvector2.begin(); itc != myvector2.end(); ++itc)
    std::cout << ' ' << *itc;
  std::cout << '\n';

// ------- rend

std::vector<int> myvec3 (5);  // 5 default-constructed ints
  std::vector<int>::reverse_iterator rit = myvec3.rbegin();

  int i=0;
  for (rit = myvec3.rbegin(); rit!= myvec3.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvec3 contains:";
  for (std::vector<int>::iterator it = myvec3.begin(); it != myvec3.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}