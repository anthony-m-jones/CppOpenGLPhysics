#pragma once
#include <../Source/Vector2.h>

namespace MyCppOpenGLProject {
	class Particle2 {
	public:
		Vector2 position{ 1, 1 };
		Vector2 velocity{ 1, 1 };
		Particle2(float x, float y, float speed, float direction);
		
		void Update();
	};
}