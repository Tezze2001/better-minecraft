
#include <betmine/shaders/shader_program.hh>
#include <fstream>
#include <sstream>
#include <string>

ShaderProgram::ShaderProgram(const std::string& vertPath, const std::string& fargPath) : ShaderProgram(vertPath, "", fargPath) {}

ShaderProgram::ShaderProgram(const std::string& vertPath, const std::string& geomPath, const std::string& fargPath) : ShaderProgram(vertPath, "", "", geomPath, fargPath) {}

ShaderProgram::ShaderProgram(const std::string& vertPath, const std::string& tessContPath, const std::string& tessEvalPath, const std::string& geomPath, const std::string& fargPath) {
    if (!vertPath.empty())
        vertexShader = Shader(GL_VERTEX_SHADER, vertPath);
    if (!tessContPath.empty())
        tesselationControlShader = Shader(GL_TESS_CONTROL_SHADER, tessContPath);
    if (!tessEvalPath.empty())
        tesselationEvaluationShader = Shader(GL_TESS_EVALUATION_SHADER, tessEvalPath);
    if (!geomPath.empty())
        geometryShader = Shader(GL_GEOMETRY_SHADER, geomPath);
    if (!fargPath.empty())
        fragmentShader = Shader(GL_FRAGMENT_SHADER, fargPath);
}
/*
int8_t ShaderProgram::compile(){
    if (vertexShader != 0){
        glCompileShader(vertexShader);
        GLint isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            GLchar errorLog[maxLength];
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, errorLog);
            
            Debug::error("Error during compiling the vertex shader: " + (std::string) errorLog);

            glDeleteShader(vertexShader);
            return;
        }

    }
    
    if (tesselationControlShader != 0) {
        glCompileShader(tesselationControlShader);

        GLint isCompiled = 0;
        glGetShaderiv(tesselationControlShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(tesselationControlShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            GLchar errorLog[maxLength];
            glGetShaderInfoLog(tesselationControlShader, maxLength, &maxLength, errorLog);
            
            Debug::error("Error during compiling the tesselation control shader: " + (std::string) errorLog);

            glDeleteShader(tesselationControlShader);
            return;
        }
    }

    if (tesselationEvaluationShader != 0) {
        glCompileShader(tesselationEvaluationShader);


        GLint isCompiled = 0;
        glGetShaderiv(tesselationEvaluationShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(tesselationEvaluationShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            GLchar errorLog[maxLength];
            glGetShaderInfoLog(tesselationEvaluationShader, maxLength, &maxLength, errorLog);

            Debug::error("Error during compiling the tesselation evaluation shader: " + (std::string) errorLog);

            glDeleteShader(tesselationEvaluationShader);
            return;
        }
    }

    if (geometryShader != 0) {
        glCompileShader(geometryShader);


        GLint isCompiled = 0;
        glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(geometryShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            GLchar errorLog[maxLength];
            glGetShaderInfoLog(geometryShader, maxLength, &maxLength, errorLog);

            Debug::error("Error during compiling the geometry shader: " + (std::string) errorLog);

            glDeleteShader(geometryShader);
            return;
        }
    }

    if (fragmentShader != 0){
        glCompileShader(fragmentShader);


        GLint isCompiled = 0;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            GLchar errorLog[maxLength];
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, errorLog);

            Debug::error("Error during compiling the fragment shader: " + (std::string) errorLog);

            glDeleteShader(fragmentShader);
            return;
        }
    }
}
*/
void ShaderProg::link(){
    shaderProgram = glCreateProgram();

    if (vertexShader != 0)
        glAttachShader(shaderProgram, vertexShader);
    
    if (tesselationControlShader != 0)
        glAttachShader(shaderProgram, tesselationControlShader);
    
    if (tesselationEvaluationShader != 0)    
        glAttachShader(shaderProgram, tesselationEvaluationShader);

    if (geometryShader != 0)
        glAttachShader(shaderProgram, geometryShader);

    if (fragmentShader != 0)
        glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    
    GLint isLinked = 0;

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);
    Debug::log("aaaaaaaaaaa");
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        GLchar errorLog[maxLength];
        glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, errorLog);

        Debug::error("Error during linking the program: " + (std::string) errorLog);

        glDeleteProgram(shaderProgram);
    }

}

void ShaderProg::useProgram(){
    glUseProgram(shaderProgram);
}

ShaderProg::~ShaderProg(){
    glDeleteShader(vertexShader);
    glDeleteShader(tesselationControlShader);
    glDeleteShader(tesselationEvaluationShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);

    glDeleteProgram(shaderProgram);
}
