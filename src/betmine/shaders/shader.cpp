

#include <betmine/shaders/shader.hh>
#include <glad/gl.h>
#include <string>
#include <betmine/utils.hh>
#include <betmine/debug.hh>
#include <betmine/const.hh>

Shader::Shader(GLint type, std::string path){
    this->type = type;
    std::string source;
    
    int8_t result = readLinesFromFile(path, source);

    if(result == ERROR_CODE){
        status = ERROR_CODE;
        return;
    }

    reference = glCreateShader(type);

    if(reference == 0){
        Debug::error("this type of shader is not allowed");
        status = ERROR_CODE;
        return;
    }

    const char* src = source.c_str();
    glShaderSource(type, 1, &src, NULL);
}

int8_t Shader::getStatus(){
    return status;
}

GLint Shader::getType(){
    return type;
}

GLint Shader::getReference(){
    return reference;
}


Shader::~Shader(){
    if(reference != 0)
        glDeleteShader(reference);
}


