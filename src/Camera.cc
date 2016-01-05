#include "Camera.h"
#include <glm/ext.hpp>
#include <iostream>


Camera::Camera(){
	  cameraPositionX = -3.0f;
	  cameraPositionY = 1.5f;
	  cameraPositionZ = 0.0f;

	  horizontalAngle = 0;
	  verticalAngle = 0;

}


 glm::mat4 Camera::UpdateCameraPosition(Input inputDirection, int mouseX, int mouseY){

	if(inputDirection == UP){
		  cameraPositionZ += 0.5;
	  }else if(inputDirection == DOWN){
		  cameraPositionZ -= 0.5;
	  }else if(inputDirection == LEFT){
		  cameraPositionX += 0.5;
	  }else if(inputDirection == RIGHT){
		  cameraPositionX -= 0.5;
	  }

	  horizontalAngle += 2 * float(640/2 - mouseX);
	  verticalAngle += 2 * float(480/2 - mouseY);

return glm::lookAt(glm::vec3(cameraPositionX, cameraPositionY, cameraPositionZ),
glm::vec3(cameraPositionX, 0.0f, cameraPositionZ + 2),
	glm::vec3(0.0f, 1.0f, 0.0f));
}



