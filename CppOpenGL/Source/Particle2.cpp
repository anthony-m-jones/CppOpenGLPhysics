#include <../Source/Particle2.h>

namespace MyCppOpenGLProject {
	Particle2::Particle2(float x, float y, float speed, float direction) {
		position = { x, y };
		velocity.SetAngle(direction);
		velocity.SetLength(speed);
	}

	void Particle2::Update() {
		position = position + velocity;
	}
}