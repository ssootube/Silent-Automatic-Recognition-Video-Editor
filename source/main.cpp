#include "IOhelper.h"
#include "Tokenizer.h"
#include "Option.h"
#include <direct.h>
using namespace std;
using namespace sf;
int main() {
	_mkdir("temp");
	Option	op;
	IOhelper iohelper;
	iohelper.selectLang();
	iohelper.getOption(op);
	Tokenizer tokenizer;
	if (iohelper.getLoad())
		op.load();
	else
		tokenizer.analyze(op, 300);//샘플링은 300정도로 설정한다.
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
				cout << abs(scroll) << "/" << op.cuts.size() << endl;
				scroll += e.mouseWheel.x / 1000000000;
			}
			if (e.type == Event::KeyPressed) 
			{
				if (e.key.code == Keyboard::Space) 
				{
					if (op.sound.getStatus() == Sound::Playing) 
					{
						op.sound.stop();
					}
					else 
					{
						selected = abs(scroll);
						op.setFillColor(selected, Color::Blue);
						op.sound.setPlayingOffset(sf::seconds(op.getStart(selected)));
						op.sound.play();
					}
				}
				else if (e.key.code == Keyboard::X) 
				{
					op.toggleSilent(abs(scroll));
				}
				else if (e.key.code == Keyboard::Up)
				{
					cout << abs(scroll) << "/" << op.cuts.size() << endl;
					scroll++;
				}
				else if (e.key.code == Keyboard::Down)
				{
					cout << abs(scroll) << "/" << op.cuts.size() << endl;
					scroll--;
				}
				else if (e.key.code == Keyboard::F)
				{
					cout << dic["pieceFilter"][lang];
					op.pieceFilter(iohelper.getFloatWhile([](float a)->bool {return a >= 0; }, dic["only decimal"][lang]));
				}
				else if (e.key.code == Keyboard::S)
				{
					cout << dic["saving"][lang];
					op.save();
					cout << dic["saved"][lang];
				}
			}
		}
		if (selected >= 0) 
		{
			if (op.sound.getPlayingOffset() >= sf::seconds(op.getEnd(selected)) || op.sound.getStatus() == Sound::Stopped) {
				op.setFillColor(selected, Color::Red);
				selected = -1;
				op.sound.stop();
			}
		}
		window.clear();
		for (int i = 0; i < op.cuts.size(); ++i) {
			if (i + scroll > 24) break;
			if (i + scroll < 0) continue;
			op.cuts[i].rect.setPosition(Vector2f(0, 20 * (i + scroll)));
			op.draw(window, i);
		}
		window.display();
	}
	tokenizer.chop(op);
	system("del .\\temp\\*");
	iohelper.showEnding();
}