#pragma once
#include <math.h>
namespace MyCppOpenGLProject {
	class Vector2 {
	private:
		float _x = 1;
		float _y = 0;
	public:
		Vector2(float, float);
		void SetX(float x);

		float GetX();

		void SetY(float y);

		float GetY();

		float GetLength();

		void SetAngle(float);

		float GetAngle();

		void SetLength(float);

		Vector2 operator+(Vector2 other);

		Vector2 operator-(Vector2 other);

		Vector2 operator*(float scalar);

		Vector2 operator/(float scalar);

		//Vector2 operator*(Vector2 other);
	};
}