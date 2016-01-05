#include "Camera.h"
#include <glm/ext.hpp>


Camera::Camera(){
	  cameraPositionX = 0.0f;
	  cameraPositionY = 0.0f;
	  cameraPositionZ = 0.0f;

	  horizontalAngle = 0;
	  verticalAngle = 0;

}

glm::mat4 Camera::UpdateCameraPosition(Input input_Direction, int mouseX, int mouseY){

	if(input_Direction == UP){
		  cameraPositionZ += 0.1;
	  }else if(input_Direction == DOWN){
		  cameraPositionZ -= 0.1;
	  }else if(input_Direction == LEFT){
		  cameraPositionX += 0.1;
	  }else if(input_Direction == RIGHT){
		  cameraPositionX -= 0.1;
	  }


	  horizontalAngle += 2 * float(640/2 - mouseX);
	  verticalAngle += 2 * float(480/2 - mouseY);



	  return glm::lookAt(glm::vec3(cameraPositionX, cameraPositionY, cameraPositionZ),
			                    glm::vec3(cameraPositionX, 0.0f, cameraPositionZ + 2),
								glm::vec3(0.0f, 1.0f, 0.0f));
}



