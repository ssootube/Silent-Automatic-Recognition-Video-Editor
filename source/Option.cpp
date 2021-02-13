#include "Option.h"

void Option::setFillColor(size_t selected, Color color)
{
	if (selected < 0 || selected >= cuts.size())
		return;
	if (color == Color::Blue)
		cuts[selected].rect.setFillColor(color);
	else
		cuts[selected].rect.setFillColor(cuts[selected].is_silent ? Color::Red : Color::Green);
}

float Option::getStart(size_t selected)
{
	if (selected < 0 || selected >= cuts.size())
		return cuts.back().end;
	return cuts[selected].start;
}

float Option::getEnd(size_t selected)
{
	if (selected < 0 || selected >= cuts.size())
		return 0;
	return cuts[selected].end;
}

void Option::toggleSilent(size_t idx)
{
	if (idx < 0 || idx >= cuts.size())
		return;
	cuts[idx].is_silent = !cuts[idx].is_silent;
	cuts[idx].rect.setFillColor(cuts[idx].is_silent ? Color::Red : Color::Green);
}

void Option::draw(RenderWindow& window, size_t i)
{
	if (i < 0 || i >= cuts.size())
		return;
	window.draw(cuts[i].rect);
}

void Option::pieceFilter(float min)
{
	for (int i = 0; i < cuts.size(); ++i)
	{
		if (cuts[i].end - cuts[i].start < min)
		{
			cuts[i].is_silent = true;
			cuts[i].rect.setFillColor(Color::Red);
		}
	}
}
