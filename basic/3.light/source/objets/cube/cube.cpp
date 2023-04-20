#include "cube.hpp"


void Cube::addUniformShader(glm::mat4 *_projection, glm::mat4 *_view){
  projection=_projection;
  shader->setMat4("projection", *projection); 
  view=_view ;
}
void Cube::addShader(const char *vertexShader, const char *fragShader){
  shader=new Shader();
  shader->load(vertexShader, fragShader );
}
void Cube::addBuffer(float *vertices, unsigned int sizeVert, unsigned int *indices, unsigned int sizeInd){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVert, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}
void Cube::addTexture(const char *texture){
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load(texture, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

}
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void Cube::Init(Camera *_camera){
    shader->use();
    shader->setInt("texture1", 0);
};
void Cube::Update(){};
void Cube::Renderer(){
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture1);
  shader->use();
  shader->setMat4("projection", *projection); 
  shader->setMat4("view", *view);
 
  glBindVertexArray(VAO);
  
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));
  shader->setMat4("model", model);

  glDrawArrays(GL_TRIANGLES, 0, 36);
    

};
