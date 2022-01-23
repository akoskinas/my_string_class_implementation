#include "my_string.h"
#include <iostream>

int main(){
    std::cout << "my_string class exercise"<< std::endl;
    
    std::cout << "-------- Test 1:-----------" << std::endl;
    std::cout << "Testing the default constructor" << std::endl;
    my_string a;
    std::cout << "End of Test 1" << std::endl;

    std::cout << "-------- Test 2:-----------" << std::endl;
    std::cout << "Testing the constructor from C-style array" << std::endl;
    my_string b{"a C-style array"};
    my_string c{"a second C-style array, that in fact is very very very long"};
    std::cout << "End of Test 2" << std::endl;

    std::cout << "-------- Test 3:-----------" << std::endl;
    std::cout << "Testing the class copy constructor" << std::endl;
    my_string d{b};
    std::cout << "End of Test 3" << std::endl;

    std::cout << "-------- Test 4:-----------" << std::endl;
    std::cout << "Testing the class copy assignment" << std::endl;
    c = b;
    std::cout << "End of Test 4" << std::endl;

    std::cout << "-------- Test 5:-----------" << std::endl;
    std::cout << "Testing the class move constructor" << std::endl;
    my_string e{std::move(c)};
    std::cout << "End of Test 5" << std::endl;

    std::cout << "-------- Test 6:-----------" << std::endl;
    std::cout << "Testing the class move assignment" << std::endl;
    b = std::move(a);
    std::cout << "End of Test 6" << std::endl;

    std::cout << "-------- Test 7:-----------" << std::endl;
    std::cout << "Testing the class destructor explicitly" << std::endl;
    c.~my_string();
    std::cout << "End of Test 7" << std::endl;

    return 0;
}