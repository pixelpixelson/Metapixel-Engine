#pragma once

#include <string>

namespace CoreEngine::Vector
{
	// Class for 2D Vector mathematics
	class Vector2
	{
	public:
		float x = 0.0f, y = 0.0f;

		Vector2() = default;
		Vector2(float x, float y);
		Vector2(const Vector2& other);
		virtual ~Vector2();

		Vector2 operator + (Vector2 rhs) const;
		Vector2 operator - (Vector2 rhs) const;
		Vector2 operator * (float scalar) const;

		Vector2& operator += (Vector2 rhs);
		Vector2& operator -= (Vector2 rhs);
		Vector2& operator *= (float scalar);

		Vector2& operator = (Vector2 rhs);

		// Angle between 2 vectors
		float Angle(Vector2 rhs) const;

		// The projection of the vector onto 'rhs'
		float Dot(Vector2 rhs) const;

		// The hypotonuse of the vector
		float Length() const;

		// The distance to 'rhs'
		float Distance(Vector2 rhs) const;

		// A copy of the vector with length 1
		Vector2 Normalized();
	};	
}


namespace std
{

	// Simple conversion from Vector2 to string
	std::string to_string(const CoreEngine::Vector::Vector2& vector);
}