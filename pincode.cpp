#include "pincode.h"

using namespace std;
int i = 0;

void Pincode :: Ccode()      {
    std::string temp;
    ifstream in;
	in.open("code.txt");
    for (auto col = 0; col < 155600; col++) {
        in >> temp;
        codes.push_back(temp);
    }
    in.close();
}

bool Pincode::Validate(std::string pin)      {
    bool flag1 = 0;
    bool flag = std::regex_match(pin, std::regex("[0-9]{6}"));
    if(flag == 1)       {
        for(auto i = codes.begin(); i != codes.end(); ++i)      {
            if(*i == pin)     {
                flag1 = 1;
            }
        }
    }
    return flag1;
}

bool Pincode::Validate(std::string pin, std::string code)      {
    bool flag1;
    bool flag = std::regex_match(pin, std::regex(code+"[0-9]{3}"));    
    return flag;    
        if(flag == 1)       {
        for(auto i = codes.begin(); i != codes.end(); ++i)      {
            if(*i == pin)     {
                flag1 = 1;
            }
        }
    }
    return flag1;
}

std::string Pincode::Random(bool x){
    std::string Full_number;
    srand(time(0)+(i++));
    if(x==1)        { 
        Full_number += Generate(6);
    }
    else        {
        Full_number += Generate_Invalid(5);
    }
    return Full_number;
}

std::string Pincode::Random(bool x, std::string code){
    std::string Full_number = code;
    srand(time(0)+(i++));
    if(x==1)        { 
        Full_number += Generate(4);
    }
    else        {
        Full_number += Generate_Invalid(rand()%3);
    }
    return Full_number;
}

std::string Pincode::Generate(int length)        {
    auto randchar = []() -> char    {
        const char charset[] = "0123456789";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length-1,0);
    srand(time(0) + i++);
    std::generate_n(str.begin(), length-1, randchar);
    return str;
}

std::string Pincode::Generate_Invalid(int length)        {
    auto randchar = []() -> char    {
        const char charset[] =
        "1234567890";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    srand(time(0)+i++);
    std::generate_n( str.begin(), length, randchar );
    if(Validate(str))
        Generate_Invalid(length);
    return str;
}