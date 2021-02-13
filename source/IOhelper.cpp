#include "IOhelper.h"

int		lang;

int IOhelper::getIntWhile(function<bool(int)> condition, string msg)
{
	int result;
	do{
		cout << msg;
		cin >> result;
		if (condition(result) && cin)
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return result;
}

void IOhelper::selectLang()
{
	cout << dic["language"][0] + dic["language"][1];
	lang = getIntWhile([](int a)->bool {return a == 0 || a == 1;}, dic["only 0,1"][0] + dic["only 0,1"][1]);
}

int IOhelper::getThreshold()
{
	cout << dic["threshold"][lang];
	return getIntWhile([](int a)->bool {return a >= 0; }, dic["positive int"][lang]);
}

string IOhelper::getTitle()
{
	cout << dic["enter title"][lang];
	string title;	
	cin >> title;
	return title;
}

SoundBuffer IOhelper::LoadAudio(string title)
{
	string command = "ffmpeg -i " + title + ".mp4 -async 1 " + ".\\temp\\" + title + ".wav";
	system(command.c_str());
	cout << dic["loading audio"][lang];
	SoundBuffer buf; 
	buf.loadFromFile(".\\temp\\" + title + ".wav");
	return buf;
}

void IOhelper::showInfo()
{
	cout << dic["close info"][lang];
	cout << dic["control info"][lang];
	cout << dic["color info"][lang];
}

void IOhelper::showEnding()
{
	cout << dic["done"][lang];
}

void IOhelper::getOption(Option& op)
{
	op.threshold = getThreshold();
	op.title = getTitle();
	op.buffer = LoadAudio(op.title);
	op.sound = Sound(op.buffer);
	cout << dic["audio loaded"][lang];
	op.samples = op.buffer.getSamples();
	op.samples_length = op.buffer.getSampleCount();
	op.rate = op.buffer.getSampleRate();
}

float IOhelper::getFloatWhile(function<bool(float)> condition, string msg)
{
	float result;
	do {
		cout << msg;
		cin >> result;
		if (condition(result) && cin)
			break;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return result;
}