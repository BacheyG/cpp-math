// Created by Gábor Bácsi
// 4/5/2024

#pragma once

template <typename T>
struct Vector2D {
	Vector2D() : X(0), Y(0) {}
	Vector2D(T x, T y) : X(x), Y(y) {} 
public:
	T X;
	T Y;
};