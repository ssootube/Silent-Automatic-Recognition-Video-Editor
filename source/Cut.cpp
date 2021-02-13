#include "Cut.h"

int		scale = 40;
int		minWidth = 3;
float	get_width(float start, float end) {
	float width = (end - start) * scale;
	if (width < minWidth)
		width = minWidth;
	return width;
}
void Cut::set_end(float end)
{
	this->end = end;
	rect.setSize(Vector2f(get_width(start,end), 20));
}

Cut::Cut()
{
}

Cut::Cut(float start, float end, bool is_silent) :start(start), end(end), is_silent(is_silent) {
	rect.setSize(Vector2f(get_width(start,end), 20));
	is_silent ? rect.setFillColor(Color::Red) : rect.setFillColor(Color::Green);
}

void Cut::init()
{
	rect.setSize(Vector2f(get_width(start, end), 20));
	is_silent ? rect.setFillColor(Color::Red) : rect.setFillColor(Color::Green);
}
