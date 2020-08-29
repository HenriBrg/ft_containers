#ifndef TESTER_HPP
#define TESTER_HPP

# include "../Containers/Utils/Ressources.hpp"
# include "../Containers/Map/includes/Map.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <string>
# include <memory>
# include <stdlib.h>
# include <sstream>

/*
** Summary:
** --- 1. Macros
** --- 2. Constants
** --- 3. List
** --- 4. Queue
** --- 5. Stack
** --- 6. Vector
** --- 7. Map
** --- x. Other
*/

// ----------------------------------------------------------------

/*
** --- 1. Macros
*/

# define PRINT_ERROR(msg)   std::cout << RED_C << "KO : " << msg << RESET << std::endl;
# define PASS_SUCCESS(feature)  std::cout << GREEN_C << "OK : " << feature << RESET << std::endl << std::endl;

// ----------------------------------------------------------------

/*
** --- 2. Constants
*/

#define OK 0
#define KO 1

// ----------------------------------------------------------------

/*
** --- 3. List
*/

template <class STD, class FT>
void assert_list_equals(STD std, FT ft, std::string const &feature)
{
	if (std.empty() && ft.empty())
	{
    	PASS_SUCCESS(feature)
		return;
	}
	else if (std.size() != ft.size())
	{
		PRINT_ERROR("error size")
		return;
	}
    else
    {
        typename STD::iterator std_ite = std.begin();
        typename FT::iterator ft_ite = ft.begin();

        if (std.size() != 0) {
            for (; std_ite != std.end(); ++std_ite, ++ft_ite)
            {
                if (*std_ite != *ft_ite)
                {
                    PRINT_ERROR("error content");
                    return;
                }
            }
        }
        PASS_SUCCESS(feature)
    }
}

