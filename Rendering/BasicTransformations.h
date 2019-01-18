#pragma once
#include "Transformer.h"
namespace CoreEngine::Rendering::Transform
{
	class Translate : public Transformation
	{
	public:
		Translate(Vector::Vector2 amt);
		Vector::Vector2 amount;

		virtual Vector::Vector2 Compute(Vector::Vector2 position) override;
	};
}
