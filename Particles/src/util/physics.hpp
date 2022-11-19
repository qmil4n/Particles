#pragma once
#include "stdain.hpp"

float sqrt7(float x) {
	unsigned int i = *(unsigned int*)&x;
	i += 127 << 23;
	i >>= 1;
	return *(float*)&i;
}

float getMagnitude(const sf::Vector2f& vec) {
	return sqrt7(vec.x * vec.x + vec.y * vec.y);
}

void normalize(sf::Vector2f& vec) {
	vec /= getMagnitude(vec);
}