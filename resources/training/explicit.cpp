/* Conversion constructors and non-explicit conversion functions may introduce ambiguity */
/* Le mot clé explicit interdit au constructeur de faire une conversion implicite potentiellement toxique */
/*
	Remember :

		A a;       // default constructor
		A b(a);    // copy constructor since a is type of A
		A c = a;   // copy constructor
		c = b;     // operator =

*/

# include <iostream>

class myClass {
	public:
	 	explicit myClass(int n) {std::cout << "int n" << std::endl;}; // allocate n bytes to the myClass object
		myClass(const char *p) {std::cout << "char p" << std::endl;}; // initializes object with char *p
};

int main() {
	myClass a(1); // Call int n constructor
	myClass b('c'); // Call int n constructor
	myClass mystring = 'x'; // Call int n constructor

	// myClass mystring = 'x'; // <------- COMPILATION ERROR if the constructor is explicit
	/* The character 'x' will be implicitly converted to int and then the String(int) constructor will be called.
	But, this is not what the user might have intended. So, to prevent such conditions, we shall define the constructor as explicit */
	/* You can only assign values that match the values of the class type */
 }
