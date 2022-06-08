#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include "../sources/map.hpp"
#include "../sources/stack.hpp"
#include "../sources/vector.hpp"
#include "./map/mUtils.hpp"
#include<ctime>
#include<cstdlib>

# define RESET			"\033[0m"
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define ROJO			"\033[31m"

template <class T>
void print_vector(std::vector<T> &vector)
{
    std::cout << "std Vector" << std::endl;
    std::cout << "[ "; 
    for(size_t i = 0; i < vector.size(); i++)
        std::cout << GREEN << vector.at(i) << RESET << ", ";
    std::cout << ']' << std::endl;
    std::cout << "std Vector size: " << vector.size() << std::endl;
    std::cout << "std Vector capacity: " << vector.capacity() << std::endl;
}

template <class T>
void print_vector(ft::vector<T> &vector)
{
    std::cout << "Ft Vector" << std::endl;
    std::cout << "[ "; 
    for(size_t i = 0; i < vector.size(); i++)
        std::cout << GREEN << vector.at(i) << RESET << ", ";
    std::cout << ']' << std::endl;
    std::cout << "ft Vector size: " << vector.size() << std::endl;
    std::cout << "ft Vector capacity: "<< vector.capacity() << std::endl;
}

/* --- Map -- */

template <class T, class U>
void isEmpty(std::map<T, U> &map)
{
    map.empty() ? std::cout << ROJO << "Map is empty" << RESET << std::endl : std::cout << GREEN << "Map is not empty." << RESET << std::endl ;
}

template <class T, class U>
void isEmpty(ft::map<T, U> &map)
{
    map.empty() ? std::cout << ROJO << "Map is empty" << RESET << std::endl : std::cout << GREEN << "Map is not empty." << RESET << std::endl ;
}

template <class T, class U>
void printMapInfo(std::map<T, U> &map)
{
    isEmpty(map);
    std::cout << "std::Map size: " << map.size() << '\n';
    std::cout << "std::Map max_size: " << map.max_size() << '\n';
}

template <class T, class U>
void printMapInfo(ft::map<T, U> &map)
{
    isEmpty(map);
    std::cout << "std::Map size: " << map.size() << '\n';
    std::cout << "std::Map max_size: " << map.max_size() << '\n';
}

