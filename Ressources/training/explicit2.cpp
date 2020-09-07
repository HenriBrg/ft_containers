#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {
		cout << "Hello" << endl;
	}

    // A method to compare two Complex numbers
    bool operator== (Complex rhs) {
       return (real == rhs.real && imag == rhs.imag)? true : false;
    }
};

int main()
{
    // a Complex object
    Complex com1(3.0, 0.0);

	/* We could also cast with : Complex(3.0) */

	/* FOR COMPARAISON HERE, THE CONSTRUCTOR IS CALLED ! That's the problem */
    if (com1 == static_cast<Complex>(3.0)) // Without cast, it doesnt compile
       cout << "Same";
    else
       cout << "Not Same";
     return 0;
}
