#pragma once
#include "Cut.h"
#include <vector>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#define mute_count ((int)(3500/sampling))
using namespace std;
using namespace sf;
class Tokenizer {
public:
	Tokenizer(const Int16* samples, Uint64 samples_length, int threshold,unsigned int rate);
	void	analyze(int sampling);
	void	push(float start, float end, bool is_silent);
	size_t	getCutsSize();
	void	setFillColor(size_t selected, Color color);
	void    setPosition(Vector2f pos, size_t i);
	float	getStart(size_t selected);
	float	getEnd(size_t selected);
	void	toggleSilent(size_t idx);
	void	draw(RenderWindow& window, size_t i);
	void	chop(string title);
	void	remove(string title);

private:
	vector<Cut>		cuts;
	const Int16*	samples;
	int				threshold;
	Uint64			samples_length;
	unsigned int	rate;
};