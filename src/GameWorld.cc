#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {


  asset_manager = std::make_shared<GameAssetManager>(mode);


/*  //// used for testing

int maze [3][3]{
{1,1,1},
{1,1,1},
{1,1,4},
};
		for ( int x = 0; x < 3; x++)
			{
				for (int z = 0; z < 3; z++)
					{
						if (maze[x][z] == 1)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z)); // center bottom
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); // center left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); // center right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); // center top
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); // center bottom
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); // top left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); // bottom right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); // bottom left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); // top right
							}
							else if (maze[x][z] == 2)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); // center left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); // center right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); // center top
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); // center bottom
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); // top left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); // bottom right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); // bottom left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); // top right
							}
else if (maze[x][z] == 3)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); // center left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); // center right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); // center top
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); // center bottom
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); // top left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); // bottom right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); // bottom left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); // top right
							}
	
else if (maze[x][z] == 4)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); // center left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); // center right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); // center top
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); // center bottom
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); // top left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); // bottom right
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); // bottom left
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); // top right
							}
	
	
					}	

			}


*/

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


		for ( int x = 0; x < 10; x++)
			{
				for (int z = 0; z < 10; z++)
					{
						if (maze[x][z] == 1)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
									asset_manager->AddAsset(std::make_shared<StarAsset>(-3.0 * x, -0.0, -3.0 * z));

							}
					else if (maze[x][z] == 2)
						{
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));
									asset_manager->AddAsset(std::make_shared<StarAsset>(-3.0 * x, -0.0, -3.0 * z));
						}
					else if (maze[x][z] == 3)
						{		
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
									asset_manager->AddAsset(std::make_shared<StarAsset>(-3.0 * x, -0.0, -3.0 * z));
						}
						else if (maze[x][z] == 4)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
									asset_manager->AddAsset(std::make_shared<StarAsset>(-3.0 * x, -0.0, -3.0 * z));
							}
						else if (maze[x][z] == 5)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 

							}
						else if (maze[x][z] == 6)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));

							}
						else if (maze[x][z] == 7)
							{		
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 

							}
						else if (maze[x][z] == 8)
							{		
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));

							}
						else if (maze[x][z] == 9)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));

							}
						else if (maze[x][z] == 10)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));
							}
						else if (maze[x][z] == 11)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));
							}
						else if (maze[x][z] == 12)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
							}
						else if (maze[x][z] == 13)
							{		
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x,   -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
							}
						else if (maze[x][z] == 14)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1));
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1));
							}
						else if (maze[x][z] == 15)
							{	
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x+1, -0.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<CubeAsset>(-3.0 * x-1, -0.0 , -3.0 * z+1)); 
							}
					}
			}


		for ( int  x = 0; x < 10; x++)
			{	
				for ( int z = 0; z < 10; z++)
					{
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x,   -1.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x+1, -1.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x-1, -1.0 , -3.0 * z)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x,   -1.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x,   -1.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x+1, -1.0 , -3.0 * z+1)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x-1, -1.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x+1, -1.0 , -3.0 * z-1)); 
								asset_manager->AddAsset(std::make_shared<GroundAsset>(-3.0 * x-1, -1.0 , -3.0 * z+1)); 
					}
			}	



}

	void GameWorld::Draw() {
  		asset_manager->Draw();
}

	void GameWorld::UpdateCameraPosition(Input input_direction, int mouseX, int mouseY){
		asset_manager->UpdateCameraPosition(input_direction,  mouseX,  mouseY);
}
