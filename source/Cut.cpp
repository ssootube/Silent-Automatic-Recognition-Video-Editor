#include "Cut.h"

void Cut::set_end(float end)
{
	this->end = end;
	rect.setSize(Vector2f((end - start) * 40, 20));
}

Cut::Cut(float start, float end, bool is_silent) :start(start), end(end), is_silent(is_silent) {
	rect.setSize(Vector2f((end - start) * 40, 20));
	is_silent ? rect.setFillColor(Color::Red) : rect.setFillColor(Color::Green);
}
