#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

float constrain(float n, float low, float high);

float magSq(Vector2f v);

float mag(Vector2f v);
Vector2f div(Vector2f v, float n);

Vector2f mult(Vector2f v, float n);

Vector2f normalize(Vector2f v);

Vector2f setMag(Vector2f v, float n);

Vector2f limit(Vector2f v, float max);
