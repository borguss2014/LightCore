#version 330 core

out vec4 FragColor;  

//in vec3 ourColor;
//in vec2 TexCoord;
in vec3 Normal;
in vec3 vertexPos;

//uniform sampler2D ourTexture;

uniform vec3 lightColor;
uniform vec3 objectColor;

uniform vec3 lightPos;
uniform vec3 camPos;
  
void main()
{
    //FragColor = vec4(ourColor, 1.0);
	//FragColor = texture(ourTexture, TexCoord);

	vec3 lightDir = normalize(lightPos - vertexPos);
	vec3 reflectedLightDir = reflect(-lightDir, Normal);

	vec3 viewDir = normalize(camPos - vertexPos);

	float specularStrength = 0.5;
	float shininessFactor = 32;

	float cameraRayReflAngle = max(dot(viewDir, reflectedLightDir), 0.0);
	vec3 specularLight = specularStrength * pow(cameraRayReflAngle, shininessFactor) * lightColor;

	float lightNormalAngle = max(dot(normalize(Normal), lightDir), 0.0f);
	vec3 diffuseLight = lightNormalAngle * lightColor;

	float ambientStrength = 0.2;
	vec3 ambientLight = ambientStrength * lightColor;

	FragColor = vec4( (ambientLight + diffuseLight + specularLight) * objectColor, 1.0);
}