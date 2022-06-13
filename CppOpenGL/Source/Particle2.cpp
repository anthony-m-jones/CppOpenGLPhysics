#include <../Source/Particle2.h>
namespace MyCppOpenGLProject {
	Particle2::Particle2(float x, float y, float speed, Vector2 direction) {
		_position = { x, y };
		_velocity = { direction };
	}
}