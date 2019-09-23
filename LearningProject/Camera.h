#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

//Default camera values
const float CAM_SPEED = 2.0f;
const float CAM_SENSITIVITY = 0.5f;
const float YAW = -90.0f;
const float PITCH = 0.0f;

class Camera
{
public:
	glm::vec3 cameraPos;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)), camSpeed(CAM_SPEED), mouseSensitivity(CAM_SENSITIVITY)
	{
		cameraPos = position;
		cameraUp = upVector;

		Yaw = yaw;
		Pitch = pitch;
	}

	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = camSpeed * deltaTime;

		if (direction == Camera_Movement::FORWARD)
		{
			cameraPos += cameraFront * velocity;
		}
		else if (direction == Camera_Movement::BACKWARD)
		{
			cameraPos -= cameraFront * velocity;
		}

		if (direction == Camera_Movement::LEFT)
		{
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
		}

		if (direction == Camera_Movement::RIGHT)
		{
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
		}
	}

	void ProcessMouse(float xOffset, float yOffset, GLboolean constrainPitch = true)
	{
		xOffset *= mouseSensitivity;
		yOffset *= mouseSensitivity;

		Yaw += xOffset;
		Pitch += yOffset;

		if (constrainPitch)
		{
			if (Pitch > 89.0f)
				Pitch = 89.0f;
			if (Pitch < -89.0f)
				Pitch = -89.0f;
		}

		updateCameraVectors();
	}

	void setSpeed(float speed)
	{
		if (speed >= 0.0f)
		{
			camSpeed = speed;
		}
		else
		{
			std::cout << "WARNING: Camera speed must be positive. \n";
		}
	}

	float getSpeed()
	{
		return camSpeed;
	}

private:
	float Yaw;
	float Pitch;

	float camSpeed;
	float mouseSensitivity;

	void updateCameraVectors()
	{
		cameraFront.x = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw));
		cameraFront.y = sin(glm::radians(Pitch));
		cameraFront.z = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw));

		cameraFront = glm::normalize(cameraFront);
	}
};

#endif