template <class T, class U>
void printMapValues(std::map<T, U> &map)
{
    std::map<int, std::string>::iterator it;
    std::cout << CYAN << "std Map contains:\n" << RESET;
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

template <class T, class U>
void printMapValues(ft::map<T, U> &map)
{
    ft::map<int, std::string>::iterator it;
    std::cout << CYAN << "ft Map contains:\n" << RESET;
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

void populateMap(std::map<int, std::string> &map, int seed)
{
    std::cout << std::endl;
    std::cout << "Populating std::map..." << std::endl;
    for(int i = seed; i < seed + 10; i++)
        map.insert(std::make_pair(i, std::to_string(i)));
    std::cout << std::endl;  
}

void populateMap(ft::map<int, std::string> &map, int seed)
{
    std::cout << std::endl;
    std::cout << "Populating ft::map..." << std::endl;
    for(int i = seed; i < seed + 10; i++)
        map.insert(ft::make_pair(i, std::to_string(i)));
    std::cout << std::endl;  
}

/* void printMapInfo(std::map<int, std::string> &map)
{

} */

int main(int ac, char**av)
{
    if (ac != 2)
	{
		std::cerr << "Usage: ./program seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		return 1;
	}
	const int seed = atoi(av[1]);
	srand(seed);
    int x = rand();

    std::vector<int> sv(x, x);
    ft::vector<int> fv(x, x);

    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                          VECTOR                                           |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    std::cout << MAGENTA << "CAPACITY" << RESET << std::endl;
    std::cout << YELLOW << "size()" << RESET << std::endl;   std::cout << "Std: " << sv.size() << std::endl;  std::cout << "Ft: " << fv.size() << std::endl;
    std::cout << YELLOW << "max_size()"  RESET << std::endl;   std::cout << "Std: " << sv.max_size() << std::endl;  std::cout << "Ft: " << fv.max_size() << std::endl;
    std::cout << YELLOW << "capacity()"  RESET << std::endl;   std::cout << "Std: " << sv.capacity() << std::endl;  std::cout << "Ft: " << fv.capacity() << std::endl;
    std::cout << YELLOW << "empty()"  RESET << std::endl;   std::cout << "Std: " << sv.empty() << std::endl;  std::cout << "Ft: " << fv.empty() << std::endl;
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std actual size: " << sv.size() << std::endl;  std::cout << "Ft actual size: " << fv.size() << std::endl;
    sv.resize(x/2);
    fv.resize(x/2);
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std new size: " << sv.size() << std::endl;  std::cout << "Ft new size: " << fv.size() << std::endl;
    std::cout << YELLOW << "resize()"  RESET << std::endl;   std::cout << "Std capacity: " << sv.capacity() << std::endl;  std::cout << "Ft capacity: " << fv.capacity() << std::endl;

    std::cout << YELLOW << "reserve()"  RESET << std::endl;   
    std::cout << "Actual std capacity: " << sv.capacity() << std::endl;  std::cout << "Actual std size: " << sv.size() << std::endl;
    std::cout << "Actual ft capacity: " <<  fv.capacity() << std::endl;  std::cout << "Actual ft size: " << fv.size() << std::endl;
    std::cout << CYAN << "reserve(x+(x/2))"  RESET << std::endl; 
    sv.reserve(x+(x/2));
    fv.reserve(x+(x/2));
    std::cout << "New std capacity: " << sv.capacity() << std::endl;  std::cout << "New std size: " << sv.size() << std::endl;
    std::cout << "New ft capacity: " << fv.capacity() << std::endl;  std::cout << "New ft size: " << fv.size() << std::endl;
    
    std::cout << std::endl;
    std::cout << MAGENTA << "MODIFIERS" << RESET << std::endl;
    std::cout << YELLOW << "assign(10, )"  RESET << std::endl;
    sv.assign(10, seed);
    fv.assign(10, seed);
    print_vector(sv);
    print_vector(fv);
    std::cout << YELLOW << "push_back(1111)"  RESET << std::endl;
    sv.push_back(1111);
    fv.push_back(1111);
    print_vector(sv);
    print_vector(fv);
    std::cout << YELLOW << "pop_back()"  RESET << std::endl;
    sv.pop_back();
    fv.pop_back();
    print_vector(sv);
    print_vector(fv);
    std::cout << YELLOW << "clear()"  RESET << std::endl;
    fv.clear();
    sv.clear();
    std::cout << "Std size: " << sv.size() << std::endl;  std::cout << "Ft size: " << fv.size() << std::endl;
    std::cout << "Std capacity: " << sv.capacity() << std::endl;  std::cout << "Ft capacity: " << fv.capacity() << std::endl;
    std::cout << YELLOW << "insert(vector.begin(), 10, " + std::to_string(seed+1) << ")" << RESET << std::endl;
    sv.insert(sv.begin(), 10, seed + 1);
    fv.insert(fv.begin(), 10, seed + 1);
    print_vector(sv);
    print_vector(fv);
    std::cout << YELLOW << "erase(vector.begin(), vector.begin()+ 3)"  RESET << std::endl;
    sv.erase(sv.begin(), sv.begin()+ 3);
    fv.erase(fv.begin(), fv.begin()+ 3);
    print_vector(sv);
    print_vector(fv);

    std::cout << std::endl;
    std::cout << MAGENTA << "ELEMENT ACCESS" << RESET << std::endl;
    std::cout << YELLOW << "operator[]"  RESET << std::endl;
    std::cout << "std:vector[0]: " << sv[0] << std::endl;
    std::cout << "ft:vector[0]: " << fv[0] << std::endl;
    std::cout << YELLOW << "at()"  RESET << std::endl;
    std::cout << "std:vector.at(): " << sv.at(0) << std::endl;
    std::cout << "ft:vector.at(): " << fv.at(0) << std::endl;
    std::cout << YELLOW << "front()"  RESET << std::endl;
    std::cout << "std:vector.front(): " << sv.front() << std::endl;
    std::cout << "ft:vector.front(): " << fv.front() << std::endl;
    std::cout << YELLOW << "back()"  RESET << std::endl;
    std::cout << YELLOW << "a little push_back first...42"  RESET << std::endl;
    sv.push_back(42);
    fv.push_back(42);
    print_vector(sv);
    print_vector(fv);
    std::cout << "std:vector.back(): " << sv.back() << std::endl;
    std::cout << "ft:vector.back(): " << fv.back() << std::endl;


    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                          STACK                                            |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                          MAP                                              |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    std::map<int, std::string> smap;
	ft::map<int, std::string> fmap;
	ft::map<int, std::string>::iterator fit;
	std::map<int, std::string>::iterator sit;

    populateMap(smap, seed);
    populateMap(fmap, seed);
    sit = smap.begin();
    fit = fmap.begin();
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;

    std::cout << MAGENTA << "CAPACITY" << RESET << std::endl;
    printMapInfo(smap);
    printMapInfo(fmap);

    std::cout << std::endl;
    std::cout << MAGENTA << "ELEMENT ACCESS" << RESET << std::endl;
    std::cout << YELLOW << "operator[] (const key_type& k) - map[seed+3]"  RESET << std::endl;
    std::cout << "result: " CYAN << smap[seed + 3] << RESET << std::endl;
    std::cout << "result: " CYAN << fmap[seed + 3] << RESET << std::endl;
    
    std::cout << std::endl;
    std::cout << MAGENTA << "MODIFIERS" << RESET << std::endl;
    std::cout << YELLOW << "insert(const value_type& val) - std::make_pair(x, 'fortytwo')"  RESET << std::endl;    
    smap.insert(std::make_pair(x, "fortytwo"));
    fmap.insert(ft::make_pair(x, "fortytwo"));
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(const key_type& k) - map.erase(seed + 2)" << RESET << std::endl;
    smap.erase(seed + 2);
    fmap.erase(seed + 2);
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(iterator position) - erase(map.begin());" << RESET << std::endl; 
    smap.erase(sit);
    fmap.erase(fit);
    printMapValues(smap);
    printMapValues(fmap);
    std::cout << std::endl;
    std::cout << YELLOW << "erase(iterator first, iterator last) - erase(it -> 15 , it -> 17)" << RESET << std::endl;
    sit=smap.find(15);
	std::map<int, std::string>::iterator sit2 = smap.find(17);
    fit=fmap.find(15);
    ft::map<int, std::string>::iterator fit2 = fmap.find(17);     
    smap.erase(sit, sit2);
    fmap.erase(fit, fit2);
    printMapValues(smap);
    printMapValues(fmap);

    std::cout << std::endl;
    std::cout << YELLOW << "swap(map& x)" << RESET << std::endl;
    std::map<int, std::string> smap2;
    populateMap(smap2, seed *2);
    ft::map<int, std::string> fmap2;
    populateMap(fmap2, seed *2);

    std::cout << BLUE << "Original STD values" << RESET << std::endl;
    std::cout << "smap: ";
    printMapValues(smap);
    std::cout << "smap2: ";
    printMapValues(smap2);
    smap.swap(smap2);
    std::cout << BLUE << "Swapped STD values" << RESET << std::endl;
    std::cout << "smap: ";
    printMapValues(smap);
    std::cout << "smap2: ";
    printMapValues(smap2);
    std::cout << BLUE << "Original FT values" << RESET << std::endl;
    std::cout << "fmap: ";
    printMapValues(fmap);
    std::cout << "fmap2: ";
    printMapValues(fmap2);
    fmap.swap(fmap2);
    std::cout << BLUE << "Swapped FT values" << RESET << std::endl;
    std::cout << "fmap: ";
    printMapValues(fmap);
    std::cout << "fmap2: ";
    printMapValues(fmap2);

    std::cout << std::endl;
    std::cout << YELLOW << "clear()" << RESET << std::endl;
    smap.clear();
    fmap.clear();
    printMapInfo(smap);
    printMapInfo(fmap);

    populateMap(smap, seed);
    populateMap(fmap, seed);
    printMapValues(smap);
    printMapValues(fmap);

    std::cout << std::endl;
    std::cout << MAGENTA << "OPERATIONS" << RESET << std::endl;    
    std::cout << YELLOW << "find(const key_type& k) - map.find(seed + 3) - Returns an iterator pointing that key" << RESET << std::endl;
    sit = smap.find(seed + 3);
    fit = fmap.find(seed + 3);
    std::cout << CYAN << "STD MAP ITERATOR is now pointing to: " << sit->first << "=>" << sit->second << RESET << std::endl;
    std::cout << CYAN << "FT MAP ITERATOR is now pointing to: " << fit->first << "=>" << fit->second << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "count (const key_type& k) - map.count(seed + 3) - Returns number of element with specific key" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.count(seed + 2) << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.count(seed + 2) << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "lower_bound (const key_type& k) - map.lower_bound(seed + 3) - Returns iterator to the element with specific key" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.lower_bound(seed + 3)->first << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.lower_bound(seed + 3)->first << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "upper_bound (const key_type& k) - map.upper_bound(seed + 3) - An iterator to the the first element in the container whose key is considered to go after k" << RESET << std::endl;
    std::cout <<"result: " CYAN << smap.upper_bound(seed + 3)->first << RESET << std::endl;
    std::cout <<"result: " CYAN << fmap.upper_bound(seed + 3)->first << RESET << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "equal_range (const key_type& k) - map.equal_range(seed + 3) - The function returns a pair of map iterators" << RESET << std::endl;
    std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> sRet = smap.equal_range(seed + 3);
    ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> fRet = fmap.equal_range(seed + 3);
    std::cout << "STD lower_bound points to: ";
    std::cout << CYAN << sRet.first->first << " => " << sRet.first->second << RESET << '\n';
    std::cout << "STD upper_bound points to: ";
    std::cout << CYAN << sRet.second->first << " => " << sRet.second->second << RESET << '\n';
    std::cout << "FT lower_bound points to: ";
    std::cout << CYAN << fRet.first->first << " => "  << fRet.first->second << RESET << '\n';
    std::cout << "FT upper_bound points to: ";
    std::cout << CYAN << fRet.second->first << " => " << fRet.second->second << RESET << '\n';
}