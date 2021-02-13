#include "dictionary.h"
unordered_map<string, vector<string>> dic =
{
	{"language",
	{"Select your Language(English: 0 , Korean: 1)>\n",
	"언어를 선택하세요.(영어: 0, 한국어: 1)>\n"}},

	{"only 0,1",
	{"please enter 0 or 1 only>\n",
	"0과 1 중에 하나만 입력하세요>\n"}},

	{"load",
	{"Do you want to load the file you were working on before? The file to be loaded must be the same text file as the name of the current source video.\n",
	"이전에 작업하던 파일을 로드하시겠습니까? 로드할 파일은 현재 원본 동영상의 이름과 동일한 텍스트 파일이어야 합니다.\n"}},

	{"only decimal",
	{"Please enter only positive realnumber in decimal places>",
	"양의 실수만을 소수점 단위로 입력해주세요>"}},

	{"yes no",
	{"(yes : 1, no : 0)",
	"(네 : 1, 아니오: 0)"}},

	{"saving",
	{"saving\n",
	"저장중입니다.\n"}},


	{"saved",
	{"saved\n",
	"저장되었습니다.\n"}},

	{"threshold",
	{"Please set threshold of the volume. About 30 to 70 is appropriate\n",
	"볼륨의 감도를 설정해주세요. 30~70정도가 적당합니다.(예를 들어 45로 설정하면, 볼륨이 45이하인 소리는 무음으로 인식하겠다는 의미입니다.)\n"}},

	{"positive int",
	{"Please enter positive integers only>",
	"양의 정수만 입력하세요>"}},

	{"enter title",
	{"Please enter a name for the video you want to import. The file name or path should not contain Korean. Please omit the file extension (only mp4 file available)>",
	"불러올 비디오의 이름을 입력하세요. 파일이름이나 경로에 한글이 들어가면 안됩니다. 확장자는 생략해주세요.(mp4파일만 가능)>"}},

	{"loading audio",
	{"Loading audio\n",
	"오디오를 로드하는 중\n"}},

	{"audio loaded",
	{"Audio Load Completed\n",
	"오디오 로드 완료\n"}},

	{"close info",
	{"Please close the editing window to finish editing.(not the console window)\n",
	"편집을 완료하려면 창을 닫아주세요.\n"}},

	{"control info",
	{"You can scroll through the mouse and press the space bar to try playing.\n",
	"마우스를 스크롤하거나, 스페이스바를 눌러 재생을 해볼 수 있습니다.\n"}},

	{"color info",
	{"The red part is the cutout part of the video, and the green part is the surviving part. You can change the color by pressing the x key.\n",
	"빨간색 부분은 영상에서 잘려나가는 부분이고, 초록색 부분은 살아남는 부분입니다. x키를 누르면 색깔을 바꿀 수 있습니다.\n"}},

	{"pieceFilter",
	{"Enter the time in decimal places for the parallel deletion processing. (Slices with less than the entered time length will be deleted)\n",
	"병렬 삭제 처리할 조각의 시간을 소수점 단위로 입력해주세요.(입력된 시간 이하 길이의 조각들은 삭제됩니다)\n"}},

	{"done",
	{"It's done.",
	"완료되었습니다."}}
};