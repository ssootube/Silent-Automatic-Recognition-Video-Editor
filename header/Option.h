#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include <vector>
#include "Cut.h"

using namespace std;
using namespace sf;

class Option {
public:
	void			setFillColor(size_t selected, Color color);
	float			getStart(size_t selected);
	float			getEnd(size_t selected);
	void			toggleSilent(size_t idx);
	void			draw(RenderWindow& window, size_t i);
	void			pieceFilter(float min);
	int				threshold;
	string			title;
	SoundBuffer		buffer;
	const Int16*	samples;
	Uint64			samples_length;
	unsigned int	rate;
	Sound			sound;
	vector<Cut>		cuts;
};