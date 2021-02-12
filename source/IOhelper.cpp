#include "IOhelper.h"

void IOhelper::selectLang()
{
    cout << "Select your Language(English: 0 , Korean: 1)>\n언어를 선택하세요.(영어: 0, 한국어: 1)>\n";
	do 
	{
		cout << "please enter 0 or 1 only(English: 0, Korean: 1)>\n0과 1 중에 하나만 입력하세요(영어: 0, 한국어:1)>\n";
		cin >> lang;
		if (lang == 0 || lang == 1) break;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (true);
}

int IOhelper::getThreshold()
{
	int threshold;
	switch (lang) 
	{
	case 0:
		cout << "Please set threshold of the volume. 30 to 70 is appropriate (For example, setting this value to 45 means that a sound with a volume below 45 will be recognized as silent.)\n";
		break;
	case 1:
		cout << "볼륨의 감도를 설정해주세요. 30~70정도가 적당합니다.(예를 들어 45로 설정하면, 볼륨이 45이하인 소리는 무음으로 인식하겠다는 의미입니다.)\n";
		break;
	}
	do 
	{
		switch (lang) 
		{
		case 0:
			cout << "Please enter positive integers only>";	break;
		case 1:
			cout << "양의 정수만 입력하세요>";
			break;
		}
		cin >> threshold;
		if (threshold >= 0 && cin) break;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} while (true);
	return threshold;
}

string IOhelper::getTitle()
{
	switch (lang)
	{
	case 0:
		cout << "Please enter a name for the video you want to import. The file name or path should not contain Korean. Please omit the file extension (only mp4 file available)>";
		break;
	case 1:
		cout << "불러올 비디오의 이름을 입력하세요. 파일이름이나 경로에 한글이 들어가면 안됩니다. 확장자는 생략해주세요.(mp4파일만 가능)>";
		break;
	}
	string title;	
	cin >> title;
	return title;
}

SoundBuffer IOhelper::LoadAudio(string title)
{
	string command = "ffmpeg -i " + title + ".mp4 " + ".\\temp\\" + title + ".wav";
	system(command.c_str());
	switch (lang)
	{
	case 0:
		cout << "Loading audio\n"; break;
	case 1:
		cout << "오디오를 로드하는 중\n"; break;
	}
	SoundBuffer buf; 
	buf.loadFromFile(".\\temp\\" + title + ".wav");
	return buf;
}

void IOhelper::showInfo()
{
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
}

void IOhelper::showEnding()
{
	switch (lang) {
	case 0:
		cout << "It's done.";	break;
	case 1:
		cout << "완료되었습니다."; break;
	}
}
