#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate( Point & );
public:
    Point( void ) : m_i(0) {}
    void PrintPrivate( void ){cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate ( Point &i ) { i.m_i++; }

int main()
{
   Point sPoint;
   sPoint.PrintPrivate();
   ChangePrivate(sPoint);
   sPoint.PrintPrivate();
}

/*

If a function is defined as a friend function then, the private and protected data of a class can be accessed using the function.
The complier knows a given function is a friend function by the use of the keyword friend.
For accessing the data, the declaration of a friend function should be made inside the body of the class

Similarly, like a friend function, a class can also be made a friend of another class using keyword friend. For example

class B;

class A
{
   // class B is a friend class of class A
   friend class B;
   ... .. ...
}

class B
{
   ... .. ...
}

*/

/* C++ program to demonstrate the working of friend function.*/
#include <iostream>
using namespace std;

class Distance
{
    private:
        int meter;
    public:
        Distance(): meter(0) { }
        //friend function
        friend int addFive(Distance);
};

// friend function definition
int addFive(Distance d)
{
    //accessing private data from non-member function
    d.meter += 5;
    return d.meter;
}

int main()
{
    Distance D;
    cout<<"Distance: "<< addFive(D);
    return 0;
}
