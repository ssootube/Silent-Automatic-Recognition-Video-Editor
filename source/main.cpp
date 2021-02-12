#include "IOhelper.h"
#include "Tokenizer.h"
#include <direct.h>
using namespace std;
using namespace sf;
int main() {
	_mkdir("temp");
	IOhelper iohelper;
	iohelper.selectLang();
	int threshold = iohelper.getThreshold();
	string title = iohelper.getTitle();
	SoundBuffer buf = iohelper.LoadAudio(title);
	Tokenizer tokenizer(buf.getSamples(), buf.getSampleCount(),threshold, buf.getSampleRate());
	Sound sound(buf);
	switch (iohelper.lang) 
	{
	case 0:
		cout << "Audio Load Completed\n";
		break;
	case 1:
		cout << "오디오 로드 완료\n";
		break;
	}
	tokenizer.analyze(300);//샘플링은 300정도로 설정한다.
	iohelper.showInfo();
	long long int scroll = 0;
	RenderWindow window(VideoMode(480, 480), "auto mute recognition video editer[Math channel Ssootube]");
	window.setFramerateLimit(60);
	long long int selected = -1;
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			if (e.type == Event::MouseWheelScrolled)
			{
				cout << abs(scroll) << "/" << tokenizer.getCutsSize() << endl;
				scroll += e.mouseWheel.x / 1000000000;
			}
			if (e.type == Event::KeyPressed) 
			{
				if (e.key.code == Keyboard::Space) 
				{
					if (sound.getStatus() == Sound::Playing) 
					{
						sound.stop();
					}
					else 
					{
						selected = abs(scroll);
						tokenizer.setFillColor(selected, Color::Blue);
						sound.setPlayingOffset(sf::seconds(tokenizer.getStart(selected)));
						sound.play();
					}
				}
				else if (e.key.code == Keyboard::X) 
				{
					tokenizer.toggleSilent(abs(scroll));
				}
			}
		}
		if (selected >= 0) 
		{
			if (sound.getPlayingOffset() >= sf::seconds(tokenizer.getEnd(selected)) || sound.getStatus() == Sound::Stopped) {
				tokenizer.setFillColor(selected, Color::Red);
				selected = -1;
				sound.stop();
			}
		}
		window.clear();
		for (int i = 0; i < tokenizer.getCutsSize(); ++i) {
			if (i + scroll > 24) break;
			if (i + scroll < 0) continue;
			tokenizer.setPosition(Vector2f(0, 20 * (i + scroll)), i);
			tokenizer.draw(window, i);
		}
		window.display();
	}
	tokenizer.chop(title);
	tokenizer.remove(title);
	iohelper.showEnding();
}