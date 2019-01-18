#include <string>
#include <sstream>
#include "Vector2.h"
#include <cmath>

using namespace CoreEngine;
using namespace CoreEngine::Vector;

Vector2::Vector2(float x, float y) : x{ x }, y{ y }
{
}

Vector2::Vector2(const Vector2 & other) : x{ other.x }, y{other.y}
{
}

CoreEngine::Vector::Vector2::~Vector2()
{
}

Vector2 CoreEngine::Vector::Vector2::operator+(Vector2 rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 CoreEngine::Vector::Vector2::operator-(Vector2 rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y );
}

Vector2 CoreEngine::Vector::Vector2::operator*(float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 & CoreEngine::Vector::Vector2::operator+=(Vector2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2& CoreEngine::Vector::Vector2::operator-=(Vector2 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 & CoreEngine::Vector::Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2 & CoreEngine::Vector::Vector2::operator=(Vector2 rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}

float CoreEngine::Vector::Vector2::Angle(Vector2 rhs) const
{
	return std::acos(Dot(rhs));
}

float Vector2::Dot(Vector2 rhs) const
{
	return x * rhs.x + y * rhs.y;
}

float Vector2::Length() const
{
	return std::sqrtf(Dot(*this));
}

float Vector2::Distance(Vector2 rhs) const
{
	// end - start
	Vector2 point = rhs - *this;
	return point.Length();
}

Vector2 CoreEngine::Vector::Vector2::Normalized()
{
	float length = Length();
	return Vector2(x / length, y / length);
}

std::string std::to_string(const CoreEngine::Vector::Vector2 & vector)
{
	std::stringstream ss;
	ss << "{";
	ss << vector.x;
	ss << ",";
	ss << vector.y;
	ss << "}";
	std::string str;
	ss >> str;
	return str;
}
