#include <vector>
#include "includes/Vector.hpp"
#include "../../Tester/Tester.hpp"

// ------------------------------------------------------------------------

/*
** Summary
** PROTOTYPES
** MACROS
** CONSTANTS
** TESTS
*/

/*
** TODO
** ok all
*/

// ------------------------------------------------------------------------

/*
** PROTOTYPES
*/

/*
** MACROS
*/

#define PRINT(content, LOG) if (LOG) (std::cout << content << std::endl)
int test_id = 1;
#define PRINT_MAGENTA(content, LOG) if (LOG) (std::cout << MAGENTA_C << content << RESET << std::endl);
#define PRINT_BLUE(content, LOG) if (LOG) (std::cout << BLUE_C << test_id++ << " - " << content << RESET << std::endl);
#define PRINT_RED(content, LOG) if (LOG) (std::cout << RED_C << content << RESET << std::endl);
#define DISPLAY_VECTOR(v, name, LOG) display_vector(v, name, LOG)

/*
** CONSTANTES
*/

#define DEBUG_CONSTRUCTORS        1
#define DEBUG_DESTRUCTORS         1
#define DEBUG_ELEMENT_ACCESS      1
#define DEBUG_ITERATORS           1
#define DEBUG_CAPACITY            1
#define DEBUG_MODIFIERS			  1
#define DEBUG_NON_MEMBER          1

/*
** TESTS
*/

