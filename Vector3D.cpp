#include "Vector3D.h"
#include <cmath>

Vector3D Vector3D::fromPolar(double magnitude, double theta, double phi) {
	return Vector3D(magnitude * sin(phi) * cos(theta), magnitude * sin(phi) * sin(theta), magnitude * cos(phi));
}

Vector3D& Vector3D::set(Vector3D v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector3D& Vector3D::add(Vector3D v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vector3D& Vector3D::subtract(Vector3D v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector3D& Vector3D::multiply(Vector3D v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
Vector3D& Vector3D::multiply(double c) {
	x *= c;
	y *= c;
	z *= c;
	return *this;
}
Vector3D& Vector3D::divide(Vector3D v) {
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}Vector3D& Vector3D::divide(double c) {
	x /= c;
	y /= c;
	z /= c;
	return *this;
}

double Vector3D::dot(Vector3D v) {
	return x * v.x + y * v.y + z * v.z;
}
Vector3D Vector3D::cross(Vector3D v) {
	return Vector3D(y * v.z - (v.y * z), -(x * v.z) + v.x * z, x * v.y - (v.x * y));
}
double Vector3D::getMagnitude() {
	return sqrt(x * x + y * y + z * z);
}
double Vector3D::getTheta() {
	return acos(x / (getMagnitude() * getPhi()));
}
double Vector3D::getPhi() {
	return acos(z / getMagnitude());
}
double Vector3D::getThetaBetween(Vector3D v) {
	return acos(dot(v) / (getMagnitude() * v.getMagnitude()));
}
double Vector3D::getPhiBetween(Vector3D v) {
	return 0;
}
Vector3D& Vector3D::setMagnitude(double magnitude) {
	Vector3D temp = fromPolar(magnitude, getTheta(), getPhi());
	x = temp.x;
	y = temp.y;
	z = temp.z;
	return *this;
}
Vector3D& Vector3D::setTheta(double theta) {
	Vector3D temp = fromPolar(getMagnitude(), theta, getPhi());
	x = temp.x;
	y = temp.y;
	z = temp.z;
	return *this;
}
Vector3D& Vector3D::setPhi(double phi) {
	Vector3D temp = fromPolar(getMagnitude(), getTheta(), phi);
	x = temp.x;
	y = temp.y;
	z = temp.z;
	return *this;
}
Vector3D Vector3D::projectionOn(Vector3D v) {
	return v.multiply(dot(v) / pow(v.getMagnitude(), 2));
}
Vector3D Vector3D::unitize() {
	return divide(getMagnitude());
}