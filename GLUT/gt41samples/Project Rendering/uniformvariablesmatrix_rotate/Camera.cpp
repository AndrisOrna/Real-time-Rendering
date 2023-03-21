#include "Camera.h"


Camera::Camera(glm::vec3 position)
	:cameraPos(position),
	worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
	yaw(-90.0f),
		pitch(0.0f),
		speed(2.5f),
		zoom(45.0f),
		cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
		{
			updateCameraVectors();
		}


void Camera::updateCameraDirection(double dx, double dy){}
void Camera::updateCameraPos(CameraDirection dir, double dt){}
void Camera::updateCameraZoom(double dy){}

glm::mat4 Camera::getViewMatrix(){}

void Camera::updateCameraVectors()
	{
	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);

	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));


	}