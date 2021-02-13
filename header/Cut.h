#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cut {
public:
	void set_end(float end);
	Cut();
	Cut(float start, float end, bool is_silent);
	void init();
	bool is_silent = false;
	RectangleShape rect;
	float start;
	float end;
};