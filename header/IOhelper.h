#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
class IOhelper {
public:
	void			selectLang();
	int				getThreshold();
	string			getTitle();
	SoundBuffer		LoadAudio(string title);
	void			showInfo();
	void			showEnding();
	int				lang;
};