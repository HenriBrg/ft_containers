#include <iostream>
#include <string>

using namespace std;

class Person{

	public:

	    string name;

		    class Address{
		    public:
		        string country;
		        string stname;
		        int hno;

		    };

	    Address addr;
	    void AddressPlease(){
	    cout<< name <<endl << addr.country <<endl <<addr.stname << endl <<addr.hno <<endl;
	    }
		
};


int main()
{
    Person :: Address ad;
    Person anil;
    anil.name = "anil";
    anil.addr.country = "India";
    anil.addr.stname = "madamakki";
    anil.addr.hno = 68;

    anil.AddressPlease();
    return 0;
}
