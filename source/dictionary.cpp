#include "dictionary.h"
unordered_map<string, vector<string>> dic =
{
	{"language",
	{"Select your Language(English: 0 , Korean: 1)>\n",
	"�� �����ϼ���.(����: 0, �ѱ���: 1)>\n"}},

	{"only 0,1",
	{"please enter 0 or 1 only>\n",
	"0�� 1 �߿� �ϳ��� �Է��ϼ���>\n"}},

	{"load",
	{"Do you want to load the file you were working on before? The file to be loaded must be the same text file as the name of the current source video.\n",
	"������ �۾��ϴ� ������ �ε��Ͻðڽ��ϱ�? �ε��� ������ ���� ���� �������� �̸��� ������ �ؽ�Ʈ �����̾�� �մϴ�.\n"}},

	{"only decimal",
	{"Please enter only positive realnumber in decimal places>",
	"���� �Ǽ����� �Ҽ��� ������ �Է����ּ���>"}},

	{"yes no",
	{"(yes : 1, no : 0)",
	"(�� : 1, �ƴϿ�: 0)"}},

	{"saving",
	{"saving\n",
	"�������Դϴ�.\n"}},


	{"saved",
	{"saved\n",
	"����Ǿ����ϴ�.\n"}},

	{"threshold",
	{"Please set threshold of the volume. About 30 to 70 is appropriate\n",
	"������ ������ �������ּ���. 30~70������ �����մϴ�.(���� ��� 45�� �����ϸ�, ������ 45������ �Ҹ��� �������� �ν��ϰڴٴ� �ǹ��Դϴ�.)\n"}},

	{"positive int",
	{"Please enter positive integers only>",
	"���� ������ �Է��ϼ���>"}},

	{"enter title",
	{"Please enter a name for the video you want to import. The file name or path should not contain Korean. Please omit the file extension (only mp4 file available)>",
	"�ҷ��� ������ �̸��� �Է��ϼ���. �����̸��̳� ��ο� �ѱ��� ���� �ȵ˴ϴ�. Ȯ���ڴ� �������ּ���.(mp4���ϸ� ����)>"}},

	{"loading audio",
	{"Loading audio\n",
	"������� �ε��ϴ� ��\n"}},

	{"audio loaded",
	{"Audio Load Completed\n",
	"����� �ε� �Ϸ�\n"}},

	{"close info",
	{"Please close the editing window to finish editing.(not the console window)\n",
	"������ �Ϸ��Ϸ��� â�� �ݾ��ּ���.\n"}},

	{"control info",
	{"You can scroll through the mouse and press the space bar to try playing.\n",
	"���콺�� ��ũ���ϰų�, �����̽��ٸ� ���� ����� �غ� �� �ֽ��ϴ�.\n"}},

	{"color info",
	{"The red part is the cutout part of the video, and the green part is the surviving part. You can change the color by pressing the x key.\n",
	"������ �κ��� ���󿡼� �߷������� �κ��̰�, �ʷϻ� �κ��� ��Ƴ��� �κ��Դϴ�. xŰ�� ������ ������ �ٲ� �� �ֽ��ϴ�.\n"}},

	{"pieceFilter",
	{"Enter the time in decimal places for the parallel deletion processing. (Slices with less than the entered time length will be deleted)\n",
	"���� ���� ó���� ������ �ð��� �Ҽ��� ������ �Է����ּ���.(�Էµ� �ð� ���� ������ �������� �����˴ϴ�)\n"}},

	{"done",
	{"It's done.",
	"�Ϸ�Ǿ����ϴ�."}}
};