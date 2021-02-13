#pragma once
#include <iostream>
#include "Option.h"
#include <SFML/Audio.hpp>
#include <functional>
#include "dictionary.h"

using namespace std;
using namespace sf;
extern	int		lang;
class IOhelper {
public:
	int				getIntWhile(function<bool(int)> condition, string msg);
	void			getOption(Option &op);
	void			selectLang();
	int				getThreshold();
	float			getFloatWhile(function<bool(float)> condition, string msg);
	string			getTitle();
	SoundBuffer		LoadAudio(string title);
	void			showInfo();
	void			showEnding();
	bool			getLoad();
};