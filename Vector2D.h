/*
2D Vector Implementation
Created on 7/24/2017
By Daniel Janikowski
*/

#pragma once
#include <iostream>
class Vector2D {
private:
	double x, y;

public:
	Vector2D(double x_ = 1.0, double y_ = 0.0) : x{ x_ }, y{ y_ } {}
	static Vector2D fromPolar(double magnitude = 1.0, double theta = 0.0);

	Vector2D& set(Vector2D v);

	Vector2D& add(Vector2D v);
	Vector2D& subtract(Vector2D v);
	Vector2D& multiply(Vector2D v);
	Vector2D& multiply(double c);
	Vector2D& divide(Vector2D v);
	Vector2D& divide(double c);

	double dot(Vector2D v);
	double getMagnitude();
	double getTheta();
	double getThetaBetween(Vector2D v);
	Vector2D& setMagnitude(double magnitude);
	Vector2D& setTheta(double theta);
	Vector2D projectionOn(Vector2D v);
	Vector2D unitize();

	Vector2D clone() {
		return Vector2D(x, y);
	}
	bool isEqual(Vector2D v) {
		return (x == v.x) && (y == v.y);
	}
	//void print() {
	//	std::cout << "(" << x << ", " << y << ")" << std::endl;
	//}
	friend std::ostream& operator<< (std::ostream &out, Vector2D v) {
		out << "(" << v.x << ", " << v.y << ")" << std::endl;
		return out;
	}
};