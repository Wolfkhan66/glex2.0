#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {


  asset_manager = std::make_shared<GameAssetManager>(mode);

	int maze [11][11] = {
		{3,1,1,1,1,1,1,1,1,1,1},
		{3,1,2,2,2,2,1,1,2,2,1},
		{3,1,1,1,1,2,2,1,1,2,1},
		{3,1,1,2,2,2,2,2,1,2,1},
		{2,2,2,2,1,1,1,2,2,2,1},
		{3,1,2,1,1,1,2,2,1,2,1},
		{3,1,2,2,2,1,1,2,2,2,1},
		{3,1,1,1,2,1,1,1,2,1,1},
		{3,1,1,2,2,1,1,2,2,1,1},
		{3,1,1,1,2,1,1,2,1,1,1},
		{3,1,1,1,2,1,1,2,1,1,1},
										};

		for ( int x = 0; x < 11; x++)
			{
				for (int z = 0; z < 11; z++)
					{
						if (maze[x][z] == 1)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * z+1));

							}
					if (maze[x][z] == 2)
						{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * z+1));
						}
					if (maze[x][z] == 3)
						{
								asset_manager->AddAsset(std::make_shared<StarAsset>(3.0 * x, 0.0, 3.0 * z));
						}
					}
			}





}

void GameWorld::Draw() {
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){

asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);

}
