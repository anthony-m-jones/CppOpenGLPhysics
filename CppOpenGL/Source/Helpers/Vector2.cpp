#include <../Source/Helpers/Vector2.h>

namespace MyCppOpenGLProject {
	Vector2::Vector2(float x, float y) {
		SetX(x);
		SetY(y);
	}

	void Vector2::SetX(float x) {
		_x = x;
	}

	float Vector2::GetX() {
		return _x;
	}

	void Vector2::SetY(float y) {
		_y = y;
	}

	float Vector2::GetY() {
		return _y;
	}

	float Vector2::GetLength() {
		return sqrtf(_x * _x + _y * _y);
	}

	void Vector2::SetAngle(float angle) {
		float length = GetLength();
		_x = length * cos(angle);
		_y = length * sin(angle);
	}

	float Vector2::GetAngle() {
		return atan2(_y, _x);
	}

	void Vector2::SetLength(float length) {
		float angle = GetAngle();
		_x = length * cos(angle);
		_y = length * sin(angle);
	}

	Vector2 Vector2::operator+(Vector2 other) {
		return Vector2( _x + other.GetX(), _y + other.GetY() );
	}

	Vector2 Vector2::operator-(Vector2 other) {
		return Vector2(_x - other.GetX(), _y - other.GetY());
	}

	Vector2 Vector2::operator*(float scalar) {
		return Vector2(scalar * _x, scalar * _y);
	}

	Vector2 Vector2::operator/(float scalar) {
		return Vector2(_x / scalar, _y / scalar);
	}

	/*Vector2 Vector2::operator*(Vector2 other) {
		Vector2 result{ 0,0 };
		result.SetX(_x * scalar);
		result.SetY(_y * scalar);
		return result;
	}*/
};