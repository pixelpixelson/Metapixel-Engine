#include "BasicTransformations.h"
#include <cmath>

using namespace CoreEngine;

CoreEngine::Rendering::Transform::Translate::Translate(Vector::Vector2 amt) : amount{ amt }
{
}

Vector::Vector2 CoreEngine::Rendering::Transform::Translate::Compute(Vector::Vector2 position)
{
	return position + amount;
}