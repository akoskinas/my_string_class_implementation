// this file contains the declaration of my_string class

// includes
#include <iostream>

class my_string{
    
private:
    // class constants
    // Q1: why error appears if I don't use `static` below,
    // and I want to use this constant as part of the class
    // for subsequent variable declarations
    // static const int cut_off_size = 32;
    static const int cut_off_size = 32;

    // Q2: if I declare a constant as a class member, then all objects will have it
    // and the memory needed for each object will become larger. How else can I do that?

    // Q3: instead of using a union, I throught to have only one char* that will either point to a
    // memory area in stack or in heap. Could this approach also work?

    union
    {
        char* buffer_{nullptr}; // ptr to the array of char
        char small_buffer_[my_string::cut_off_size];
    };
    std::size_t my_string_size_{0};

    // private methods
    size_t compute_length(const char * ptr);

public:

    // default constructor
    my_string();

    // constructor from a char array
    my_string(const char * c_style_string);

    // copy constructor
    my_string(const my_string &lhs);
    
    // copy assignment operator
    my_string& operator=(const my_string &lhs);

    // move constructor
    my_string(my_string &&rhs);

    // destructor
    ~my_string();
        
    // move assignment operator
    my_string& operator=(my_string &&rhs);
};