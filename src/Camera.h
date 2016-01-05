#include <glm/ext.hpp>
#include "common.h"

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_
class Camera{

public:
	 Camera();
	 glm::mat4 UpdateCameraPosition(Input inputDirection, int mouseX, int mouseY);

private:
	
	float cameraPositionX;
	float cameraPositionY;
	float cameraPositionZ;
	float horizontalAngle;
	float verticalAngle;
};

#endif

