#include <betmine/debug.hh>

void Debug::log(const std::string msg){
    std::cout << "LOG: " << msg << std::endl;
}

void Debug::warning(const std::string msg){
    std::cout << "WARNING: " << msg << std::endl;
}

void Debug::error(const std::string msg){
    std::cerr << "ERROR: " << msg << std::endl;
}