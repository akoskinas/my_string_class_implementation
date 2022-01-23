// this file contains the implementation of the my_string class

// includes
#include "my_string.h"
#include <stdio.h>
#include <iostream>

// implementation of the default constructor
my_string::my_string(){
    std::cout << "default constructor" << std::endl;
}

// implementation of the constructor from C-style array
my_string::my_string(const char* c_style_ptr){

    std::cout << "Constructor from C-style array" << std::endl;
    
    // compute size of input string
    size_t c_style_ptr_size = my_string::compute_length(c_style_ptr);

    if (c_style_ptr_size > my_string::cut_off_size){
        // large string --> place it heap
        
        // check that memory allocation was OK
        try {
            this->buffer_ = new (std::nothrow) char[c_style_ptr_size+1];
            for (size_t i =0; i < c_style_ptr_size+1; i++){
                this->buffer_[i] = c_style_ptr[i];
            }
            this->my_string_size_ = c_style_ptr_size;
        }
        catch (std::bad_alloc& ba){
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    } else {
        // small string --> place it in stack
        for (size_t i =0; i < c_style_ptr_size; i++){
            this->small_buffer_[i] = c_style_ptr[i];
        }        
        this->my_string_size_ = c_style_ptr_size;        
    }
}

// copy constructor implementation
my_string::my_string(const my_string &lhs){

    std::cout << "copy constructor" << std::endl;

    if (lhs.my_string_size_ > my_string::cut_off_size){
        // needs heap allocation

        // check that memory allocation was OK
        try {
            this->buffer_ = new (std::nothrow) char[lhs.my_string_size_];
            for (size_t i =0; i < lhs.my_string_size_; i++){
                this->buffer_[i] = lhs.buffer_[i];
            }
            this->my_string_size_ = lhs.my_string_size_;
        }
        catch (std::bad_alloc& ba){
            std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        }
    } else {
        // small string --> place it in stack
        for (size_t i =0; i < lhs.my_string_size_; i++){
            this->small_buffer_[i] = lhs.small_buffer_[i];
        }        
        this->my_string_size_ = lhs.my_string_size_;
    }
}

// implementation of the copy assignment operator
my_string& my_string::operator=(const my_string& lhs){

    std::cout << "copy assignment operator" << std::endl;

    if (this!=&lhs){
        // the above if statement prevents self-copy

        // to prevent memory leakage, call delete on the ptr to the heap
        delete this->buffer_;

        if (lhs.my_string_size_ > my_string::cut_off_size){
            // needs heap allocation
            // check that memory allocation was OK
            try {
                this->buffer_ = new (std::nothrow) char[lhs.my_string_size_];
                for (size_t i =0; i < lhs.my_string_size_; i++){
                    this->buffer_[i] = lhs.buffer_[i];
                }
                this->my_string_size_ = lhs.my_string_size_;
            }
            catch (std::bad_alloc& ba){
                std::cerr << "bad_alloc caught: " << ba.what() << '\n';
            }
        } else {
            // small string --> place it in stack
            for (size_t i =0; i < lhs.my_string_size_; i++){
                this->small_buffer_[i] =  lhs.small_buffer_[i];
            }        
            this->my_string_size_ = lhs.my_string_size_;
        }   
    }
    return *this;
}

// move constructor
my_string::my_string(my_string &&rhs){
    
    std::cout << "move constructor" << std::endl;

    if (rhs.my_string_size_ > my_string::cut_off_size){
        // "steal" the content stored in heap
        this->buffer_ = rhs.buffer_;
        rhs.buffer_ = nullptr;
        this->my_string_size_ = rhs.my_string_size_;
    } else {
        // small string --> place it in stack
        for (size_t i =0; i < rhs.my_string_size_; i++){
            this->small_buffer_[i] = rhs.small_buffer_[i];
        }        
        this->my_string_size_ = rhs.my_string_size_;
    }
}

// move assignment operator
my_string& my_string::operator=(my_string &&rhs){
    
    std::cout << "move assignment operator" << std::endl;

    if (this!=&rhs) {
        // the above if-statement prevents self-move

        if (rhs.my_string_size_ > my_string::cut_off_size){
            // "steal" the content stored in heap
            this->buffer_ = rhs.buffer_;
            rhs.buffer_ = nullptr;
            this->my_string_size_ = rhs.my_string_size_;
        } else {
            // small string --> place it in stack
            for (size_t i =0; i < rhs.my_string_size_; i++){
                this->small_buffer_[i] = rhs.small_buffer_[i];
            }        
            this->my_string_size_ = rhs.my_string_size_;
        }
    }
    return *this;
}

// destructor
my_string::~my_string(){

    std::cout << "destructor" << std::endl;

    if (this->my_string_size_ > my_string::cut_off_size){
        // free heap memory
        delete this->buffer_;
        this->buffer_ = nullptr;
    }
}

// implementation of the private method that calculates if a string is long or not
size_t my_string::compute_length(const char * ptr){
    //std::cout << "computing length" << std::endl;
    size_t counter{0};
    while(ptr[counter]!='\0'){
        counter++;
    }
    return counter;
}