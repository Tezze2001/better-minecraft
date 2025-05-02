#ifndef SHADER__HH
#define SHADER__HH

#include <glad/gl.h>

#include <string>

class Shader {
private:
    GLint reference;
    GLint type;
    int8_t status;

public:
    Shader(GLint type, std::string path);
    int8_t getStatus();
    GLint getType();
    GLint getReference();
    GLint compile();
    ~Shader();
};


#endif