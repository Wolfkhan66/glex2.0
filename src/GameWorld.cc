#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode)
{
	// Creates a CubeAsset in the asset manager
	asset_manager = std::make_shared<GameAssetManager>(mode);

	/*// 
	for(int i = 0; i < 5; i++)
	{
		if(i == 0)
		{
			asset_manager->AddAsset(std::make_shared<CubeAsset>(0.0, 0.0, 0.0));
		}
		else
		{
			asset_manager->AddAsset(std::make_shared<CubeAsset>(2.0*i, 0.0, 0.0));
		}
	}
	
	*/

// use of an 2d Array to create cubes.
	int ground [10][10];
	
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			ground[x][y] = 1 ;
		}
	
	}
	
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (ground[x][y] == 1)
				asset_manager->AddAsset(std::make_shared<CubeAsset>(2.0 * x, 0.0 , 2.0 * y));
		}
	
		
}
}


void GameWorld::Camera(int a)
{
	// W A S D // Player Movement
	if(a == 1)
		position += z_direction * camera_speed;
	if(a == 2)
		position -= x_direction * camera_speed;
	if(a == 3)
		position -= z_direction * camera_speed;
	if(a == 4)
		position += x_direction * camera_speed;

	// For MouseMovement (currently Up Down Left Right keys)
	if(a == 5)
		camera_y += 0.5f * camera_speed;
	if(a == 6)
		camera_x += 0.5f * camera_speed;
	if(a == 7)
		camera_y -= 0.5f * camera_speed;
	if(a == 8)
		camera_x -= 0.5f * camera_speed;

	// For movement on Y Axis // to be used for jump implementation
	if(a == 9)
		position.y += 0.5f * camera_speed;
	if(a == 10)
		position.y -= 0.5f * camera_speed;  }

void GameWorld::Action(int x)
{

//allows events to be executed based on variable x

// place a new cube or object
	if(x == 1)
	{
		asset_manager->AddAsset(std::make_shared<CubeAsset>(0.0f + int(position.x), 0.0f + int(position.y), 0.0f + int(position.z)));
	}


}



void GameWorld::Draw()
{   

	glm::vec3 direction(
		cos(camera_y) * sin(camera_x),
		sin(camera_y),
		cos(camera_y) * cos(camera_x)
	);

	glm::vec3 move_direction(
		cos(camera_y) * sin(camera_x),
		0,
		cos(camera_y) * cos(camera_x)
	);
	z_direction = move_direction;

	x_direction = glm::vec3(
		sin(camera_x - 3.14f/2.0f),
		0,
		cos(camera_x - 3.14f/2.0f)
	);

	glm::vec3 vup = glm::cross(x_direction, direction);
	glm::mat4 cam_proj = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 cam_view = glm::lookAt(
		position,
		position + direction,
		vup
	);
	glm::mat4 cam_mod(1.0f);

	glUniformMatrix4fv(0, 1, GL_FALSE, &cam_proj[0][0]);
	glUniformMatrix4fv(1, 1, GL_FALSE, &cam_view[0][0]);
	glUniformMatrix4fv(2, 1, GL_FALSE, &cam_mod[0][0]);

	// Calls draw from the asset manager
	asset_manager->Draw();
}
