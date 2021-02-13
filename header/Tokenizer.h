#pragma once

#include "Option.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#define mute_count ((int)(3500/sampling))
using namespace std;
using namespace sf;
class Tokenizer {
public:
	void	analyze(Option& op, int sampling);
	void	push(Option& op, float start, float end, bool is_silent);
	void	chop(Option& op);
};