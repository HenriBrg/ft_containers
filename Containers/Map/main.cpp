#include <map>
#include "includes/Map.hpp"
#include "../../Tester/Tester.hpp"

// ------------------------------------------------------------------------

/*
** Summary
** PROTOTYPES
** MACROS
** CONSTANTS
** TESTS
*/

// ------------------------------------------------------------------------

/*
** PROTOTYPES
*/

/*
** MACROS
*/

#define PRINT(content, LOG) if (LOG) (std::cout << content << std::endl);
int test_id = 1;
#define PRINT_MAGENTA(content, LOG) if (LOG) (std::cout << MAGENTA_C << content << RESET << std::endl);
#define PRINT_BLUE(content, LOG) if (LOG) (std::cout << BLUE_C << test_id++ << " - " << content << RESET << std::endl);
#define PRINT_RED(content, LOG) if (LOG) (std::cout << RED_C << content << RESET << std::endl);
#define DISPLAY_MAP_FT(m, name, LOG) display_map_ft(m, name, LOG)
#define DISPLAY_MAP_STD(m, name, LOG) display_map_std(m, name, LOG)

/*
** CONSTANTES
*/

#define DEBUG_CONSTRUCTORS        1
#define DEBUG_DESTRUCTORS         1
#define DEBUG_ELEMENT_ACCESS      1
#define DEBUG_ITERATORS           1
#define DEBUG_CAPACITY            1
#define DEBUG_MEMBER_FUNCTIONS    1
#define DEBUG_LOOKUP_FUNCTIONS    1
#define DEBUG_OPERATIONS          1

/*
** TESTS
*/

