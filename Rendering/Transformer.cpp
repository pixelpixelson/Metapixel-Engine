#include "Transformer.h"

CoreEngine::Rendering::Transform::Transformation::Transformation()
{
}

void CoreEngine::Rendering::Transform::Transformer::PushTransformation(Transformation* transform)
{
	transformation.push_back(std::unique_ptr<Transformation>(transform));
}

void CoreEngine::Rendering::Transform::Transformer::PopTransformation()
{
	transformation.pop_back();
}

CoreEngine::Vector::Vector2 CoreEngine::Rendering::Transform::Transformer::Transform(Vector::Vector2 original)
{
	for(auto iter = transformation.begin(); iter < transformation.end(); ++iter)
	{
		original = iter->get()->Compute(original);
	}
	return original;
}
