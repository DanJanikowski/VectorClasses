#include "Vector2D.h"
#include <cmath>

Vector2D Vector2D::fromPolar(double magnitude, double theta) {
	return Vector2D(magnitude * cos(theta), magnitude * sin(theta));
}

Vector2D& Vector2D::set(Vector2D v) {
	x = v.x;
	y = v.y;
	return *this;
}

Vector2D& Vector2D::add(Vector2D v) {
	x += v.x;
	y += v.y;
	return *this;
}
Vector2D& Vector2D::subtract(Vector2D v) {
	x -= v.x;
	y -= v.y;
	return *this;
}
Vector2D& Vector2D::multiply(Vector2D v) {
	x *= v.x;
	y *= v.y;
	return *this;
}
Vector2D& Vector2D::multiply(double c) {
	x *= c;
	y *= c;
	return *this;
}
Vector2D& Vector2D::divide(Vector2D v) {
	x /= v.x;
	y /= v.y;
	return *this;
}Vector2D& Vector2D::divide(double c) {
	x /= c;
	y /= c;
	return *this;
}

double Vector2D::dot(Vector2D v) {
	return x * v.x + y * v.y;
}
double Vector2D::getMagnitude() {
	return sqrt(x * x + y * y);
}
double Vector2D::getTheta() {
	return atan2(y, x);
}
double Vector2D::getThetaBetween(Vector2D v) {
	return acos(dot(v) / (getMagnitude() * v.getMagnitude()));
}
Vector2D& Vector2D::setMagnitude(double magnitude) {
	Vector2D temp = fromPolar(magnitude, getTheta());
	x = temp.x;
	y = temp.y;
	return *this;
}
Vector2D& Vector2D::setTheta(double theta) {
	Vector2D temp = fromPolar(getMagnitude(), theta);
	x = temp.x;
	y = temp.y;
	return *this;
}
Vector2D Vector2D::projectionOn(Vector2D v) {
	v.unitize();
	return v.multiply(dot(v));
}
Vector2D Vector2D::unitize() {
	return divide(getMagnitude());
}