void test_constructors(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** MAP Constructors\n", DEBUG_CONSTRUCTORS && 1);

    // ------------------------------------------------------------------------
    // default
    PRINT_BLUE("default:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Map<int, std::string> ft_m1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Map<int, std::string> ft_m1;
    DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    PRINT("std::map<int, std::string> std_m1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::map<int, std::string> std_m1;
    DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_map_equals(std_m1, ft_m1, "constructor - default");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // copy
    PRINT_BLUE("copy:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    ft_m1.insert(std::make_pair(1, "1"));
    std_m1.insert(std::make_pair(1, "1"));
    ft_m1.insert(std::make_pair(2, "2"));
    std_m1.insert(std::make_pair(2, "2"));
    ft_m1.insert(std::make_pair(3, "3"));
    std_m1.insert(std::make_pair(3, "3"));
    // // ft_m1.display();
    DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Map<int, std::string> ft_m2(ft_m1);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Map<int, std::string> ft_m2(ft_m1);
    DISPLAY_MAP_FT(ft_m2, "ft_m2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::map<int, std::string> std_m2(std_m1);", DEBUG_CONSTRUCTORS && VERBOSE);
    std::map<int, std::string> std_m2(std_m1);
    DISPLAY_MAP_STD(std_m2, "std_m2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_map_equals(std_m2, ft_m2, "constructor - copy");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // assignation
    PRINT_BLUE("assignation:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    // ---
    PRINT("ft::Map<int, std::string> ft_m3 = ft_m1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Map<int, std::string> ft_m3 = ft_m1;
    DISPLAY_MAP_FT(ft_m3, "ft_m3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::map<int, std::string> std_m3 = std_m1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::map<int, std::string> std_m3 = std_m1;
    DISPLAY_MAP_STD(std_m3, "std_m3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_map_equals(std_m3, ft_m3, "constructor - assignation");
    // ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
    // range
    PRINT_BLUE("range:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    // ---
    PRINT("ft::Map<int, std::string> ft_m4(ft_m3.begin(), ft_m3.end());", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Map<int, std::string> ft_m4(ft_m3.begin(), ft_m3.end());
    DISPLAY_MAP_FT(ft_m4, "ft_m4", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::map<int, std::string> std_m4(std_m3.begin(), std_m3.end());", DEBUG_CONSTRUCTORS && VERBOSE);
    std::map<int, std::string> std_m4(std_m3.begin(), std_m3.end());
    DISPLAY_MAP_STD(std_m4, "std_m4", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_map_equals(std_m4, ft_m4, "constructor - range");
    // ------------------------------------------------------------------------
	
}

void test_element_access(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** MAP Element access\n", DEBUG_ELEMENT_ACCESS && 1);

    // ------------------------------------------------------------------------
    // []
	PRINT_BLUE("[] if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    ft::Map<int, std::string> ft_m1;
    ft_m1.insert(std::make_pair(1, "1"));
    ft_m1.insert(std::make_pair(2, "2"));
    ft_m1.insert(std::make_pair(3, "3"));
    std::map<int, std::string> std_m1;
    std_m1.insert(std::make_pair(1, "1"));
    std_m1.insert(std::make_pair(2, "2"));
    std_m1.insert(std::make_pair(3, "3"));
    // ---
    DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT("ft_m1[1] = ", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_m1[1], DEBUG_ELEMENT_ACCESS && VERBOSE);

    ft_m1[1] = "a";
    ft_m1[4] = "d";
    ft_m1[5];
    
    DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT("std[1] = ", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_m1[1], DEBUG_ELEMENT_ACCESS && VERBOSE);

    std_m1[1] = "a";
    std_m1[4] = "d";
    std_m1[5];

    DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_value_equals(ft_m1[5], std_m1[5], "[] - if not empty");
    // ------------------------------------------------------------------------
}

void test_capacity(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }
	
	PRINT_MAGENTA("*** MAP Capacity\n", DEBUG_ELEMENT_ACCESS && 1);

	ft::Map<int, std::string> ft_m1;
	std::map<int, std::string> std_m1;
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_m1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_m1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_m1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_m1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_m1.empty(), ft_m1.empty(), "empty 1/2 - if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	// DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_m1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_m1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_m1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_m1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_m1.size(), ft_m1.size(), "size 1/2 - if empty");
	// ------------------------------------------------------------------------

    ft_m1.insert(std::make_pair(1, "1"));
    std_m1.insert(std::make_pair(1, "1"));
    ft_m1.insert(std::make_pair(2, "2"));
    std_m1.insert(std::make_pair(2, "2"));
    ft_m1.insert(std::make_pair(3, "3"));
    std_m1.insert(std::make_pair(3, "3"));
	
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_m1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_m1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_m1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_m1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_m1.empty(), ft_m1.empty(), "empty 2/2 if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_m1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_m1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_m1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_m1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_m1.size(), ft_m1.size(), "size 2/2 - if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// max_size
	PRINT_BLUE("max_size:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	PRINT("ft_m1.max_size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_m1.max_size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	PRINT("std_m1.max_size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_m1.max_size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_m1.max_size(), ft_m1.max_size(), "max_size");
	// ------------------------------------------------------------------------

}

void test_modifiers(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("\n\n*** MAP Modifiers\n", DEBUG_MEMBER_FUNCTIONS && 1);

	// ------------------------------------------------------------------------
	// insert 1/3
	PRINT_BLUE("insert 1/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	ft::Map<int, std::string> ft_m1;
   	ft_m1.insert(std::make_pair(1, "1"));
   	ft_m1.insert(std::make_pair(2, "2"));
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std::map<int, std::string> std_m1;
   	std_m1.insert(std::make_pair(1, "1"));
   	std_m1.insert(std::make_pair(2, "2"));
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "insert 1/3");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// insert 2/3
	PRINT_BLUE("insert 2/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.insert(ft_m1.begin(), std::make_pair(3, "3"));
	// ft_m1.insert(ft_m1.begin(), std::make_pair(4, "4"));
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std_m1.insert(std_m1.begin(), std::make_pair(3, "3"));
	// std_m1.insert(std_m1.begin(), std::make_pair(4, "4"));
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "insert 2/3");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// insert 3/3
	PRINT_BLUE("insert 3/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
    ft::Map<int, std::string> ft_m2;
   	ft_m2.insert(std::make_pair(4, "4"));
   	ft_m2.insert(std::make_pair(5, "5"));
	// ---
   	ft_m1.insert(ft_m2.begin(), ft_m2.end());
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std::map<int, std::string> std_m2;
   	std_m2.insert(std::make_pair(4, "4"));
   	std_m2.insert(std::make_pair(5, "5"));
	// ---
   	std_m1.insert(std_m2.begin(), std_m2.end());
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "insert 3/3");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// erase 1/3
	PRINT_BLUE("erase 1/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.erase(++ft_m1.begin());
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
   	std_m1.erase(++std_m1.begin());
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "insert");
	// ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
	// erase 2/3
	PRINT_BLUE("erase 2/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.erase(ft_m1.begin(), ft_m1.end());
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
   	std_m1.erase(std_m1.begin(), std_m1.end());
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "insert");
	// ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
	// erase 3/3
	PRINT_BLUE("erase 3/3", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.insert(std::make_pair(1, "1"));
   	ft_m1.insert(std::make_pair(2, "2"));
   	ft_m1.insert(std::make_pair(9, "9"));
   	ft_m1.insert(std::make_pair(3, "3"));
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
   	std_m1.insert(std::make_pair(1, "1"));
   	std_m1.insert(std::make_pair(2, "2"));
   	std_m1.insert(std::make_pair(9, "9"));
   	std_m1.insert(std::make_pair(3, "3"));
	DISPLAY_MAP_STD(std_m1, "std_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
   	ft_m1.erase(9);
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
   	std_m1.erase(9);
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "erase 3/3");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// clear if not empty
	PRINT_BLUE("clear if not empty", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.clear();
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std_m1.clear();
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "clear if not empty");
	// ------------------------------------------------------------------------
	
	// ------------------------------------------------------------------------
	// clear
	PRINT_BLUE("clear if already empty", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_m1.clear();
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std_m1.clear();
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_map_equals(std_m1, ft_m1, "clear if already empty");
	// ------------------------------------------------------------------------	

}

void test_lookup(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("\n\n*** MAP Lookup\n", DEBUG_LOOKUP_FUNCTIONS && 1);

	// ------------------------------------------------------------------------
	// count
	PRINT_BLUE("count", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	ft::Map<int, std::string> ft_m1;
   	ft_m1.insert(std::make_pair(0, "0"));
   	ft_m1.insert(std::make_pair(1, "1"));
   	ft_m1.insert(std::make_pair(2, "2"));
   	ft_m1.insert(std::make_pair(3, "3"));
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("ft_m1.count(1);", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT(ft_m1.count(1), DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	std::map<int, std::string> std_m1;
   	std_m1.insert(std::make_pair(0, "0"));
   	std_m1.insert(std::make_pair(1, "1"));
   	std_m1.insert(std::make_pair(2, "2"));
   	std_m1.insert(std::make_pair(3, "3"));
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("std_m1.count(1);", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT(std_m1.count(1), DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	assert_value_equals(std_m1.count(1), ft_m1.count(1), "count");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// find
	PRINT_BLUE("find", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*ft_m1.find(1).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*ft_m1.find(1)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*std_m1.find(1).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*std_m1.find(1)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	assert_value_equals((*std_m1.find(1)).first, (*ft_m1.find(1)).first, "find");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// lower_bound
	PRINT_BLUE("lower_bound", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*ft_m1.lower_bound(1).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*ft_m1.lower_bound(1)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*std_m1.lower_bound(1).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*std_m1.lower_bound(1)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	assert_value_equals((*std_m1.lower_bound(1)).first, (*ft_m1.lower_bound(1)).first, "lower_bound");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// upper_bound
	PRINT_BLUE("upper_bound", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*ft_m1.upper_bound(2).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*ft_m1.upper_bound(2)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("*std_m1.upper_bound(2).first:", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT((*std_m1.upper_bound(2)).first, DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	assert_value_equals((*std_m1.upper_bound(2)).first, (*ft_m1.upper_bound(2)).first, "upper_bound");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// equal_range
	PRINT_BLUE("equal_range", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("(*(ft_m1.equal_range(2).first)).first", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT( (*(ft_m1.equal_range(2).first)).first , DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("(*(ft_m1.equal_range(2).second)).first", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT( (*(ft_m1.equal_range(2).second)).first , DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	DISPLAY_MAP_STD(std_m1, "std_m1", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("(*(std_m1.equal_range(2).first)).first", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT( (*(std_m1.equal_range(2).first)).first , DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT("(*(std_m1.equal_range(2).second)).first", DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	PRINT( (*(std_m1.equal_range(2).second)).first , DEBUG_LOOKUP_FUNCTIONS && VERBOSE);
	// ---
	assert_value_equals((*(std_m1.equal_range(2).first)).first, (*(ft_m1.equal_range(2).first)).first, "equal_range (first)");
	assert_value_equals((*(std_m1.equal_range(2).second)).first, (*(ft_m1.equal_range(2).second)).first, "equal_range (second)");
	// ------------------------------------------------------------------------
}

void test_non_member_functions(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** MAP Non member functions\n", DEBUG_OPERATIONS && 1);

    ft::Map<int, std::string> ft_m1;
	ft_m1.insert(std::make_pair(1, "1"));
	ft_m1.insert(std::make_pair(2, "2"));
    DISPLAY_MAP_FT(ft_m1, "ft_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Map<int, std::string> ft_m2;
	ft_m2.insert(std::make_pair(1, "1"));
	ft_m2.insert(std::make_pair(2, "2"));
	ft_m2.insert(std::make_pair(3, "3"));
    DISPLAY_MAP_FT(ft_m2, "ft_m2 ", DEBUG_CONSTRUCTORS && VERBOSE);

    std::map<int, std::string> std_m1;
	std_m1.insert(std::make_pair(1, "1"));
	std_m1.insert(std::make_pair(2, "2"));
    DISPLAY_MAP_STD(std_m1, "std_m1 ", DEBUG_CONSTRUCTORS && VERBOSE);
    std::map<int, std::string> std_m2;
	std_m2.insert(std::make_pair(1, "1"));
	std_m2.insert(std::make_pair(2, "2"));
	std_m2.insert(std::make_pair(3, "3"));
    DISPLAY_MAP_STD(std_m2, "std_m2 ", DEBUG_CONSTRUCTORS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty map
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 == std_m2), (ft_m1 == ft_m2), "== not empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty map
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 != std_m2), (ft_m1 != ft_m2), "!= not empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty map
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 < std_m2), (ft_m1 < ft_m2), "< not empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty map
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 <= std_m2), (ft_m1 <= ft_m2), "<= not empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty map
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 > std_m2), (ft_m1 > ft_m2), "> not empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty map
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m1 >= std_m2), (ft_m1 >= ft_m2), ">= not empty map");
    // ------------------------------------------------------------------------

    ft::Map<int, std::string> ft_m3;
    ft::Map<int, std::string> ft_m4;
    DISPLAY_MAP_FT(ft_m3, "ft_m3 ", DEBUG_CONSTRUCTORS && VERBOSE);
    DISPLAY_MAP_FT(ft_m4, "ft_m4 ", DEBUG_CONSTRUCTORS && VERBOSE);

    std::map<int, std::string> std_m3;
    std::map<int, std::string> std_m4;
    DISPLAY_MAP_STD(std_m3, "std_m3", DEBUG_CONSTRUCTORS && VERBOSE);
    DISPLAY_MAP_STD(std_m4, "std_m4", DEBUG_CONSTRUCTORS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty map
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 == std_m4), (ft_m3 == ft_m4), "== if empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty map
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 != std_m4), (ft_m3 != ft_m4), "!= if empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty map
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 < std_m4), (ft_m3 < ft_m4), "< if empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty map
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 <= std_m4), (ft_m3 <= ft_m4), "<= if empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty map
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 > std_m4), (ft_m3 > ft_m4), "> if empty map");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty map
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_m3 >= std_m4), (ft_m3 >= ft_m4), ">= if empty map");
    // ------------------------------------------------------------------------
}

int main()
{
    test_constructors();
    test_element_access();
    test_capacity();
    test_modifiers();
    test_lookup();
    test_non_member_functions();

}