template <class list>
int display_list(list l, std::string name, const int LOG)
{
    if (!LOG)
        return (OK);

    int index;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    ss1 << std::string(name.length(), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	typename list::iterator it = l.begin();

    while (it != l.end())
    {
        int len_content = std::to_string(*it).length();
        int len_index = std::to_string(index).length();
        ss1 << "--" << index << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << std::to_string(*it) << RESET << " |" << "-->";
        it++;
        index++;
    }
    ss2 << CYAN_C << "NULL" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
    return (OK);
}

template <class list>
void init_list(list &l, size_t n)
{
    for (size_t i = 1; i <= n; ++i)
        l.push_back(i);
}

// ----------------------------------------------------------------

/*
** --- 4. Queue
*/

template <class queue>
void display_queue(queue q, std::string name, const int LOG)
{
	if (!LOG)
        return ;

    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    int index = 0;

    ss1 << std::string(name.length(), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	ss1 << "        ";
	ss2 << CYAN_C << "front" << RESET << "-->";

	for (size_t i = 0; i < q.size(); i++)
	{
		typename queue::value_type tmp = q.front();

        int len_content = std::to_string(tmp).length();
        int len_index = std::to_string(index).length();

		ss1 << "--" << index << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << std::to_string(tmp) << RESET << " |" << "-->";

        index++;

		q.pop();
		q.push(tmp);
	}

    ss2 << CYAN_C << "back" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
}


template <class STD, class FT>
void assert_queue_equals(STD std, FT ft, std::string const &feature)
{
	if (std.empty() && ft.empty())
	{
    	PASS_SUCCESS(feature)
		return;
	}
	else if (std.size() != ft.size())
	{
		PRINT_ERROR("error size")
		return;
	}
    else
    {
		for (size_t i = 0; i < std.size(); i++)
		{
			typename STD::value_type tmp_std = std.front();
			typename FT::value_type tmp_ft = ft.front();
			if (tmp_std != tmp_ft)
			{
				PRINT_ERROR("error content");
				return;
			}
			std.pop();
			std.push(tmp_std);
			ft.pop();
			ft.push(tmp_ft);
		}
        PASS_SUCCESS(feature)
    }
}

// ----------------------------------------------------------------

/*
** --- 5. Stack
*/


template <class stack>
void display_stack(stack s, std::string name, const int LOG)
{
	if (!LOG)
        return ;

    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    int index = 0;

    ss1 << std::string(name.length(), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	ss1 << "        ";
	ss2 << CYAN_C << "front" << RESET << "-->";

	stack save;
	size_t size = s.size();

	for (size_t i = 0; i < size; i++)
	{
		typename stack::value_type tmp = s.top();
        int len_content = std::to_string(tmp).length();
        int len_index = std::to_string(index).length();
		ss1 << "--" << index << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << std::to_string(tmp) << RESET << " |" << "-->";
        index++;

		s.pop();
		save.push(tmp);
	}
	for (size_t i = 0; i < size; i++)
	{
		typename stack::value_type tmp = save.top();
		s.push(tmp);
	}
    std::cout << std::endl;

    ss2 << CYAN_C << "back" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
}

template <class STD, class FT>
void assert_stack_equals(STD std, FT ft, std::string const &feature)
{
	if (std.empty() && ft.empty())
	{
    	PASS_SUCCESS(feature)
		return;
	}
	else if (std.size() != ft.size())
	{
		PRINT_ERROR("error size")
		return;
	}
    else
    {
		STD std_save;
		FT ft_save;
		size_t size = std.size();

		if (std.size() != ft.size())
		{
			PRINT_ERROR("error size")
			return;
		}
		for (size_t i = 0; i < size; i++)
		{
			typename STD::value_type tmp_og = std.top();
			typename FT::value_type tmp_me = ft.top();
			if (tmp_og != tmp_me)
			{
				PRINT_ERROR("error content")
				return;
			}
			std_save.push(tmp_og);
			ft_save.push(tmp_me);
			std.pop();
			ft.pop();
		}
		for (size_t i = 0; i < size; i++)
		{
			typename STD::value_type tmp_og = std_save.top();
			typename FT::value_type tmp_me = ft_save.top();
			std.push(tmp_og);
			ft.push(tmp_me);
			std_save.pop();
			ft_save.pop();
		}
		PASS_SUCCESS(feature);
    }
}

// ----------------------------------------------------------------

/*
** --- 6. Vector
*/

template <class STD, class FT>
void assert_vector_equals(STD std, FT ft, std::string const &feature)
{
	if (std.empty() && ft.empty())
	{
    	PASS_SUCCESS(feature)
		return;
	}
	else if (std.size() != ft.size())
	{
		PRINT_ERROR("error size")
		return;
	}
    else
    {
        typename STD::iterator std_ite = std.begin();
        typename FT::iterator ft_ite = ft.begin();

        if (std.size() != 0)
		{
            for (; std_ite != std.end(); ++std_ite, ++ft_ite)
            {
                if (*std_ite != *ft_ite)
                {
                    PRINT_ERROR("error content");
                    return;
                }
            }
        }
        PASS_SUCCESS(feature)
    }
}

template <class vector>
void display_vector(vector v, std::string name, const int LOG)
{
    if (!LOG)
        return ;

    int index;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    ss1 << std::string(name.length(), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	typename vector::iterator it = v.begin();

    while (it != v.end())
    {
        int len_content = std::to_string(*it).length();
        int len_index = std::to_string(index).length();
        ss1 << "--" << index << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << std::to_string(*it) << RESET << " |" << "-->";
        it++;
        index++;
    }
	std::cout << std::endl;
    ss2 << CYAN_C << "NULL" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
}

template <class vector>
void init_vector(vector &v, size_t n)
{
    for (size_t i = 1; i <= n; ++i)
        v.push_back(i);
}

// ----------------------------------------------------------------

/*
** --- 7. Map
*/

template <class STD, class FT>
void assert_map_equals(STD std, FT ft, std::string const &feature)
{
	if (std.empty() && ft.empty())
	{
        std::cout << "EMPTY" << std::endl;
    	PASS_SUCCESS(feature)
		return;
	}
	else if (std.size() != ft.size())
	{
                std::cout << "SIZE" << std::endl;

		PRINT_ERROR("error size")
		return;
	}
    else
    {
                std::cout << "ELSE" << std::endl;

        typename STD::iterator std_ite = std.begin();
        typename FT::iterator ft_ite = ft.begin();

        if (std.size() != 0)
		{
            for (; std_ite != std.end(); ++std_ite, ++ft_ite)
            {
                if ((*std_ite).first != (*ft_ite).first)
                {
                    PRINT_ERROR("error content");
                    return;
                }
            }
        }
        PASS_SUCCESS(feature)
    }
}

template<typename key_type, typename value_type>
void display_map_ft(ft::Map<key_type, value_type> &m, std::string name, const int LOG)
{
	if (!LOG)
        return ;

    int index;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    ss1 << std::string((name.length()), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	typename ft::Map<key_type, value_type>::iterator it = m.begin();
	typename ft::Map<key_type, value_type>::iterator ite = m.end();

	while (it != ite)
    {
        int len_content = 1;
        int len_index = 1;
        ss1 << "--" << (*it).first << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << (*it).second << RESET << " |" << "-->";
        ++it;
        ++index;
    }
	std::cout << std::endl;
    ss2 << CYAN_C << "NULL" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
}

template<class map>
void display_map_std(map m, std::string name, const int LOG)
{
	if (!LOG)
        return ;

    int index;
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;

    ss1 << std::string((name.length()), ' ') << "   ";
    ss2 << name << " = ";
    index = 0;

	typename map::iterator it = m.begin();
	typename map::iterator ite = m.end();

	while (it != ite)
    {
        int len_content = 1;
        int len_index = 1;
        ss1 << "--" << (*it).first << std::string(len_content - len_index, '-') << "--" << "   ";
        ss2 << "| " << CYAN_C << (*it).second << RESET << " |" << "-->";
        ++it;
        ++index;
    }
	std::cout << std::endl;
    ss2 << CYAN_C << "NULL" << RESET;
    std::cout << ss1.str() << std::endl;
    std::cout << ss2.str() << std::endl;
    std::cout << std::endl;
}

// ----------------------------------------------------------------

/*
** --- x. Other
*/

std::string getEnvVar( std::string const & key )
{
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

template <typename STD, typename FT>
void assert_value_equals(STD std, FT ft, std::string const &feature)
{
	if (std == ft)
    	PASS_SUCCESS(feature)
	else
		PRINT_ERROR(feature)
    return;
}

#endif
