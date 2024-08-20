// Created by Gábor Bácsi
// 4/5/2024

#pragma once

template <typename T>
struct Vector2D {
	Vector2D() : X(0), Y(0) {}
	Vector2D(T x, T y) : X(x), Y(y) {} 

	Vector2D& operator+=(const Vector2D& rhs) {
		this->X += rhs.X;
		this->Y += rhs.Y;
		return *this;
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

	static float squareDistance(const Vector2D& p1, const Vector2D& p2) {
		float xDifference = (p1.X - p2.X);
		float yDifference = (p1.Y - p2.Y) 
		return xDifference * xDifference + yDifference * yDifference;
	}

public:
	T X;
	T Y;
};