// Created by Gábor Bácsi
// 4/5/2024

#pragma once

#include <cmath> 

template <typename T>
struct Vector2D {
	Vector2D() : X(0), Y(0) {}
	Vector2D(T x, T y) : X(x), Y(y) {} 

	T SquaredLength() const {
		return X * X + Y * Y;
	}	
	
	T Length() const {
		return std::sqrt(SquaredLength());
	}

	T Dot(const Vector2D& other) const {
		return (this->X * other.X) + (this->Y * other.Y);
	}

	T Cross(const Vector2D& other) const {
		return x * other.y - y * other.x;
	}

	Vector2D Normalized() const {
		T length = Length();
		if (length == 0) {
			return Vector2D(0, 0);
		}
		return Vector2D(X / length, Y / length);
	}

	Vector2D& operator+=(const Vector2D& rhs) {
		this->X += rhs.X;
		this->Y += rhs.Y;
		return *this;
	}

	Vector2D& operator*=(T value) {
		this->X *= value;
		this->Y *= value;
		return *this;
	}

	Vector2D operator-() {
		return Vector2D(-this->X, -this->Y);
	}

	friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
		return Vector2D(lhs.X + rhs.X, lhs.Y + rhs.Y);
	}

	friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs) {
		return Vector2D(lhs.X - rhs.X, lhs.Y - rhs.Y);
	}

	friend Vector2D operator/(const Vector2D& lhs, const Vector2D& rhs) {
		return Vector2D(lhs.X / rhs.X, lhs.Y / rhs.Y);
	}

	friend Vector2D operator+(const Vector2D& lhs, const T& rhs) {
		return Vector2D(lhs.X + rhs, lhs.Y + rhs);
	}

	friend Vector2D operator*(const Vector2D& lhs, const T& rhs) {
		return Vector2D(lhs.X * rhs, lhs.Y * rhs);
	}

	static T SquareDistance(const Vector2D& p1, const Vector2D& p2) {
		T xDifference = (p1.X - p2.X);
		T yDifference = (p1.Y - p2.Y);
		return xDifference * xDifference + yDifference * yDifference;
	}

	static T Distance(const Vector2D& p1, const Vector2D& p2) {
		return std::sqrt(SquareDistance(p1, p2));
	}

public:
	T X;
	T Y;
};

template <typename T>
struct Vector3D {
	Vector3D() : X(0), Y(0), Z(0) {}
	Vector3D(T x, T y, T z) : X(x), Y(y), Z(z) {}

	T SquaredLength() const {
		return X * X + Y * Y + Z * Z;
	}

	T Length() const {
		return std::sqrt(SquaredLength());
	}

	T Dot(const Vector3D& other) const {
		return (this->X * other.X) + (this->Y * other.Y) + (this->Z * other.Z);
	}

	Vector3D Normalized() const {
		T length = Length();
		if (length == 0) {
			return Vector2D(0, 0);
		}
		return Vector3D(X / length, Y / length, Z / length);
	}

	Vector3D& operator+=(const Vector3D& rhs) {
		this->X += rhs.X;
		this->Y += rhs.Y;
		this->Z += rhs.Z;
		return *this;
	}

	Vector3D& operator*=(T value) {
		this->X *= value;
		this->Y *= value;
		this->Z *= value;
		return *this;
	}

	Vector3D operator-() {
		return Vector3D(-this->X, -this->Y, -this->Z);
	}

	friend Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
	}

	friend Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z);
	}

	friend Vector3D operator/(const Vector3D& lhs, const Vector3D& rhs) {
		return Vector3D(lhs.X / rhs.X, lhs.Y / rhs.Y, lhs.Z / rhs.Z);
	}

	friend Vector3D operator+(const Vector3D& lhs, const T& rhs) {
		return Vector3D(lhs.X + rhs, lhs.Y + rhs, lhs.Z + rhs);
	}

	friend Vector3D operator*(const Vector3D& lhs, const T& rhs) {
		return Vector3D(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs);
	}

	static T SquareDistance(const Vector3D& p1, const Vector3D& p2) {
		T xDifference = (p1.X - p2.X);
		T yDifference = (p1.Y - p2.Y);
		T zDifference = (p1.Z - p2.Z);
		return xDifference * xDifference + yDifference * yDifference + zDifference * zDifference;
	}

	static T Distance(const Vector3D& p1, const Vector3D& p2) {
		return std::sqrt(SquareDistance(p1, p2));
	}

public:
	T X;
	T Y;
	T Z;
};