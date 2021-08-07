#include "Particle.h"
#include "VectorMath.h"
#include "Utility.h"

void Particle::display(sf::RenderWindow & Window)
{
	sf::VertexArray line(sf::LineStrip, 2);
	line[0].position = (pos);
	line[1].position = (prevpos);
	line[1].color = (Color(100, 100, 0, 1));
	line[0].color = (Color(255, 100, 100, 1));
	Window.draw(line);
	updatePrev();
}

void Particle::update()
{
	vel += acc;
	vel = limit(vel, 4);
	pos += vel;
	acc = mult(acc, 1);
}

void Particle::edges()
{
	if (pos.x > WindowWidth()) {
		pos.x = 1;
		updatePrev();
	};
	if (pos.x < 0) {
		pos.x = WindowWidth()-1;
		updatePrev();
	}

	if (pos.y > WindowHeight()) {
		pos.y = 1;
		updatePrev();
	}
	if (pos.y < 0) {
		pos.y = WindowHeight()-1;
		updatePrev();
	}
}

void Particle::applyforce(Vector2f &force)
{
	vel += force;
}

void Particle::follow(Vector2f array[], int & size)
{
	int x = floor(pos.x / scl());
	int y = floor(pos.y / scl());
	int index = x + y * cols();
	index > size ? index = size : index = x + y * cols();
	Vector2f force = array[index];
	applyforce(force);
}

void Particle::follow(std::vector<Vector2f>& vector, int & size)
{
	int x = floor(pos.x / scl());
	int y = floor(pos.y / scl());
	int index = x + y * cols();
	if (index > size) index = size;
	Vector2f force = vector[index];
	applyforce(force);
}

void Particle::updatePrev()
{
	prevpos = pos;
}