void test_constructors(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("*** VECTOR Constructors\n", DEBUG_CONSTRUCTORS && 1);

    // ------------------------------------------------------------------------
    // default
    PRINT_BLUE("default:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Vector<int> ft_v1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Vector<int> ft_v1;
    DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::vector<int> std_v1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::vector<int> std_v1;
    DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    assert_vector_equals(std_v1, ft_v1, "constructor - default");
    // ------------------------------------------------------------------------

 	// ------------------------------------------------------------------------
    // fill
    PRINT_BLUE("fill:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    // ---
    PRINT("ft::Vector<int> ft_v2(5, 2);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Vector<int> ft_v2(5, 2);
    DISPLAY_VECTOR(ft_v2, "ft_v2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::vector<int> std_v2(5, 2);", DEBUG_CONSTRUCTORS && VERBOSE);
    std::vector<int> std_v2(5, 2);
    DISPLAY_VECTOR(std_v2, "std_v2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    assert_vector_equals(std_v2, ft_v2, "constructor fill");
    // ------------------------------------------------------------------------

 	// ------------------------------------------------------------------------
    // range
    PRINT_BLUE("range:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    // ---
    PRINT("ft::Vector<int> ft_v3(ft_v2.begin(), ft_v2.end());", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Vector<int> ft_v3(ft_v2.begin(), ft_v2.end());
    DISPLAY_VECTOR(ft_v3, "ft_v3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::vector<int> std_v3(std_v2.begin(), std_v2.end());", DEBUG_CONSTRUCTORS && VERBOSE);
    std::vector<int> std_v3(std_v2.begin(), std_v2.end());
    DISPLAY_VECTOR(std_v3, "std_v3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    assert_vector_equals(std_v3, ft_v3, "constructor range");
    // ------------------------------------------------------------------------

 	// ------------------------------------------------------------------------
    // copy
    PRINT_BLUE("copy:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    // ---
    PRINT("ft::Vector<int> ft_v4(ft_v3);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Vector<int> ft_v4(ft_v3);
    DISPLAY_VECTOR(ft_v4, "ft_v4", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::vector<int> std_v4(std_v3);", DEBUG_CONSTRUCTORS && VERBOSE);
    std::vector<int> std_v4(std_v3);
    DISPLAY_VECTOR(std_v4, "std_v4", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    assert_vector_equals(std_v4, ft_v4, "constructor copy");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // assignation
    PRINT_BLUE("assignation:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	ft_v1.push_back(1);
	ft_v1.push_back(2);
	std_v1.push_back(1);
	std_v1.push_back(2);
    // ---
    PRINT("ft::Vector<int> ft_v5 = ft_v4;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Vector<int> ft_v5 = ft_v4;
    DISPLAY_VECTOR(ft_v5, "ft_v5", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::vector<int> std_v5 = std_v4;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::vector<int> std_v5 = std_v4;
    DISPLAY_VECTOR(std_v5, "std_v5", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    assert_vector_equals(std_v5, ft_v5, "constructor assignation");
    // ------------------------------------------------------------------------
}

void test_element_access(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("*** VECTOR Element access\n", DEBUG_ELEMENT_ACCESS && 1);

    // ------------------------------------------------------------------------
    // at()
	PRINT_BLUE("at():", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    ft::Vector<int> ft_v1;
	ft_v1.push_back(1);
	ft_v1.push_back(2);
    std::vector<int> std_v1;
	std_v1.push_back(1);
	std_v1.push_back(2);
    // ---
    DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_v1.at(1)", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_v1.at(1), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std_v1.at(1)", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_v1.at(1), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    assert_value_equals(std_v1.at(1), ft_v1.at(1), "at()");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // front
	PRINT_BLUE("front():", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    // ---
    DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_v1.front()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_v1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std_v1.front()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_v1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    assert_value_equals(std_v1.front(), ft_v1.front(), "front");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // back
	PRINT_BLUE("back():", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    // ---
    DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_v1.back()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_v1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std_v1.back()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_v1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    assert_value_equals(std_v1.back(), ft_v1.back(), "back");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // operator[]
	PRINT_BLUE("operator[]:", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    // ---
    PRINT("ft_v1[1]", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_v1[1], DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_v1[1] = 8", DEBUG_ELEMENT_ACCESS && VERBOSE);
	ft_v1[1] = 8;
    DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    PRINT("std_v1[1]", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_v1[1], DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std_v1[1] = 8", DEBUG_ELEMENT_ACCESS && VERBOSE);
	std_v1[1] = 8;
    DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    assert_value_equals(std_v1[1], ft_v1[1], "operator[]");
    // ------------------------------------------------------------------------}
}

void test_capacity(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("*** VECTOR Capacity\n", DEBUG_CAPACITY && 1);

	ft::Vector<int> ft_v1;
	std::vector<int> std_v1;
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_v1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_v1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.empty(), ft_v1.empty(), "empty if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	// DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_v1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_v1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.size(), ft_v1.size(), "size if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// max_size
	PRINT_BLUE("max_size if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	// DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_v1.max_size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.max_size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_v1.max_size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.max_size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// assert_value_equals(std_v1.max_size(), ft_v1.max_size(), "max_size if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// capacity
	PRINT_BLUE("capacity if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	// DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_v1.capacity()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_v1.capacity()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.capacity(), ft_v1.capacity(), "capacity if empty");
	// ------------------------------------------------------------------------

	ft_v1.push_back(1);
	ft_v1.push_back(2);
	DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	std_v1.push_back(1);
	std_v1.push_back(2);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);

	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	PRINT("ft_v1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	PRINT("std_v1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.empty(), ft_v1.empty(), "empty if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	// DISPLAY_VECTOR(ft_v1, "ft_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_v1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_v1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.size(), ft_v1.size(), "size if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// max_size
	PRINT_BLUE("max_size if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	PRINT("ft_v1.max_size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.max_size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	PRINT("std_v1.max_size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.max_size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	// assert_value_equals(std_v1.max_size(), ft_v1.max_size(), "max_size if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// reserve
	PRINT_BLUE("reserve if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	PRINT("ft_v1.reserve(100)", DEBUG_CAPACITY && VERBOSE);
	ft_v1.reserve(100);
	PRINT("ft_v1.capacity():", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	PRINT("std_v1.reserve(100)", DEBUG_CAPACITY && VERBOSE);
	std_v1.reserve(100);
	PRINT("std_v1.capacity();", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.capacity(), ft_v1.capacity(), "reserve if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// capacity
	PRINT_BLUE("capacity if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	PRINT("ft_v1.capacity()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	PRINT("std_v1.capacity()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_v1.capacity(), DEBUG_CAPACITY && VERBOSE);
	// ---
	assert_value_equals(std_v1.capacity(), ft_v1.capacity(), "capacity if not empty");
	// ------------------------------------------------------------------------
}

void test_modifiers(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("\n\n*** VECTOR Modifiers\n", DEBUG_MODIFIERS && 1);

	// ------------------------------------------------------------------------
	// insert
	PRINT_BLUE("insert", DEBUG_MODIFIERS && VERBOSE);
	// ---
	ft::Vector<int> ft_v1;
   	ft_v1.push_back(0);
   	ft_v1.insert(ft_v1.begin(), 1);
   	ft_v1.insert(ft_v1.begin(), 0);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);

	std::vector<int> std_v1;
   	std_v1.push_back(0);
	std_v1.insert(std_v1.begin(), 1);
	std_v1.insert(std_v1.begin(), 0);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "insert 1");
	// ---
	ft_v1.insert(ft_v1.begin(), 2, 2);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);

	std_v1.insert(std_v1.begin(), 2, 2);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "insert 2");
	// ---
	ft::Vector<int> ft_v2;
   	ft_v2.push_back(0);
   	ft_v2.insert(ft_v2.begin(), 3);
	DISPLAY_VECTOR(ft_v2, "ft_v2 ", DEBUG_MODIFIERS && VERBOSE);
	ft_v1.insert(ft_v1.begin(), ft_v2.begin(), ft_v2.end());
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);

	std::vector<int> std_v2;
   	std_v2.push_back(0);
   	std_v2.insert(std_v2.begin(), 3);
	DISPLAY_VECTOR(std_v2, "std_v2", DEBUG_MODIFIERS && VERBOSE);
	std_v1.insert(std_v1.begin(), std_v2.begin(), std_v2.end());
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "insert 3");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// insert
	PRINT_BLUE("erase", DEBUG_MODIFIERS && VERBOSE);
	// ---
   	ft_v1.erase(ft_v1.begin());
   	ft_v1.erase(ft_v1.begin());
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);

	std_v1.erase(std_v1.begin());
	std_v1.erase(std_v1.begin());
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "erase 1");
	// ---
	ft_v1.erase(ft_v1.begin(), ft_v1.end());
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);

	std_v1.erase(std_v1.begin(), std_v1.end());
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "erase 2");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// push_back
	PRINT_BLUE("push_back", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
   	ft_v1.push_back(1);
	ft_v1.push_back(2);
	ft_v1.push_back(3);
	ft_v1.push_back(4);
	ft_v1.push_back(5);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	std_v1.push_back(1);
	std_v1.push_back(2);
	std_v1.push_back(3);
	std_v1.push_back(4);
	std_v1.push_back(5);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "push_back");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// pop_back
	PRINT_BLUE("pop_back", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	ft_v1.pop_back();
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	std_v1.pop_back();
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "pop_back");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// resize
	PRINT_BLUE("resize", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
   	ft_v1.resize(3, 9);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
   	ft_v1.resize(5, 9);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	std_v1.resize(3, 9);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	std_v1.resize(5, 9);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "resize");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// swap
	PRINT_BLUE("swap", DEBUG_MODIFIERS && VERBOSE);
	// ---
	ft::Vector<int> ft_v3;
	std::vector<int> std_v3;

	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
   	ft_v3.swap(ft_v1);
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	DISPLAY_VECTOR(ft_v3, "ft_v3 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	std_v3.swap(std_v1);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	DISPLAY_VECTOR(std_v3, "std_v3", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "swap");
	assert_vector_equals(std_v3, ft_v3, "swap");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// clear if not empty
	PRINT_BLUE("clear if not empty", DEBUG_MODIFIERS && VERBOSE);
	// ---
   	ft_v1.clear();
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	std_v1.clear();
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "clear if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// clear
	PRINT_BLUE("clear if already empty", DEBUG_MODIFIERS && VERBOSE);
	// ---
   	ft_v1.clear();
	DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_MODIFIERS && VERBOSE);
	// ---
	std_v1.clear();
	PRINT("std segfault", DEBUG_MODIFIERS && VERBOSE);
	DISPLAY_VECTOR(std_v1, "std_v1", DEBUG_MODIFIERS && VERBOSE);
	// ---
	assert_vector_equals(std_v1, ft_v1, "clear if already empty");
	// ------------------------------------------------------------------------

}

void test_non_member_functions(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** VECTOR Non member functions\n", DEBUG_NON_MEMBER && 1);

    ft::Vector<int> ft_v1;
	ft_v1.push_back(1);
	ft_v1.push_back(2);
    DISPLAY_VECTOR(ft_v1, "ft_v1 ", DEBUG_NON_MEMBER && VERBOSE);
    ft::Vector<int> ft_v2;
	ft_v2.push_back(1);
	ft_v2.push_back(2);
	// ft_v2.push_back(9);
    DISPLAY_VECTOR(ft_v2, "ft_v2 ", DEBUG_NON_MEMBER && VERBOSE);

    std::vector<int> std_v1;
	std_v1.push_back(1);
	std_v1.push_back(2);
    DISPLAY_VECTOR(std_v1, "std_v1 ", DEBUG_NON_MEMBER && VERBOSE);
    std::vector<int> std_v2;
	std_v2.push_back(1);
	std_v2.push_back(2);
	// std_v2.push_back(9);
    DISPLAY_VECTOR(std_v2, "std_v2 ", DEBUG_NON_MEMBER && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty vector
    // ---
    PRINT_BLUE("==", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v1 == std_v2), (ft_v1 == ft_v2), "== not empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty vector
    // ---
    PRINT_BLUE("!=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v1 != std_v2), (ft_v1 != ft_v2), "!= not empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty vector
    // ---
    PRINT_BLUE("<", DEBUG_NON_MEMBER && VERBOSE);
    // ---
	// PRINT("ft_v1.size();", DEBUG_NON_MEMBER && VERBOSE);
	// PRINT(ft_v1.size(), DEBUG_NON_MEMBER && VERBOSE);
	// PRINT("ft_v2.size();", DEBUG_NON_MEMBER && VERBOSE);
	// PRINT(ft_v2.size(), DEBUG_NON_MEMBER && VERBOSE);
	// PRINT((ft_v1 < ft_v2), DEBUG_NON_MEMBER && VERBOSE);

	// PRINT("std_v1.size();", DEBUG_NON_MEMBER && VERBOSE);
	// PRINT(std_v1.size(), DEBUG_NON_MEMBER && VERBOSE);
	// PRINT("std_v2.size();", DEBUG_NON_MEMBER && VERBOSE);
	// PRINT(std_v2.size(), DEBUG_NON_MEMBER && VERBOSE);
	// PRINT((std_v1 < std_v2), DEBUG_NON_MEMBER && VERBOSE);

    assert_value_equals((std_v1 < std_v2), (ft_v1 < ft_v2), "< not empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty vector
    // ---
    PRINT_BLUE("<=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v1 <= std_v2), (ft_v1 <= ft_v2), "<= not empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty vector
    // ---
    PRINT_BLUE(">", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v1 > std_v2), (ft_v1 > ft_v2), "> not empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty vector
    // ---
    PRINT_BLUE(">=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v1 >= std_v2), (ft_v1 >= ft_v2), ">= not empty vector");
    // ------------------------------------------------------------------------

    ft::Vector<int> ft_v3;
    ft::Vector<int> ft_v4;
    DISPLAY_VECTOR(ft_v3, "ft_v3 ", DEBUG_NON_MEMBER && VERBOSE);
    DISPLAY_VECTOR(ft_v4, "ft_v4 ", DEBUG_NON_MEMBER && VERBOSE);

    std::vector<int> std_v3;
    std::vector<int> std_v4;
    DISPLAY_VECTOR(std_v3, "std_v3", DEBUG_NON_MEMBER && VERBOSE);
    DISPLAY_VECTOR(std_v4, "std_v4", DEBUG_NON_MEMBER && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty vector
    // ---
    PRINT_BLUE("==", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 == std_v4), (ft_v3 == ft_v4), "== if empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty vector
    // ---
    PRINT_BLUE("!=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 != std_v4), (ft_v3 != ft_v4), "!= if empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty vector
    // ---
    PRINT_BLUE("<", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 < std_v4), (ft_v3 < ft_v4), "< if empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty vector
    // ---
    PRINT_BLUE("<=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 <= std_v4), (ft_v3 <= ft_v4), "<= if empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty vector
    // ---
    PRINT_BLUE(">", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 > std_v4), (ft_v3 > ft_v4), "> if empty vector");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty vector
    // ---
    PRINT_BLUE(">=", DEBUG_NON_MEMBER && VERBOSE);
    // ---
    assert_value_equals((std_v3 >= std_v4), (ft_v3 >= ft_v4), ">= if empty vector");
    // ------------------------------------------------------------------------
}

int main()
{
    test_constructors();
    test_element_access();
    test_capacity();
    test_modifiers();
    test_non_member_functions();
    return (0);
}
