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

	int maze [10][10] = {
		{1,2,1,1,1,1,1,1,1,1},
		{1,2,2,2,2,1,1,2,2,1},
		{1,1,1,1,2,2,1,1,2,1},
		{1,1,2,2,2,2,2,1,2,1},
		{1,2,2,1,1,1,2,2,2,1},
		{1,2,1,1,1,2,2,1,2,1},
		{1,2,2,2,1,1,2,2,2,1},
		{1,1,1,2,1,1,1,2,1,1},
		{1,1,2,2,1,1,2,2,1,1},
		{1,1,1,2,1,1,2,1,1,1},
										};

		for ( int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
					{
						if (maze[x][y] == 1)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * y));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * y));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * y));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * y+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x, 0.0 , 3.0 * y-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * y+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * y-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * y-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * y+1));

							}
					if (maze[x][y] == 2)
						{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * y+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * y-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x+1, 0.0 , 3.0 * y-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(3.0 * x-1, 0.0 , 3.0 * y+1));
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
