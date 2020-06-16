# include <iostream>
# include <string>

class Hello {

	public:
		Hello() { std::cout << "Constructor" << std::endl; }
		std::string getN() { return name; }
		void setN(std::string param) { name = param; }

	private:
		std::string name;
};

int main() {

	Hello *foo = static_cast<Hello*>(::operator new(sizeof(Hello) * 3));

	std::cout << foo[0].getN() << std::endl;

	foo[0].setN("World");

	std::cout << foo[0].getN() << std::endl;

	::operator delete(foo);

	// system("leaks a.out");
}
