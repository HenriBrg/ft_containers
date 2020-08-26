#include <stack>
#include "includes/Stack.hpp"
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

#define PRINT(content, LOG) if (LOG) (std::cout << content << std::endl);
int test_id = 1;
#define PRINT_MAGENTA(content, LOG) if (LOG) (std::cout << MAGENTA_C << content << RESET << std::endl);
#define PRINT_BLUE(content, LOG) if (LOG) (std::cout << BLUE_C << test_id++ << " - " << content << RESET << std::endl);
#define PRINT_RED(content, LOG) if (LOG) (std::cout << RED_C << content << RESET << std::endl);
#define DISPLAY_STACK(stack, name, LOG) display_stack(stack, name, LOG)

/*
** CONSTANTES
*/

#define DEBUG_CONSTRUCTORS        1
#define DEBUG_DESTRUCTORS         1
#define DEBUG_ELEMENT_ACCESS      1
#define DEBUG_ITERATORS           1
#define DEBUG_CAPACITY            1
#define DEBUG_MEMBER_FUNCTIONS    1
#define DEBUG_OPERATIONS          1

/*
** TESTS
*/

void test_constructors(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** STACK Constructors\n", DEBUG_CONSTRUCTORS && 1);

    // ------------------------------------------------------------------------
    // default
    PRINT_BLUE("default:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Stack<int> ft_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Stack<int> ft_q1;
    DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::stack<int> std_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::stack<int> std_q1;
    DISPLAY_STACK(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_stack_equals(std_q1, ft_q1, "constructor default");
    // ------------------------------------------------------------------------


    // ------------------------------------------------------------------------
    // copy
    PRINT_BLUE("copy:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
    // ---
    PRINT("ft::Stack<int> ft_q2(ft_q1);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Stack<int> ft_q2(ft_q1);
    DISPLAY_STACK(ft_q2, "ft_q2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::stack<int> std_q2(std_q1);", DEBUG_CONSTRUCTORS && VERBOSE);
    std::stack<int> std_q2(std_q1);
    DISPLAY_STACK(std_q2, "std_q2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_stack_equals(std_q2, ft_q2, "constructor copy");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // assignation
    PRINT_BLUE("assignation:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Stack<int> ft_q3 = ft_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Stack<int> ft_q3 = ft_q1;
    DISPLAY_STACK(ft_q3, "ft_q3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::stack<int> std_q3 = std_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::stack<int> std_q3 = std_q1;
    DISPLAY_STACK(std_q3, "std_q3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_stack_equals(std_q3, ft_q3, "constructor assignation");
    // ------------------------------------------------------------------------
}

void test_element_access(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** STACK Element access\n", DEBUG_ELEMENT_ACCESS && 1);

    // ------------------------------------------------------------------------
    // top
	PRINT_BLUE("top 1/2 if empty:", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    ft::Stack<int> ft_q1;
    std::stack<int> std_q1;
    // ---
    DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_q1.top()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_q1.top(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_STACK(std_q1, "std_q1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // PRINT(std_q1.top(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std segfault", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    // assert_value_equals(std_q1.top(), ft_q1.top(), "top 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // front
	PRINT_BLUE("top 2/2 if not empty:", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
    // ---
    DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("ft_q1.top()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(ft_q1.top(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_STACK(std_q1, "std_q1", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std_q1.top()", DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT(std_q1.top(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_q1.top(), ft_q1.top(), "top 2/2 - if not empty");
    // ------------------------------------------------------------------------

}

void test_capacity(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }
	
	PRINT_MAGENTA("*** STACK Capacity\n", DEBUG_CAPACITY && 1);

	ft::Stack<int> ft_q1;
	std::stack<int> std_q1;
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 1/2 if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_q1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_q1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	DISPLAY_STACK(std_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_q1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_q1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---    
	assert_value_equals(std_q1.empty(), ft_q1.empty(), "empty 1/2 - if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 1/2 if empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_q1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_q1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	DISPLAY_STACK(std_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_q1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_q1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---    
	assert_value_equals(std_q1.size(), ft_q1.size(), "size 1/2 - if empty");
	// ------------------------------------------------------------------------

	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
	
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 2/2 if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_q1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_q1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---
	DISPLAY_STACK(std_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_q1.empty()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_q1.empty(), DEBUG_CAPACITY && VERBOSE);
	// ---    
	assert_value_equals(std_q1.empty(), ft_q1.empty(), "empty 2/2 if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 2/2 if not empty:", DEBUG_CAPACITY && VERBOSE);
    // ---
	DISPLAY_STACK(ft_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("ft_q1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(ft_q1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---
	DISPLAY_STACK(std_q1, "ft_q1", DEBUG_CAPACITY && VERBOSE);
	PRINT("std_q1.size()", DEBUG_CAPACITY && VERBOSE);
	PRINT(std_q1.size(), DEBUG_CAPACITY && VERBOSE);
	// ---    
	assert_value_equals(std_q1.size(), ft_q1.size(), "size 2/2 - if not empty");
	// ------------------------------------------------------------------------
}

void test_modifiers(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("\n\n*** STACK Modifiers\n", DEBUG_MEMBER_FUNCTIONS && 1);


	// ------------------------------------------------------------------------
	// push
	PRINT_BLUE("push", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	ft::Stack<int> ft_q1;
   	ft_q1.push(1);
	ft_q1.push(2);
	DISPLAY_STACK(ft_q1, "ft_q1 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ft::Stack<int> ft_q2(4, 2);
	// DISPLAY_STACK(ft_q2, "ft_q2 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	std::stack<int> std_q1;
	std_q1.push(1);
	std_q1.push(2);
	DISPLAY_STACK(std_q1, "std_q1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// std::stack<int> std_q2(4, 2);
	// DISPLAY_STACK(std_q2, "std_q2", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	assert_stack_equals(std_q1, ft_q1, "push");
	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------
	// pop
	PRINT_BLUE("pop", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_q1.pop();
	DISPLAY_STACK(ft_q1, "ft_q1 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ft::Stack<int> ft_q2(4, 2);
	// DISPLAY_STACK(ft_q2, "ft_q2 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	std_q1.pop();
	DISPLAY_STACK(std_q1, "std_q1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// std::stack<int> std_q2(4, 2);
	// DISPLAY_STACK(std_q2, "std_q2", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	assert_stack_equals(std_q1, ft_q1, "pop");
	// ------------------------------------------------------------------------
	
	// ------------------------------------------------------------------------
	// pop
	PRINT_BLUE("pop if already empty", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	// ft_q1.pop();
   	// ft_q1.pop();
	DISPLAY_STACK(ft_q1, "ft_q1 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ft::Stack<int> ft_q2(4, 2);
	// DISPLAY_STACK(ft_q2, "ft_q2 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	// std_q1.pop();
	// std_q1.pop();
	PRINT("std segfault", DEBUG_ELEMENT_ACCESS && VERBOSE);
	// DISPLAY_STACK(std_q1, "std_q1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// std::stack<int> std_q2(4, 2);
	// DISPLAY_STACK(std_q2, "std_q2", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	assert_stack_equals(std_q1, ft_q1, "pop if already empty");
	// ------------------------------------------------------------------------	

}

void test_non_member_functions(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** STACK Non member functions\n", DEBUG_OPERATIONS && 1);

    ft::Stack<int> ft_q1;
	ft_q1.push(1);
	ft_q1.push(2);
    DISPLAY_STACK(ft_q1, "ft_q1 ", DEBUG_OPERATIONS && VERBOSE);
    ft::Stack<int> ft_q2;
	ft_q2.push(1);
	ft_q2.push(2);
	ft_q2.push(9);
    DISPLAY_STACK(ft_q2, "ft_q2 ", DEBUG_OPERATIONS && VERBOSE);

    std::stack<int> std_q1;
	std_q1.push(1);
	std_q1.push(2);
    DISPLAY_STACK(std_q1, "std_q1 ", DEBUG_OPERATIONS && VERBOSE);
    std::stack<int> std_q2;
	std_q2.push(1);
	std_q2.push(2);
	std_q2.push(9);
    DISPLAY_STACK(std_q2, "std_q2 ", DEBUG_OPERATIONS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty stack
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 == std_q2), (ft_q1 == ft_q2), "== not empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty stack
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 != std_q2), (ft_q1 != ft_q2), "!= not empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty stack
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 < std_q2), (ft_q1 < ft_q2), "< not empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty stack
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 <= std_q2), (ft_q1 <= ft_q2), "<= not empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty stack
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 > std_q2), (ft_q1 > ft_q2), "> not empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty stack
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 >= std_q2), (ft_q1 >= ft_q2), ">= not empty stack");
    // ------------------------------------------------------------------------

    ft::Stack<int> ft_q3;
    ft::Stack<int> ft_q4;
    DISPLAY_STACK(ft_q3, "ft_q3 ", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_STACK(ft_q4, "ft_q4 ", DEBUG_OPERATIONS && VERBOSE);

    std::stack<int> std_q3;
    std::stack<int> std_q4;
    DISPLAY_STACK(std_q3, "std_q3", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_STACK(std_q4, "std_q4", DEBUG_OPERATIONS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty stack
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 == std_q4), (ft_q3 == ft_q4), "== if empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty stack
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 != std_q4), (ft_q3 != ft_q4), "!= if empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty stack
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 < std_q4), (ft_q3 < ft_q4), "< if empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty stack
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 <= std_q4), (ft_q3 <= ft_q4), "<= if empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty stack
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 > std_q4), (ft_q3 > ft_q4), "> if empty stack");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty stack
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 >= std_q4), (ft_q3 >= ft_q4), ">= if empty stack");
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