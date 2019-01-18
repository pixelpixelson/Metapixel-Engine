#pragma once
#include "../Vector/Vector2.h"
#include <vector>
#include <memory>

namespace CoreEngine::Rendering::Transform
{
	class Transformation
	{
	public:
		Transformation();
		virtual Vector::Vector2 Compute(Vector::Vector2 position) = 0;
	};

	// A class designed for transforming positions in a stack
	// much like OpenGL does with its fixed function
	// pipeline
	class Transformer
	{
	public:
		std::vector<std::unique_ptr<Transformation>> transformation;
		void PushTransformation(Transformation* transform);
		void PopTransformation();
		Vector::Vector2 Transform(Vector::Vector2 original);
	};
}
