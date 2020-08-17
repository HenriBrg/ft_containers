/* ************************************************************************** QUEUE */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:14:29 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/06 23:25:06 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** QUEUE */

#include <queue>
#include "includes/Queue.hpp"
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
#define DISPLAY_QUEUE(queue, name, LOG) display_queue(queue, name, LOG)

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
    
    PRINT_MAGENTA("*** QUEUE Constructors\n", DEBUG_CONSTRUCTORS && 1);

    // ------------------------------------------------------------------------
    // default
    PRINT_BLUE("default:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::Queue<int> ft_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Queue<int> ft_q1;
    DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::queue<int> std_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::queue<int> std_q1;
    DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_queue_equals(std_q1, ft_q1, "constructor 1/2 - default");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // assignation
    PRINT_BLUE("assignation:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
    // ---
    PRINT("ft::Queue<int> ft_q2 = ft_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Queue<int> ft_q2 = ft_q1;
    DISPLAY_QUEUE(ft_q2, "ft_q2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("std::queue<int> std_q2 = std_q1;", DEBUG_CONSTRUCTORS && VERBOSE);
    std::queue<int> std_q2 = std_q1;
    DISPLAY_QUEUE(std_q2, "std_q2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---    
    assert_queue_equals(std_q2, ft_q2, "constructor 2/2 - assignation");
    // ------------------------------------------------------------------------
}

void test_element_access(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** QUEUE Element access\n", DEBUG_ELEMENT_ACCESS && 1);

    // ------------------------------------------------------------------------
    // front
	PRINT_BLUE("front 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    ft::Queue<int> ft_q1;
    std::queue<int> std_q1;
    // ---
    DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT("ft_q1.front()", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_q1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // PRINT(std_q1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std segfault", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    // assert_value_equals(std_q1.front(), ft_q1.front(), "front 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // back
	PRINT_BLUE("back 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_q1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    // PRINT(std_q1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    PRINT("std segfault", DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    // assert_value_equals(std_q1.back(), ft_q1.back(), "back 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // front
	PRINT_BLUE("front 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
    // ---
    DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT("ft_q1.front()", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_q1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT("std_q1.front()", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(std_q1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_q1.front(), ft_q1.front(), "front 2/2 - if not empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // back
	PRINT_BLUE("back 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
    // ---
    DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_q1.back()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_q1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_q1.back()", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(std_q1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_q1.back(), ft_q1.back(), "back 2/2 - if not empty");
    // ------------------------------------------------------------------------

}

void test_capacity(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }
	
	PRINT_MAGENTA("*** QUEUE Capacity\n", DEBUG_ELEMENT_ACCESS && 1);

	ft::Queue<int> ft_q1;
	std::queue<int> std_q1;
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_q1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_q1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_QUEUE(std_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_q1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_q1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_q1.empty(), ft_q1.empty(), "empty 1/2 - if empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 1/2 if empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_q1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_q1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_QUEUE(std_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_q1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_q1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_q1.size(), ft_q1.size(), "size 1/2 - if empty");
	// ------------------------------------------------------------------------

	ft_q1.push(1);
	ft_q1.push(2);
	std_q1.push(1);
	std_q1.push(2);
	
	// ------------------------------------------------------------------------
	// empty
	PRINT_BLUE("empty 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_q1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_q1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_QUEUE(std_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_q1.empty()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_q1.empty(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_q1.empty(), ft_q1.empty(), "empty 2/2 if not empty");
	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------
	// size
	PRINT_BLUE("size 2/2 if not empty:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
	DISPLAY_QUEUE(ft_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("ft_q1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(ft_q1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---
	DISPLAY_QUEUE(std_q1, "ft_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT("std_q1.size()", DEBUG_CONSTRUCTORS && VERBOSE);
	PRINT(std_q1.size(), DEBUG_ELEMENT_ACCESS && VERBOSE);
	// ---    
	assert_value_equals(std_q1.size(), ft_q1.size(), "size 2/2 - if not empty");
	// ------------------------------------------------------------------------
}

void test_modifiers(void)
{
	int VERBOSE;
	try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
	catch(...) { VERBOSE = 0; }

	PRINT_MAGENTA("\n\n*** QUEUE Modifiers\n", DEBUG_MEMBER_FUNCTIONS && 1);


	// ------------------------------------------------------------------------
	// push
	PRINT_BLUE("push", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
	ft::Queue<int> ft_q1;
   	ft_q1.push(1);
	ft_q1.push(2);
	DISPLAY_QUEUE(ft_q1, "ft_q1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std::queue<int> std_q1;
	std_q1.push(1);
	std_q1.push(2);
	DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_queue_equals(std_q1, ft_q1, "push");
	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------
	// pop
	PRINT_BLUE("pop", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	ft_q1.pop();
	DISPLAY_QUEUE(ft_q1, "ft_q1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	std_q1.pop();
	DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	assert_queue_equals(std_q1, ft_q1, "pop");
	// ------------------------------------------------------------------------
	
	// ------------------------------------------------------------------------
	// pop
	PRINT_BLUE("pop if already empty", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
	// ---
   	// ft_q1.pop();
	// DISPLAY_QUEUE(ft_q1, "ft_q1 ", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	// std_q1.pop();
	PRINT("std segfault", DEBUG_ELEMENT_ACCESS && VERBOSE);
	// DISPLAY_QUEUE(std_q1, "std_q1", DEBUG_CONSTRUCTORS && VERBOSE);
	// ---
	// assert_queue_equals(std_q1, ft_q1, "pop if already empty");
	// ------------------------------------------------------------------------	

}

void test_non_member_functions(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** QUEUE Non member functions\n", DEBUG_OPERATIONS && 1);

    ft::Queue<int> ft_q1;
	ft_q1.push(1);
	ft_q1.push(2);
    DISPLAY_QUEUE(ft_q1, "ft_q1 ", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::Queue<int> ft_q2;
	ft_q2.push(1);
	ft_q2.push(2);
	ft_q2.push(3);
    DISPLAY_QUEUE(ft_q2, "ft_q2 ", DEBUG_CONSTRUCTORS && VERBOSE);

    std::queue<int> std_q1;
	std_q1.push(1);
	std_q1.push(2);
    DISPLAY_QUEUE(std_q1, "std_q1 ", DEBUG_CONSTRUCTORS && VERBOSE);
    std::queue<int> std_q2;
	std_q2.push(1);
	std_q2.push(2);
	std_q2.push(3);
    DISPLAY_QUEUE(std_q2, "std_q2 ", DEBUG_CONSTRUCTORS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty queue
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 == std_q2), (ft_q1 == ft_q2), "== not empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty queue
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 != std_q2), (ft_q1 != ft_q2), "!= not empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty queue
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 < std_q2), (ft_q1 < ft_q2), "< not empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty queue
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 <= std_q2), (ft_q1 <= ft_q2), "<= not empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty queue
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 > std_q2), (ft_q1 > ft_q2), "> not empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty queue
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q1 >= std_q2), (ft_q1 >= ft_q2), ">= not empty queue");
    // ------------------------------------------------------------------------

    ft::Queue<int> ft_q3;
    ft::Queue<int> ft_q4;
    DISPLAY_QUEUE(ft_q3, "ft_q3 ", DEBUG_CONSTRUCTORS && VERBOSE);
    DISPLAY_QUEUE(ft_q4, "ft_q4 ", DEBUG_CONSTRUCTORS && VERBOSE);

    std::queue<int> std_q3;
    std::queue<int> std_q4;
    DISPLAY_QUEUE(std_q3, "std_q3", DEBUG_CONSTRUCTORS && VERBOSE);
    DISPLAY_QUEUE(std_q4, "std_q4", DEBUG_CONSTRUCTORS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty queue
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 == std_q4), (ft_q3 == ft_q4), "== if empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty queue
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 != std_q4), (ft_q3 != ft_q4), "!= if empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty queue
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 < std_q4), (ft_q3 < ft_q4), "< if empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty queue
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 <= std_q4), (ft_q3 <= ft_q4), "<= if empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty queue
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 > std_q4), (ft_q3 > ft_q4), "> if empty queue");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty queue
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_q3 >= std_q4), (ft_q3 >= ft_q4), ">= if empty queue");
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