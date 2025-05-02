#ifndef SHADER_PROGRAM_HH

#define SHADER_PROGRAM_HH

#include <glad/gl.h>
#include <debug.hh>
#include <betmine/shaders/shader.hh>

class ShaderProgram{
private:
    Shader vertexShader;
    Shader tesselationControlShader;
    Shader tesselationEvaluationShader;
    Shader geometryShader;
    Shader fragmentShader;
    GLuint shaderProgram = 0;

    int8_t compile();
    void link();


public:
    ShaderProgram(const std::string& vertPath, const std::string& tessContPath, const std::string& tessEvalPath, const std::string& geomPath, const std::string& fargPath);
    ShaderProgram(const std::string& vertPath, const std::string& geomPath, const std::string& fargPath);
    ShaderProgram(const std::string& vertPath, const std::string& fargPath);
    ~ShaderProgram();
    void useProgram();
};

#endif