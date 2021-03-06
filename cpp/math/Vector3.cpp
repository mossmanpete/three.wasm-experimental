﻿#include "Vector3.h"

Vector3::Vector3()
: x(0.0), y(0.0), z(0.0) {
}

Vector3::Vector3(
	double _x,
	double _y,
	double _z
)
: x(_x), y(_y), z(_z) {
}

Vector3* Vector3::set(
	double _x,
	double _y,
	double _z
) {
	this->x = _x;
	this->y = _y;
	this->z = _z;
	return this;
}

Vector3* Vector3::copy(
	Vector3 *v
) {
	this->x = v->x;
	this->y = v->y;
	this->z = v->z;
	return this;
}

bool Vector3::equals(
	Vector3 *v
) {
	return this->x == v->x && this->y == v->y && this->z == v->z;
}

Vector3* Vector3::applyMatrix4(
	Matrix4 *m
) {
	double x = this->x;
	double y = this->y;
	double z = this->z;
	double w = 1.0 / (m->elements[3] * x + m->elements[7] * y + m->elements[11] * z + m->elements[15]);
	this->x = (m->elements[0] * x + m->elements[4] * y + m->elements[8] * z + m->elements[12]) * w;
	this->y = (m->elements[1] * x + m->elements[5] * y + m->elements[9] * z + m->elements[13]) * w;
	this->z = (m->elements[2] * x + m->elements[6] * y + m->elements[10] * z + m->elements[14]) * w;
	return this;
}

Vector3* Vector3::setFromMatrixPosition(
	Matrix4 *m
) {
	this->x = m->elements[12];
	this->y = m->elements[13];
	this->z = m->elements[14];
	return this;
}

Vector3* Vector3::multiplyScalar(
	double scalar
) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return this;
}

double Vector3::dot(
	Vector3 *v
) {
	return this->x * v->x + this->y * v->y + this->z * v->z;
}

double Vector3::length() {
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

double Vector3::distanceToSquared(
	Vector3* v
) {
	double dx = this->x - v->x;
	double dy = this->y - v->y;
	double dz = this->z - v->z;
	return dx * dx + dy * dy + dz * dz;
}

Vector3* Vector3::addVectors(
	Vector3 *a,
	Vector3 *b
) {
	this->x = a->x + b->x;
	this->y = a->y + b->y;
	this->z = a->z + b->z;
	return this;
}
