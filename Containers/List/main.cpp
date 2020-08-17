/* ************************************************************************** LIST */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisberger <francisberger@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:14:29 by francisberg       #+#    #+#             */
/*   Updated: 2020/08/06 22:21:36 by francisberg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** LIST */

#include <list>
#include "includes/List.hpp"
#include "../../Tester/Tester.hpp"

// ------------------------------------------------------------------------

/*
** Summary
** PROTOTYPES
** MACROS
** CONSTANTS
** FUNCTIONS
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

int test_id = 1;
#define PRINT(content, LOG) if (LOG) (std::cout << content << std::endl);
#define PRINT_MAGENTA(content, LOG) if (LOG) (std::cout << MAGENTA_C << content << RESET << std::endl);
#define PRINT_BLUE(content, LOG) if (LOG) (std::cout << BLUE_C << test_id++ << " - " << content << RESET << std::endl);
#define PRINT_RED(content, LOG) if (LOG) (std::cout << RED_C << content << RESET << std::endl);
#define DISPLAY_LIST(l, name, LOG) display_list(l, name, LOG)

/*
** CONSTANTES
*/

#define OK 0
#define KO 1

#define DEBUG_CONSTRUCTORS        1
#define DEBUG_DESTRUCTORS         1
#define DEBUG_ELEMENT_ACCESS      1
#define DEBUG_ITERATORS           1
#define DEBUG_CAPACITY            1
#define DEBUG_MEMBER_FUNCTIONS    1
#define DEBUG_OPERATIONS          1

/*
** FUNCTIONS
*/

/* cf. remove_if() - Ignore sign of the value */
bool foo(int n) {
   return (n > 5);
}

/* cf. unique() 2/2 - Ignore sign of the value */
bool pred(int a, int b) {
   return (abs(a) == abs(b));
}
/* cf. merge() 2/2 */
bool cmp_fun(int a, int b) {
   return a > b;
}
/* cf. sort() 2/2 */
bool comp(int a, int b) {
   return (a > b);
}

/*
** TESTS
*/

