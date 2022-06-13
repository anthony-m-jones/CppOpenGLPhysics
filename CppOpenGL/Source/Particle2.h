#pragma once
#include <../Source/Vector2.h>

namespace MyCppOpenGLProject {
	class Particle2 {
	private:
		Vector2 _position{ 0, 0 };
		Vector2 _velocity{ 0, 0 };

	public:
		Particle2(float x, float y, float speed, Vector2 direction) {
			_position = { x, y };
			_velocity = { direction };
		}
	};
}