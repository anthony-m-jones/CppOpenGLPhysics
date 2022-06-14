#include <../Source/Particle2.h>

namespace MyCppOpenGLProject {
	Particle2::Particle2(float x, float y, float speed, float direction, float grav = 0) {
		position = { x, y };
		velocity.SetAngle(direction);
		velocity.SetLength(speed);
		gravity = Vector2(0, grav);
	}

	void Particle2::Update() {
		velocity = velocity + gravity;
		position = position + velocity;
	}

	void Particle2::Accelerate(Vector2 acceleration) {
		velocity = velocity + acceleration;
	}
}