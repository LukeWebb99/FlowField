#include "VectorMath.h"

float constrain(float n, float low, float high) {
	return max(min(n, high), low);
}

float magSq(Vector2f v) {
	return (v.x * v.x + v.y * v.y);
};

float mag(Vector2f v) {
	float g = v.x * v.x + v.y * v.y;
	return sqrt(g);
};

Vector2f div(Vector2f v, float n) {
	v.x /= n;
	v.y /= n;
	return v;
};

Vector2f mult(Vector2f v, float n){
	v.x *= n;
	v.y *= n;
	return v;
};

Vector2f normalize(Vector2f v) {

	return mag(v) == 0 ? v : div(v, mag(v));
};

Vector2f setMag(Vector2f v, float n) {

	/*
	double Mag = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	double new_vx = v.x * n / Mag;
	double new_vy = v.y * n / Mag;
	double new_vz = v.z * n / Mag;
	Vector3f new_v(new_vx, new_vy, new_vz);
	return new_v;
	*/

	v = normalize(v);
	v = mult(v, n);
	return v;


};

Vector2f limit(Vector2f v, float max) {
	float mSq = magSq(v);
	if (mSq > max * max) {
		v = div(v, sqrt(mSq));
		v = mult(v, max);
	}
	return v;
};
