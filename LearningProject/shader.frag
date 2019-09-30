#version 330 core

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light {
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

out vec4 FragColor;  

//in vec3 ourColor;
//in vec2 TexCoord;
in vec3 Normal;
in vec3 vertexPos;

//uniform sampler2D ourTexture;

uniform vec3 camPos;

uniform Material material;
uniform Light light;
  
void main()
{
	//Ambient light
	vec3 ambientLight = material.ambient * light.ambient;

	//Diffuse light
	vec3 lightDir = normalize(light.position - vertexPos);
	float diffuseFactor = max(dot(normalize(Normal), lightDir), 0.0f);
	vec3 diffuseLight = light.diffuse * (diffuseFactor * material.diffuse);
	

	//Specular light
	vec3 viewDir = normalize(camPos - vertexPos);
	vec3 reflectedLightDir = reflect(-lightDir, Normal);

	float specularFactor = pow(max(dot(viewDir, reflectedLightDir), 0.0), material.shininess);
	vec3 specularLight = material.specular * specularFactor * light.specular;

	vec3 lightResult = ambientLight + diffuseLight + specularLight;

	FragColor = vec4(lightResult, 1.0);
}