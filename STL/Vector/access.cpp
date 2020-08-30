// vector::operator[]
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (10);   // 10 zero-initialized elements

  std::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i]; // technique reverse à réutiliser
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

// -------------------------------------------------------

  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

// -------------------------------------------------------

std::vector<int> myvector5;
  myvector5.push_back(78);
  myvector5.push_back(16);
  // now front equals 78, and back 16
  myvector5.front() -= myvector5.back();
  std::cout << "myvector.front() is now " << myvector5.front() << '\n';

// ---------------------------

std::vector<int> myvector6;

  myvector6.push_back(10);
  std::cout << int(myvector6.size()) << std::endl;

  while (myvector6.back() != 0) // iteration chelou mais à retenir
  {
    myvector6.push_back ( myvector6.back() -1 );
      std::cout << "A" << std::endl;
  }
    std::cout << myvector6.size() << std::endl;


  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector6.size() ; i++)
    std::cout << ' ' << myvector6[i];
  std::cout << '\n';


  return 0;
}