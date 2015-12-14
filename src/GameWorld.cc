#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {
  asset_manager = std::make_shared<GameAssetManager>(mode);


for( int i = 0 ; i < 5; i++)
  asset_manager->AddAsset(std::make_shared<CubeAsset>(0.0 + i, 0.0 + i, 0.0 + i));
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
