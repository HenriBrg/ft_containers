/* Typename - Typedef - Template */

struct X { typedef int       foo;       };
struct Y { static  int const foo = 123; };


int main() {

	/* (C) --> */ f_tmpl<X> ();
 	/* (D) --> */ f_tmpl<Y> ();
	template<class T> void f_tmpl () { T::foo * x; /* <-- (A) */ }

}
