#include <iostream>
#include <SFML/Graphics.hpp>
#include "PerlinNoise.hpp"
#include "VectorMath.h"
#include "Utility.h"
#include "Particle.h"

#define PI 3.14159265
#define PI_TWO 6.28318530

float inc = 0.01;
float zoff = 0.0;

int main() {

	srand(time(NULL));

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WindowWidth(), WindowHeight()), "Title", sf::Style::Close ,settings);

	siv::PerlinNoise Noise;

	int ArraySize = rows() * cols();
	int ParticlesSize = 5000;

	Particle *parts;
	parts = new Particle[ParticlesSize];

	Vector2f *flow;
	flow = new Vector2f[ArraySize];

	window.setActive();
	while (window.isOpen()) 
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
				window.clear();
		}

		float yoff = 0.0;
		for (int y = 0; y < rows(); y++) {
			float xoff = 0.0;
			for (int x = 0; x < cols(); x++) {

				int index = x + y * cols();
				float angle = ((Noise.octaveNoise0_1(xoff, yoff, zoff, 1)) * PI);
				Vector2f v(sin(angle), cos(-angle));
				v = setMag(v, 0.6);
				flow[index] = v;
				xoff += inc;
			}
			yoff += inc;
			zoff += 0.0005;
		}

		for (int i = 0; i < ParticlesSize; i++) {
			parts[i].follow(flow, ArraySize);
			parts[i].update();
			parts[i].edges();
			parts[i].display(window);
		}

		window.display();

	}

}
