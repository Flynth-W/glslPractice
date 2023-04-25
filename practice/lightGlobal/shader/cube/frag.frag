#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec2 TexCoords;
in vec3 FragPos;
//env
uniform vec3 viewPos;

// texture samplers
uniform sampler2D texture1;

void main()
{
  //old
  // more one texture
	//FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2) * vec4(ourColor ,1.0);
  // only one texture
	//FragColor = texture(texture1, TexCoord) * vec4(ourColor ,1.0);
  //FragColor = texture(texture1, TexCoords);

  //env
  vec3 lightPos=vec3(1.2f, 1.0f, 2.0f);
  vec3 lightColor=vec3(1.0,1.0,1.0);
  vec3 objectColor=vec3(1.0,0.5,0.32);

    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;  
  vec3 result = ( ambient + diffuse + specular ) * objectColor;

  FragColor = vec4(result,1.0);
}
