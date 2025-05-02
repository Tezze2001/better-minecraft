
#ifndef DEBUG__HH
#define DEBUG__HH

#include<iostream>

class Debug{
public:
    static void log(const std::string msg);
    static void warning(const std::string msg);
    static void error(const std::string msg);
};

#endif