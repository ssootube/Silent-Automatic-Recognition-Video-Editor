#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>
#include <SFML/Audio.hpp>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#define sampling 300
#define mute_count ((int)(3500/sampling))
#define rate 88200
#define open(str) SoundBuffer buf;buf.loadFromFile(str);const Int16* samples = buf.getSamples();
class element {
public:
	float start;
	float end;
	bool empty = 0;
	RectangleShape rect;
	void set_end(float end) {
		this->end = end;
		rect.setSize(Vector2f((end - start) * 40, 20));
	}
	element(float start, float end, bool empty) :start(start), end(end), empty(empty) {
		rect.setSize(Vector2f((end - start) * 40, 20));
		empty ? rect.setFillColor(Color::Red) : rect.setFillColor(Color::Green);
	}
};
void push(vector<element>& cut, float start, float end, bool is_empty) {
	if (is_empty == 1) {
		cut.push_back(element(start, end, 1));
	}
	else {
		if (cut.empty()) { cut.push_back(element(start, end, 0)); return; }
		if (cut.back().empty == 1) cut.push_back(element(start, end, 0));
		else cut[cut.size() - 1].set_end(end);
	}
}
int main() {
	cout << "Select your Langueage(English: 0 , Korean: 1)>\n언어를 선택하세요.(영어: 0, 한국어: 1)>\n";
	int lang;
	do {
		cout << "please enter 0 or 1 only(English: 0, Korean: 1)>\n0과 1 중에 하나만 입력하세요(영어: 0, 한국어:1)>\n";
		cin >> lang;
		if (lang == 0 || lang ==1) break;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (true);
	vector<element> cut;
	switch (lang) {
	case 0:
		cout << "Please set the sensitivity of the volume. 30 to 70 is appropriate (for example, if you set this to 45, a sound with a volume below 45 will be recognized as mute.)\n";
		break;
	case 1:
		cout << "볼륨의 감도를 설정해주세요. 30~70정도가 적당합니다.(예를 들어 45로 설정하면, 볼륨이 45이하인 소리는 무음으로 인식하겠다는 의미입니다.)\n";
		break;
	}
	int volume;
	do {
		switch (lang) {
		case 0:
			cout << "Please enter positive integers only>";	break;
		case 1:
			cout << "양의 정수만 입력하세요>";
			break;
		}
			cin >> volume;
			if (volume >= 0 && cin) break;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	} while (true);
	switch (lang) {
	case 0:
		cout << "Please enter a name for the video you want to import. The file name or path should not contain Korean. Please omit the file extension (only mp4 file available)>";
		break;
	case 1:
		cout << "불러올 비디오의 이름을 입력하세요. 파일이름이나 경로에 한글이 들어가면 안됩니다. 확장자는 생략해주세요.(mp4파일만 가능)>";
		break;
	}
	string source;	cin >> source;
	string temp = "ffmpeg -i " + source + ".mp4 " + source + ".wav";
	system(temp.c_str());
	switch (lang) {
	case 0:
		cout << "Loading audio\n"; break;
	case 1:
		cout << "오디오를 로드하는 중\n"; break;
	}
	open(source + ".wav");
	Sound sound(buf);
	switch (lang) {
	case 0:
		cout << "Audio Load Completed\n";
		cout << "Calculating length of audio\n";
		break;
	case 1:
		cout << "오디오 로드 완료\n";
		cout << "오디오의 길이 계산 중\n";
		break;
	}
	double duration = buf.getDuration().asMilliseconds() / 1000.0;
	switch (lang) {
	case 0:
		cout << "Completed calculating length of audio\n";
		break;
	case 1:
		cout << "오디오의 길이 계산 완료\n";
		break;
	}
	Uint64 samplecount = buf.getSampleCount();
	long double time = 0;
	long double start = 0;
	long double end = 0;
	int count = 0;
	for (long i = 0; i * sampling < samplecount; ++i) {
		time += sampling / (long double)rate;
		if (count < mute_count && abs(samples[i * sampling]) >= volume) {
			count = 0;
			end = time - sampling / (long double)rate;
			push(cut, start, end, 0);
			start = end;
			continue;
		}
		else if (count >= mute_count && abs(samples[i * sampling]) >= volume) {
			switch (lang) {
			case 0:
				cout << "Analyzing audio:" << time << "\n";
				break;
			case 1:
				cout << "오디오 분석중:" << time << "\n";
				break;
			}
			end = time - sampling / (long double)rate;
			push(cut, start, end, 1);
			start = end;
			count = 0;
		}
		if (abs(samples[i * sampling]) < volume) {
			count++;
		}
	}
	switch (lang) {
	case 0:
		cout << "Please close the editing window to finish editing.(not the console window)\n";
		cout << "You can scroll through the mouse and press the space bar to try playing.\n";
		cout << "The red part is the cutout part of the video, and the green part is the surviving part. You can change the color by pressing the x key.\n";
		break;
	case 1:
		cout << "편집을 완료하려면 창을 닫아주세요.\n" << "마우스를 스크롤하거나, 스페이스바를 눌러 재생을 해볼 수 있습니다.\n";
		cout << "빨간색 부분은 영상에서 잘려나가는 부분이고, 초록색 부분은 살아남는 부분입니다. x키를 누르면 색깔을 바꿀 수 있습니다.\n";
		break;
	}
	long long int scroll = 0;
	RenderWindow window(VideoMode(480, 480), "auto mute recognition video editer[Math channel Ssootube]");
	window.setFramerateLimit(60);
	long long int selected = -1;
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)//닫기 버튼을 클릭한 경우라면 닫고, 아니면 스핀락을 걸어 놓는다.
				window.close();
			if (e.type == Event::MouseWheelScrolled) {
				cout << abs(scroll) << "/" << cut.size() << endl;
				scroll += e.mouseWheel.x / 1000000000;
			}
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Space) {
					if (sound.getStatus() == Sound::Playing) {
						sound.stop();
					}
					else {
						selected = abs(scroll);
						cut[selected].rect.setFillColor(Color::Blue);
						sound.setPlayingOffset(sf::seconds(cut[selected].start));
						sound.play();
					}
				}
				else if (e.key.code == Keyboard::X) {
					cut[abs(scroll)].empty = !cut[abs(scroll)].empty;
					cut[abs(scroll)].rect.setFillColor(cut[abs(scroll)].empty == 1 ? Color::Red : Color::Green);
					cout << (cut[abs(scroll)].rect.getFillColor() == Color::Red ? "red" : "green") << endl;
					cout << cut[abs(scroll)].rect.getSize().x << endl;
				}
			}
		}
		if (selected >= 0) {
			if (sound.getPlayingOffset() >= sf::seconds(cut[selected].end) || sound.getStatus() == Sound::Stopped) {
				cut[selected].rect.setFillColor(cut[selected].empty == 1 ? Color::Red : Color::Green);
				selected = -1;
				sound.stop();
			}
		}
		window.clear();
		for (int i = 0; i < cut.size(); ++i) {
			if (i + scroll > 24) break;
			if (i + scroll < 0) continue;
			cut[i].rect.setPosition(Vector2f(0, 20 * (i + scroll)));
			window.draw(cut[i].rect);
		}
		window.display();
	}
	count = 0;
	ofstream txt("filelist.txt", ios::out);
	for (auto& iter : cut) {
		if (iter.empty == 1) continue;
		else {
			txt << "file " << source;
			txt << count; txt << ".mp4\n";
			string temp = "ffmpeg -ss " + to_string(round(iter.start * 100) / 100.0) + " -i " + source + ".mp4 -t " + to_string(round((iter.end - iter.start) * 100) / 100.0) + " -vcodec libx264 -acodec aac " + source + to_string(count) + ".mp4";
			system(temp.c_str());
			count++;
		}
	}
	txt.close();
	system("ffmpeg -f concat -i filelist.txt -c copy output.mp4");
	ifstream del("filelist.txt", ios::in);
	char del_buf[256];
	while (del.getline(del_buf, 256)) {
		string temp = "del " + string(del_buf);
		system(temp.c_str());
	}
	system("del filelist.txt");
	string ending = "del " + source + ".wav";
	system(ending.c_str());
	switch (lang) {
	case 0:
		cout << "It's done.";	break;
	case 1:
		cout << "완료되었습니다."; break;
	}
}
