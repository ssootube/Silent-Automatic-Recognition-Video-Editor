#include "IOhelper.h"

void IOhelper::selectLang()
{
    cout << "Select your Language(English: 0 , Korean: 1)>\n�� �����ϼ���.(����: 0, �ѱ���: 1)>\n";
	do 
	{
		cout << "please enter 0 or 1 only(English: 0, Korean: 1)>\n0�� 1 �߿� �ϳ��� �Է��ϼ���(����: 0, �ѱ���:1)>\n";
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
		cout << "������ ������ �������ּ���. 30~70������ �����մϴ�.(���� ��� 45�� �����ϸ�, ������ 45������ �Ҹ��� �������� �ν��ϰڴٴ� �ǹ��Դϴ�.)\n";
		break;
	}
	do 
	{
		switch (lang) 
		{
		case 0:
			cout << "Please enter positive integers only>";	break;
		case 1:
			cout << "���� ������ �Է��ϼ���>";
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
		cout << "�ҷ��� ������ �̸��� �Է��ϼ���. �����̸��̳� ��ο� �ѱ��� ���� �ȵ˴ϴ�. Ȯ���ڴ� �������ּ���.(mp4���ϸ� ����)>";
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
		cout << "������� �ε��ϴ� ��\n"; break;
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
		cout << "������ �Ϸ��Ϸ��� â�� �ݾ��ּ���.\n" << "���콺�� ��ũ���ϰų�, �����̽��ٸ� ���� ����� �غ� �� �ֽ��ϴ�.\n";
		cout << "������ �κ��� ���󿡼� �߷������� �κ��̰�, �ʷϻ� �κ��� ��Ƴ��� �κ��Դϴ�. xŰ�� ������ ������ �ٲ� �� �ֽ��ϴ�.\n";
		break;
	}
}

void IOhelper::showEnding()
{
	switch (lang) {
	case 0:
		cout << "It's done.";	break;
	case 1:
		cout << "�Ϸ�Ǿ����ϴ�."; break;
	}
}
