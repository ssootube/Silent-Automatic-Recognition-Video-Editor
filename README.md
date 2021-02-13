# Silent-Automatic-Recognition-Video-Editor
Silent Automatic Recognition Video Editor using SFML and FFMPEG

무음구간 자동인식 영상 편집기(FFMPEG와 SFML기반)

무음구간 자동인식 가능(사용자가 지정한 볼륨 값 이하의 소리가 일정 시간 이상 지속되면 무음구간으로 간주하여 자동으로 클립을 잘라줌)

저장 가능 (편집 중에 S키를 눌러서 저장)

불러오기 가능

일괄 편집 가능 (편집중 F키를 누른 뒤 예를 들어 0.12 라고 입력하면 0.12초보다 짧게 잘린 클립들은 전부 삭제 처리 됨)

개별 편집 가능 (마우스 스크롤 및 키보드 상/하 키로 조종하여 편집창 가장 상단에 클립을 위치 시킨 뒤 X를 누르면 삭제/복구 됨)

재생 가능 (스페이스바를 누르면 오디오가 재생됨. 가벼운 편집툴로 만들기 위해 영상은 재생되지 않고 오디오만 재생됨)


이 프로젝트를 컴파일하려면 SFML을 링크하여야 하고, FFMPEG가 PC에 설치되어 있어야 합니다.
c++를 기반으로 작성되었고, SFML을 기반으로 간단한 GUI를 보여줍니다.
마우스를 스크롤하여 막대들을 선택할 수 있습니다.
초록색 막대는 비디오에서 제거되지 않고 남아있을 부분을 의미합니다.
스페이스바를 눌러서 각 막대를 재생시켜볼 수 있습니다.
빨간색 막대는 비디오에서 제거될 부분을 의미합니다. 무음 구간은 자동으로 인식이 되지만, 마음에 들지 않을 경우 x키를 눌러서 막대의 색깔을 바꿀 수 있습니다.
확인을 완료한 뒤에 GUI 윈도우의 창을 닫으면 편집이 시작됩니다.

To compile this project, you must link SFML and have FFMPEG installed on your PC.
It is written based on c++ and shows a simple GUI based on SFML.
You can scroll through the mouse to select the bars.
The green bar means the part that will remain unremoved from the video.
Press the space bar to play each bar.
The red bar means the part to be removed from the video. Silent intervals are recognized automatically, but if you don't like them, you can change the color of the bar by pressing the x key from your keyboard.
After completing the verification, close the GUI window(not console) to start editing.
