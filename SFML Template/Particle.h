#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Particle {

private:

	Vector2f pos;
	Vector2f vel;
	Vector2f acc;
	Vector2f prevpos;

public:
	Particle()
	{
		pos = Vector2f(rand() % 1200, rand() % 800);
		vel = Vector2f(0, 0);
		acc = Vector2f(0, 0);
		prevpos = Vector2f(pos.x, pos.y);
	}

	void display(sf::RenderWindow &Window);
	void update();
	void edges();
	void applyforce(Vector2f &force);
	void follow(Vector2f array[], int &size);
	void follow(std::vector<Vector2f> &vector, int &size);
	void updatePrev();
};