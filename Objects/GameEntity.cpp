#include "../GameEngine.h"
#include "../States/GameState.h"
#include "GameEntity.h"

CoreEngine::Objects::GameEntity::GameEntity(Vector::Vector2 position) : position{ position }
{
}

CoreEngine::Objects::GameEntity::~GameEntity()
{
}
