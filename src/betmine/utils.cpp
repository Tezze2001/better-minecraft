#include <betmine/utils.hh>
#include <betmine/const.hh>
#include <betmine/debug.hh>

#include <fstream>
#include <sstream>

u_int8_t readLinesFromFile(const std::string& path, std::string& text){
    std::ifstream f(path, std::ios::in | std::ios::binary);

    // Check if the file is successfully opened
    if (!f.is_open()) {
        Debug::error("Error opening the file: " + path);
        return ERROR_CODE;
    }

    std::stringstream buffer;
    buffer << f.rdbuf();  // reads the entire file into the buffer
    text = buffer.str();
    f.close();

    // Remove UTF-8 BOM if present
    if (text.size() >= 3 &&
        static_cast<unsigned char>(text[0]) == 0xEF &&
        static_cast<unsigned char>(text[1]) == 0xBB &&
        static_cast<unsigned char>(text[2]) == 0xBF) {
        text = text.substr(3);
    }

    
    return SUCCESS_CODE;
}