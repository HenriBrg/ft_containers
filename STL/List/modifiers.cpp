// list::assign
#include <iostream>
#include <vector>

#include <list>

int main ()
{

    // ------------------- assign

  std::list<int> first;
  std::list<int> second;

  first.assign (7,100);                      // 7 ints with value 100

  second.assign (first.begin(),first.end()); // a copy of first

  int myints[]={1776,7,4};
  first.assign (myints,myints+3);            // assigning from array

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  
  
// ------------------- push back & pop front


std::list<int> mylist;
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  std::cout << "Popping out the elements in mylist:";
  while (!mylist.empty())
  {
    std::cout << ' ' << mylist.front();
    
    if (rand() % 2)
        mylist.pop_front();
    else 
     mylist.pop_back();
  }

  std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';



// ------------------- insert

std::list<int> mylist2;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist2.push_back(i); // 1 2 3 4 5

  it = mylist2.begin();
  ++it;       // it points now to number 2           ^

  mylist2.insert (it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist2.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

  --it;       // it points now to the second 20            ^

  std::vector<int> myvector (2,30);
  mylist2.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  // ---------------------------- erase


  std::list<int> mylist4;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist4.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist4.begin();// ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist4.erase (it1);   // 10 30 40 50 60 70 80 90
                               //    ^           ^

  it2 = mylist4.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist4.erase (it1,it2);     // 10 30 60 80 90
                               //        ^

  std::cout << "mylist4 contains:";
  for (it1=mylist4.begin(); it1!=mylist4.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';


  return 0;
}