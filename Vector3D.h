/*
3D Vector Implementation
Created on 7/24/2017
By Daniel Janikowski
*/

#pragma once
#include <iostream>
class Vector3D {
private:
	double x, y, z;

public:
	Vector3D(double x_ = 1.0, double y_ = 0.0, double z_ = 0.0) : x{ x_ }, y{ y_ }, z{ z_ } {}
	static Vector3D fromPolar(double magnitude = 1.0, double theta = 0.0, double phi = 0.0);

	Vector3D& set(Vector3D v);

	Vector3D& add(Vector3D v);
	Vector3D& subtract(Vector3D v);
	Vector3D& multiply(Vector3D v);
	Vector3D& multiply(double c);
	Vector3D& divide(Vector3D v);
	Vector3D& divide(double c);

	double dot(Vector3D v);
	Vector3D cross(Vector3D v);
	double getMagnitude();
	double getTheta();
	double getPhi();
	double getThetaBetween(Vector3D v);
	double getPhiBetween(Vector3D v);
	Vector3D& setMagnitude(double magnitude);
	Vector3D& setTheta(double theta);
	Vector3D& setPhi(double phi);
	Vector3D projectionOn(Vector3D v);
	Vector3D unitize();

	Vector3D clone() {
		return Vector3D(x, y, z);
	}
	bool isEqual(Vector3D v) {
		return (x == v.x) && (y == v.y) && (z == v.z);
	}
	//void print() {
	//	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
	//}
	friend std::ostream& operator<< (std::ostream &out, Vector3D v) {
		out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
		return out;
	}
};