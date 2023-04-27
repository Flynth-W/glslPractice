#include "./ShaderObj.hpp"
using namespace std;

bool ShaderObj::load(const std::string &vrxFl, const std::string &frgFl){
  // vertex shader
  ifstream is_vs(vrxFl);
  const string f_vs((istreambuf_iterator<char>(is_vs)),istreambuf_iterator<char>());
  const char* vertexShaderSource=f_vs.c_str();

  ifstream is_fs(frgFl);
  const string f_fs((istreambuf_iterator<char>(is_fs)),istreambuf_iterator<char>());
  const char* fragmentShaderSource=f_fs.c_str();

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  // link shaders
  //unsigned int ShdrPrgrm = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram( shaderProgram );
  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
      return false;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  return true;
}

void ShaderObj::use(){
  //int location = glGetUniformLocation(shaderProgram, "");
  //glUniform1f(location, timeValue);

  glUseProgram(shaderProgram);


}

