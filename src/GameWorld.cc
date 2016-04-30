#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {


  asset_manager = std::make_shared<GameAssetManager>(mode);

	//// 2d array storing a maze generated using my own java maze generator, numbers represent room types from 1 to 15 that can only connect to other certain room types.
	//// tested and works - would be a simple matter to generated a map upto a 100x100 , anything beyond would be excessive for performance purposes
	//// with abit of time it wouldnt be too far fetched to port over my java map generator code and have a a dynamically random maze generated on a keypress or on each build
		int maze [10][10] = {
	{ 4,10,12, 7, 6, 2, 4, 7, 3, 3},
	{ 3, 4, 8,11,14,12,12,15,13, 9},
	{ 9, 6, 7, 5, 7, 5, 8, 9,11,13},
	{ 5,15, 8, 3, 9, 4, 2, 9, 5,13},
	{ 3,11,10, 8,11, 2, 4,15, 7, 9},
	{11,13, 3, 6,13, 6,12,13, 9, 9},
	{ 5,15,14,13, 5,14,14,15,15, 8},
	{ 6,13, 6,15, 7, 3, 6,14,13, 3},
	{ 9,11,14,14,13,11,15,12,15,13},
	{ 5,14, 2, 4,14, 8, 1, 1, 5, 8},
};
		asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 0.0), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
        asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 0.0), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.04,0.0,0.0)));
        asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(-6.0, 0.0, 0.0), 4, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));



        asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(0.0, 0.0, 3.0), 2, 1, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));
        asset_manager->AddAsset(std::make_shared<CubeAsset>(glm::vec3(3.0, 0.0, 3.0), 3, 5, glm::vec3(0.0,0.0,0.0), glm::vec3(0.0,0.0,0.0)));



//// calls the draw method in GameAssetManager.cc
}

	void GameWorld::Draw() {
  		asset_manager->Draw();
}

//// calls the updatecamera method in GameAssetManager passing the user input and mouse coordnates.

	void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
		asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);
}
