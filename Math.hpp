// Created by Gábor Bácsi
// 10/21/2024

#pragma once

template <typename T>
int signum(T val) {
	return (T(0) < val) - (val < T(0));
}
