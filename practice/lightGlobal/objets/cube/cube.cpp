#include "cube.hpp"
unsigned int loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}


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
    texture1 = loadTexture("1298130.jpg");
    texture2 = loadTexture("container2_specular.png");
}
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void Cube::Init(Camera *_camera){
    shader->use();
    shader->setInt("texture1", 0);
    camera=_camera;
    // projection:: global
    //glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    //shader->setMat4("projection", projection); 
};
void Cube::Update(){};
void Cube::Renderer(){
    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    shader->use();
    shader->setMat4("projection", *projection); 
    shader->setMat4("view", *view);
    shader->setVec3("viewPos", camera->cameraPos);
    //materal
    shader->setInt("material.diffuse", 0);
    shader->setInt("material.specular", 1);
    shader->setFloat("material.shininess", 64.0f);
  //light global (sun)
  shader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
  shader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
  shader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
  shader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        // spotLight
        shader->setVec3("spotLight.position", camera->cameraPos);
        shader->setVec3("spotLight.direction", camera->cameraFront);
        shader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        shader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        shader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        shader->setFloat("spotLight.constant", 1.0f);
        shader->setFloat("spotLight.linear", 0.09f);
        shader->setFloat("spotLight.quadratic", 0.032f);
        shader->setFloat("spotLight.cutOff", glm::cos(glm::radians(5.5f)));
        shader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(9.5f)));     
   glBindVertexArray(VAO);
   // model objet model::local
   glm::mat4 model = glm::mat4(1.0f);
   model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));
   shader->setMat4("model", model);

   glDrawArrays(GL_TRIANGLES, 0, 36);
    

};
