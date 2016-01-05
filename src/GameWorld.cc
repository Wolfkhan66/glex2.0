#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {


  asset_manager = std::make_shared<GameAssetManager>(mode);

	for(int i = 1; i < 6; i++)
	{

		
	asset_manager->AddAsset(std::make_shared<CubeAsset>(2.0* i, 0.0, 10.0));
		
	}
		

	for(int i = 1; i < 6; i++)
	{

	asset_manager->AddAsset(std::make_shared<StarAsset>(-2.0* i, 0.0, 10.0));
		
	}
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){

asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);

}
