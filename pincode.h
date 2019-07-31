#ifndef PINCODE_H
#define PINCODEE_H
#include <iostream>
#include <fstream>
#include <string> 
#include <stdexcept>
#include <regex>
typedef unsigned long size_t;
typedef std::vector<std::string> cvector;

//#include "nbind/nbind.h"

class Pincode       {
    public:
    void Ccode();
    bool Validate(std::string);
    bool Validate(std::string, std::string);
    std::string Random(bool); 
    std::string Random(bool, std::string);
    std::string Generate(int);
    std::string Generate_Invalid(int);
    cvector codes;
};

#endif 

 /* NBIND_CLASS(Telephone){
    construct<>();
    multimethod(Validate, args(std::string), "Validate");
    multimethod(Validate, args(std::string, std::string), "ValidateWithAreaCode");
    multimethod(Random, args(bool), "Random");
    multimethod(Random, args(bool, std::string), "RandomWithAreaCode");
    method(Ccode);
    method(Generate);
    method(Generate_Invalid);
} */