void test_constructors(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** LIST Constructors\n", DEBUG_CONSTRUCTORS && 1);

    // ------------------------------------------------------------------------
    // default: Constructs an empty list with zero elements.
    PRINT_BLUE("default:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::List<int> l1;", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::List<int> l1;
    DISPLAY_LIST(l1, "l1", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    std::list<int> std_l1;
    // ---    
    assert_list_equals(std_l1, l1, "constructor 1/4 - default");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // fill: Constructs a new list with n elements and assigns val to each element of list.
    PRINT_BLUE("fill with values:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::List<int> l2(5, 1);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::List<int> l2(5, 2);
    DISPLAY_LIST(l2, "l2", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    std::list<int> std_l2(5, 2);
    // ---
    assert_list_equals(std_l2, l2, "constructor 2/4 - fill");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // range: Constructs a list with as many elements as in range of first to last.
    PRINT_BLUE("range:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::List<int> l3(l2.begin(), l2.end());", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::List<int> l3(l2.begin(), l2.end());
    DISPLAY_LIST(l3, "l3", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    std::list<int> std_l3(std_l2.begin(), std_l2.end());
    // ---
    assert_list_equals(std_l3, l3, "constructor 3/4 - range");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    PRINT_BLUE("copy:", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    PRINT("ft::List<int> l4(l3);", DEBUG_CONSTRUCTORS && VERBOSE);
    ft::List<int> l4(l3);
    DISPLAY_LIST(l4, "l4", DEBUG_CONSTRUCTORS && VERBOSE);
    // ---
    std::list<int> std_l4(std_l3);
    // ---
    assert_list_equals(std_l4, l4, "constructor 4/4 - copy");
    // ------------------------------------------------------------------------
}

void test_element_access(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** LIST Element access\n", DEBUG_ELEMENT_ACCESS && 1);

    // ------------------------------------------------------------------------
    // front
    ft::List<int> ft_l1;
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_l1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    std::list<int> std_l1;
    PRINT(std_l1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_l1.front(), ft_l1.front(), "front 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // back
    PRINT(ft_l1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    PRINT(std_l1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_l1.back(), ft_l1.back(), "back 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // front
    init_list(ft_l1, 5);
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_CONSTRUCTORS && VERBOSE);
    PRINT(ft_l1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    init_list(std_l1, 5);
    PRINT(std_l1.front(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_l1.front(), ft_l1.front(), "front 2/2 - if not empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // back
    PRINT(ft_l1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---
    PRINT(std_l1.back(), DEBUG_ELEMENT_ACCESS && VERBOSE);
    // ---    
    assert_value_equals(std_l1.back(), ft_l1.back(), "back 2/2 - if not empty");
    // ------------------------------------------------------------------------
}

void test_capacity(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }
    
    PRINT_MAGENTA("*** LIST Capacity\n", DEBUG_CAPACITY && 1);

    // ------------------------------------------------------------------------
    // empty
    // ---
    ft::List<int> ft_l1;
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_CAPACITY && VERBOSE);
    PRINT(ft_l1.empty(), DEBUG_CAPACITY && VERBOSE);
    // ---
    std::list<int> std_l1;
    PRINT(std_l1.empty(), DEBUG_CAPACITY && VERBOSE);
    // ---    
    assert_value_equals(std_l1.empty(), ft_l1.empty(), "empty 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // size
    PRINT(ft_l1.size(), DEBUG_CAPACITY && VERBOSE);
    // ---
    PRINT(std_l1.size(), DEBUG_CAPACITY && VERBOSE);
    // ---    
    assert_value_equals(std_l1.size(), ft_l1.size(), "size 1/2 - if empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // empty
    // ---
    init_list(ft_l1, 5);
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_CAPACITY && VERBOSE);
    PRINT(ft_l1.empty(), DEBUG_CAPACITY && VERBOSE);
    // ---
    init_list(std_l1, 5);
    PRINT(std_l1.empty(), DEBUG_CAPACITY && VERBOSE);
    // ---    
    assert_value_equals(std_l1.empty(), ft_l1.empty(), "empty 2/2 - if not empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // size
    // ---
    PRINT(ft_l1.size(), DEBUG_CAPACITY && VERBOSE);
    // ---
    PRINT(std_l1.size(), DEBUG_CAPACITY && VERBOSE);
    // ---    
    assert_value_equals(std_l1.size(), ft_l1.size(), "size 2/2 - if not empty");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // max_size
    // ---
    PRINT(ft_l1.max_size(), DEBUG_CAPACITY && VERBOSE);
    // ---
    PRINT(std_l1.max_size(), DEBUG_CAPACITY && VERBOSE);
    // ---    
    // ------------------------------------------------------------------------
}

void test_modifiers(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** LIST Modifiers\n", DEBUG_MEMBER_FUNCTIONS && 1);

    ft::List<int> ft_l1;
    init_list(ft_l1, 5);
    DISPLAY_LIST(ft_l1, "ft_l1 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);

    ft::List<int> ft_l2(4, 2);
    DISPLAY_LIST(ft_l2, "ft_l2 ", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    
    PRINT("--- For testing:", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT("---\n", DEBUG_MEMBER_FUNCTIONS && VERBOSE);

    std::list<int> std_l1;
    init_list(std_l1, 5);
    // DISPLAY_LIST(std_l1, "std_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);

    std::list<int> std_l2(4, 2);
    // DISPLAY_LIST(std_l2, "std_l2", DEBUG_MEMBER_FUNCTIONS && VERBOSE);

    // assign: assign new content to container (public member function )
    // ------------------------------------------------------------------------
    // assign 1/2
    PRINT_BLUE("Assign with range (1/2)", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.assign(ft_l2.begin(), ft_l2.end());", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.assign(ft_l2.begin(), ft_l2.end());
    DISPLAY_LIST(ft_l1, "ft_l1 après", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 après", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.assign(std_l2.begin(), std_l2.end());
    // ---
    assert_list_equals(std_l1, ft_l1, "assign 1/2 - assigned list == list passed as arg");
    assert_list_equals(std_l2, ft_l2, "assign 1/2 - list passed as arg stays the same");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // assign 2/2
    PRINT_BLUE("b) Assign by filling (2/2)", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.assign(5, 10);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.assign(5, 10);
    DISPLAY_LIST(ft_l1, "ft_l1 après", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.assign(5, 10);
    // ---
    assert_list_equals(std_l1, ft_l1, "assign 2/2");
    // ------------------------------------------------------------------------

    // /* C++11 PRINT_BLUE("Assign / init", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // PRINT("ft_l1.assign(5, 10);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // auto it = {1, 2, 3, 4, 5};
    // std::list<int> l7;
    // l7.assign(it);
    // DISPLAY_LIST(l7, "l7", DEBUG_MEMBER_FUNCTIONS && VERBOSE); */

    // ------------------------------------------------------------------------
    // pop_front - Delete first element (public member function )
    PRINT_BLUE("pop_front()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.pop_front();", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.pop_front();
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.pop_front();
    // ---
    assert_list_equals(std_l1, ft_l1, "pop_front");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // pop_back - Delete last element (public member function )
    PRINT_BLUE("pop_back()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.pop_back();", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.pop_back();
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.pop_back();
    // ---
    assert_list_equals(std_l1, ft_l1, "pop_back");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // push_front
    PRINT_BLUE("push_front()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.push_front(5);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.push_front(5);
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.push_front(5);
    // ---
    assert_list_equals(std_l1, ft_l1, "push_front");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // push_back
    PRINT_BLUE("push_back()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.push_back(5);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.push_back(5);
    DISPLAY_LIST(ft_l1, "ft_l1", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    std_l1.push_back(5);
    // ---
    assert_list_equals(std_l1, ft_l1, "push_back");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // resize - Change size (public member function )
    PRINT_BLUE("resize()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("Initial size of ft_list:", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT(ft_l1.size(), DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT("ft_l1.resize(2);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    ft_l1.resize(2);
    DISPLAY_LIST(ft_l1, "ft_l1 after resize", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT("Size of ft_l1 after resize(2):", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT(ft_l1.size(), DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("Initial size of std_list:", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT(std_l1.size(), DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT("std_l1.resize(2);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    std_l1.resize(2);
    DISPLAY_LIST(std_l1, "std_l1 after resize", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT("Size of std_l1 after resize(2):", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    PRINT(std_l1.size(), DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "resize");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // swap - Swap content (public member function )
    PRINT_BLUE("swap()", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("ft_l1.swap(ft_l2);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    ft_l1.clear();
    init_list(ft_l1, 6);
    
    std_l1.clear();
    init_list(std_l1, 6);
    
    ft_l2.clear();
    init_list(ft_l2, 4);

    std_l2.clear();
    init_list(std_l2, 4);
    DISPLAY_LIST(ft_l1, "ft_l1 before swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 before swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(std_l1, "std_l1 before swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 before swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    ft_l1.swap(ft_l2);
    DISPLAY_LIST(ft_l1, "ft_l1 after swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    PRINT("std_l1.swap(std_l2);", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    std_l1.swap(std_l2);
    DISPLAY_LIST(std_l1, "std_l1 after swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after swap", DEBUG_MEMBER_FUNCTIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "swap 1/2");
    assert_list_equals(std_l2, ft_l2, "swap 2/2");
    // ------------------------------------------------------------------------

}

void test_operations(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** LIST Operations\n", DEBUG_OPERATIONS && 1);

    ft::List<int> ft_l1(3, 1);
    ft::List<int> ft_l2(3, 2);
    DISPLAY_LIST(ft_l1, "ft_l1 ", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 ", DEBUG_OPERATIONS && VERBOSE);

    std::list<int> std_l1(3, 1);
    std::list<int> std_l2(3, 2);
    DISPLAY_LIST(std_l1, "std_l1", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2", DEBUG_OPERATIONS && VERBOSE);

    // ------------------------------------------------------------------------
    // splice          Transfer elements from list to list (public member function )
    // ---
    PRINT_BLUE("splice()  default (1/3)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("ft_l1.splice(ft_l1.end(), ft_l2);", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.splice(ft_l1.end(), ft_l2);
    DISPLAY_LIST(ft_l1, "ft_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l1.splice(std_l1.end(), std_l2);", DEBUG_OPERATIONS && VERBOSE);
    std_l1.splice(std_l1.end(), std_l2);
    DISPLAY_LIST(std_l1, "std_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "splice 1/3 - default - list dest");
    assert_list_equals(std_l2, ft_l2, "splice 1/3 - default - list src");
    // ------------------------------------------------------------------------


    // ------------------------------------------------------------------------
    PRINT_BLUE("splice() single element (2/3)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    PRINT("ft_l2.splice(ft_l2.end(), ft_l1, ft_l1.begin());", DEBUG_OPERATIONS && VERBOSE);
    ft_l2.splice(ft_l2.end(), ft_l1, ft_l1.begin());
    DISPLAY_LIST(ft_l1, "ft_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l2.splice(std_l2.end(), std_l1, std_l1.begin());", DEBUG_OPERATIONS && VERBOSE);
    std_l2.splice(std_l2.end(), std_l1, std_l1.begin());
    DISPLAY_LIST(std_l1, "std_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "splice 2/3 - single element - list dest");
    assert_list_equals(std_l2, ft_l2, "splice 2/3 - single element - list src");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    PRINT_BLUE("splice() range version (3/3)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    PRINT("ft_l1.splice(ft_l1.end(), ft_l2, ft_l2.begin(), ft_l2.end());", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.splice(ft_l1.end(), ft_l2, ft_l2.begin(), ft_l2.end());
    DISPLAY_LIST(ft_l1, "ft_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l1.splice(std_l1.end(), std_l2, std_l2.begin(), std_l2.end());", DEBUG_OPERATIONS && VERBOSE);
    std_l1.splice(std_l1.end(), std_l2, std_l2.begin(), std_l2.end());
    DISPLAY_LIST(std_l1, "std_l1 after splice", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after splice", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "splice 3/3 - range element - list dest");
    assert_list_equals(std_l2, ft_l2, "splice 3/3 - range element - list src");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // remove - Remove elements with specific value (public member function )
    PRINT_BLUE("remove()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    ft_l1.push_back(3);
    ft_l1.push_back(4);
    ft_l1.push_back(5);
    DISPLAY_LIST(ft_l1, "new ft_l1", DEBUG_OPERATIONS && VERBOSE);
    std_l1.push_back(3);
    std_l1.push_back(4);
    std_l1.push_back(5);
    DISPLAY_LIST(std_l1, "new std_l1", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("ft_l1.remove(2);", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.remove(2);
    DISPLAY_LIST(ft_l1, "ft_l1 after remove 2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l1.remove(2);", DEBUG_OPERATIONS && VERBOSE);
    std_l1.remove(2);
    DISPLAY_LIST(std_l1, "std_l1 after remove 2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "remove");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // remove_if       Remove elements fulfilling condition (public member function template )
    PRINT_BLUE("remove_if() | foo return true if > 5", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    PRINT("ft_l1.remove_if(foo);", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.remove_if(foo);
    DISPLAY_LIST(ft_l1, "ft_l1 after remove_if(foo)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l1.remove_if(foo);", DEBUG_OPERATIONS && VERBOSE);
    std_l1.remove_if(foo);
    DISPLAY_LIST(std_l1, "std_l1 after remove_if(foo)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "remove_if(foo)");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // unique          Remove duplicate values (public member function )
    PRINT_BLUE("unique() 1/2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    PRINT("ft_l1.unique();", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.unique();
    DISPLAY_LIST(ft_l1, "ft_l1 after unique()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    PRINT("std_l1.unique();", DEBUG_OPERATIONS && VERBOSE);
    std_l1.unique();
    DISPLAY_LIST(std_l1, "std_l1 after unique()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "unique");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // unique          Remove duplicate values (public member function )
    PRINT_BLUE("unique(pred) 2/2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    ft_l1.push_front(-4);
    ft_l1.push_front(-4);
    DISPLAY_LIST(ft_l1, "ft_l1 before unique(pred)", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l1.unique(pred);", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.unique(pred);
    DISPLAY_LIST(ft_l1, "ft_l1 after unique(pred)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    std_l1.push_front(-4);
    std_l1.push_front(-4);
    DISPLAY_LIST(std_l1, "std_l1 before unique(pred)", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l1.unique(pred);", DEBUG_OPERATIONS && VERBOSE);
    std_l1.unique(pred);
    DISPLAY_LIST(std_l1, "std_l1 after unique(pred)", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "unique(pred)");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // merge - Merge sorted lists (public member function )
    PRINT_BLUE("merge() default 1/2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    DISPLAY_LIST(ft_l1, "ft_l1 before merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 before merge()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l2.merge(ft_l1);", DEBUG_OPERATIONS && VERBOSE);
    ft_l2.merge(ft_l1);
    DISPLAY_LIST(ft_l1, "ft_l1 after merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after merge()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    DISPLAY_LIST(std_l1, "std_l1 before merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 before merge()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l2.merge(std_l1);", DEBUG_OPERATIONS && VERBOSE);
    std_l2.merge(std_l1);
    DISPLAY_LIST(std_l1, "std_l1 after merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after merge()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "merge 1/2 - src");
    assert_list_equals(std_l2, ft_l2, "merge 1/2 - dest");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // merge - Merge sorted lists (public member function )
    PRINT_BLUE("merge() compare function 2/2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    DISPLAY_LIST(ft_l1, "ft_l1 before merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 before merge() with ft_l1", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l1.merge(ft_l2, cmp_fun);", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l1, "ft_l1 after merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 after merge() with ft_l1", DEBUG_OPERATIONS && VERBOSE);
    // ---
    DISPLAY_LIST(std_l1, "std_l1 before merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 before merge() with std_l1", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l1.merge(std_l2, cmp_fun);", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l1, "std_l1 after merge()", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2 after merge() with std_l1", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "merge 2/2 - src");
    assert_list_equals(std_l2, ft_l2, "merge 2/2 - dest");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // sort            Sort elements in container (public member function )
    PRINT_BLUE("sort() default 1/2", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    ft_l1.push_back(8);
    ft_l1.push_back(3);
    ft_l1.push_back(0);
    ft_l1.push_back(4);
    DISPLAY_LIST(ft_l1, "ft_l1 before sort()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l1.sort();", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.sort();
    DISPLAY_LIST(ft_l1, "ft_l1 after sort()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    std_l1.push_back(8);
    std_l1.push_back(3);
    std_l1.push_back(0);
    std_l1.push_back(4);
    DISPLAY_LIST(std_l1, "std_l1 before sort()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l1.sort();", DEBUG_OPERATIONS && VERBOSE);
    std_l1.sort();
    DISPLAY_LIST(std_l1, "std_l1 after sort()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "sort 1/2");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    PRINT_BLUE("sort() compare function 2/2 | comp >", DEBUG_OPERATIONS && VERBOSE);
    // ---
    // ---
    DISPLAY_LIST(ft_l1, "ft_l1 before sort(comp)", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l1.sort(comp);", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.sort(comp);
    DISPLAY_LIST(ft_l1, "ft_l1 after sort(comp) ", DEBUG_OPERATIONS && VERBOSE);
    // ---
    DISPLAY_LIST(std_l1, "std_l1 before sort(comp)", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l1.sort(comp);", DEBUG_OPERATIONS && VERBOSE);
    std_l1.sort(comp);
    DISPLAY_LIST(std_l1, "std_l1 after sort(comp) ", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "sort comp 2/2");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // reverse         Reverse the order of elements (public member function )
    PRINT_BLUE("reverse()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    DISPLAY_LIST(ft_l1, "ft_l1 before reverse()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("ft_l1.reverse();", DEBUG_OPERATIONS && VERBOSE);
    ft_l1.reverse();
    DISPLAY_LIST(ft_l1, "ft_l1 after reverse()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    DISPLAY_LIST(std_l1, "std_l1 before reverse()", DEBUG_OPERATIONS && VERBOSE);
    PRINT("std_l1.reverse();", DEBUG_OPERATIONS && VERBOSE);
    std_l1.reverse();
    DISPLAY_LIST(std_l1, "std_l1 after reverse()", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_list_equals(std_l1, ft_l1, "reverse");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // ---
    // ---
    // ---
    // ---
    // assert_list_equals(std_l1, ft_l1, "merge 2/2 - src");
    // assert_list_equals(std_l2, ft_l2, "merge 2/2 - dest");
    // ------------------------------------------------------------------------
}

void test_non_member_functions(void)
{
    int VERBOSE;
    try { VERBOSE = std::stoi(getEnvVar("VERBOSE")); }
    catch(...) { VERBOSE = 0; }

    PRINT_MAGENTA("\n\n*** LIST Non member functions\n", DEBUG_OPERATIONS && 1);

    ft::List<int> ft_l1(3, 1);
    ft_l1.push_back(9);
    ft::List<int> ft_l2(3, 2);
    DISPLAY_LIST(ft_l1, "ft_l1 ", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l2, "ft_l2 ", DEBUG_OPERATIONS && VERBOSE);

    std::list<int> std_l1(3, 1);
    std_l1.push_back(9);
    std::list<int> std_l2(3, 2);
    DISPLAY_LIST(std_l1, "std_l1", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l2, "std_l2", DEBUG_OPERATIONS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty list
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 == std_l2), (ft_l1 == ft_l2), "== not empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty list
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 != std_l2), (ft_l1 != ft_l2), "!= not empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty list
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 < std_l2), (ft_l1 < ft_l2), "< not empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty list
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 <= std_l2), (ft_l1 <= ft_l2), "<= not empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty list
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 > std_l2), (ft_l1 > ft_l2), "> not empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty list
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l1 >= std_l2), (ft_l1 >= ft_l2), ">= not empty list");
    // ------------------------------------------------------------------------

    ft::List<int> ft_l3;
    ft::List<int> ft_l4;
    DISPLAY_LIST(ft_l3, "ft_l3 ", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(ft_l4, "ft_l4 ", DEBUG_OPERATIONS && VERBOSE);

    std::list<int> std_l3;
    std::list<int> std_l4;
    DISPLAY_LIST(std_l3, "std_l3", DEBUG_OPERATIONS && VERBOSE);
    DISPLAY_LIST(std_l4, "std_l4", DEBUG_OPERATIONS && VERBOSE);

    // ------------------------------------------------------------------------
    // == operator with not empty list
    // ---
    PRINT_BLUE("==", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 == std_l4), (ft_l3 == ft_l4), "== if empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // != operator with not empty list
    // ---
    PRINT_BLUE("!=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 != std_l4), (ft_l3 != ft_l4), "!= if empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // < operator with not empty list
    // ---
    PRINT_BLUE("<", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 < std_l4), (ft_l3 < ft_l4), "< if empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // <= operator with not empty list
    // ---
    PRINT_BLUE("<=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 <= std_l4), (ft_l3 <= ft_l4), "<= if empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // > operator with not empty list
    // ---
    PRINT_BLUE(">", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 > std_l4), (ft_l3 > ft_l4), "> if empty list");
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // >= operator with not empty list
    // ---
    PRINT_BLUE(">=", DEBUG_OPERATIONS && VERBOSE);
    // ---
    assert_value_equals((std_l3 >= std_l4), (ft_l3 >= ft_l4), ">= if empty list");
    // ------------------------------------------------------------------------
}

int main(void)
{
    test_constructors();
    test_element_access();
    test_capacity();
    test_modifiers();
    test_operations();
    test_non_member_functions();
    return (0);
}
