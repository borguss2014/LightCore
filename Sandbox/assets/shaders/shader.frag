#version 330 core

struct Material {
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	float shininess;
};

struct Light {
	vec3 position;
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;

	float cutOff;
	float outerCutOff;
};

out vec4 FragColor;  

//in vec3 ourColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 vertexPos;

//uniform sampler2D ourTexture;

uniform vec3 camPos;
uniform float time;

uniform Material material;
uniform Light light;
  
void main()
{
	

	//Ambient light
	vec3 ambientLight = vec3(texture(material.diffuse, TexCoord)) * light.ambient;

	//Diffuse light
	vec3 lightDir = normalize(light.position - vertexPos);
	float diffuseFactor = max(dot(normalize(Normal), lightDir), 0.0f);

	vec3 diffuseLight = light.diffuse * (diffuseFactor * vec3(texture(material.diffuse, TexCoord)));
	

	//Specular light
	vec3 viewDir = normalize(camPos - vertexPos);
	vec3 reflectedLightDir = reflect(-lightDir, Normal);

	float specularFactor = pow(max(dot(viewDir, reflectedLightDir), 0.0), material.shininess);
	vec3 specularLight = vec3(texture(material.specular, TexCoord)) * specularFactor * light.specular;

	//Emission map
	vec3 emission = vec3(texture(material.emission, TexCoord + vec2(0.0, time) )) * (sin(time) * 0.5 + 0.5) * 2.5;

	//Spotlight (soft edges)
	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon   = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

	diffuseLight  *= intensity;
	specularLight *= intensity;

	//Attenuation
	float dist = length(light.position - vertexPos);
	float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist * dist) );

	ambientLight *= attenuation;
	diffuseLight  *= attenuation;
	specularLight *= attenuation;

	vec3 lightResult;

	if(vec3(texture(material.specular, TexCoord)) == vec3(0.0))
	{
		lightResult = ambientLight + diffuseLight  + specularLight + emission;
	}
	else
	{
		lightResult = ambientLight + diffuseLight + specularLight;
	}

	FragColor = vec4(lightResult * 2, 1.0);
	FragColor = vec4(1.0);
	
}