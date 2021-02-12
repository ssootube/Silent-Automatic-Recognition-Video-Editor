#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cut {
public:
	void set_end(float end);
	Cut(float start, float end, bool is_silent);
	bool is_silent = false;
	RectangleShape rect;
	float start;
	float end;
};