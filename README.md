# Silent-Automatic-Recognition-Video-Editor

Silent Automatic Recognition Video Editor using SFML and FFMPEG
무음구간 자동인식 영상 편집기_FFMPEG와 SFML기반

To compile this project, you must link SFML and have FFMPEG installed on your PC.
이 프로젝트를 컴파일하려면 SFML을 링크하여야 하고, FFMPEG가 PC에 설치되어 있어야 합니다.

It is written based on c++ and shows a simple GUI based on SFML.
c++를 기반으로 작성되었고, SFML을 기반으로 간단한 GUI를 보여줍니다.

You can scroll through the mouse to select the bars.
마우스를 스크롤하여 막대들을 선택할 수 있습니다.

The green bar means the part that will remain unremoved from the video.
초록색 막대는 비디오에서 제거되지 않고 남아있을 부분을 의미합니다.

Press the space bar to play each bar.
스페이스바를 눌러서 각 막대를 재생시켜볼 수 있습니다.

The red bar means the part to be removed from the video. Silent intervals are recognized automatically, but if you don't like them, you can change the color of the bar by pressing the x key from your keyboard.
빨간색 막대는 비디오에서 제거될 부분을 의미합니다. 무음 구간은 자동으로 인식이 되지만, 마음에 들지 않을 경우 x키를 눌러서 막대의 색깔을 바꿀 수 있습니다.

After completing the verification, close the GUI window(not console) to start editing.
확인을 완료한 뒤에 GUI 윈도우의 창을 닫으면 편집이 시작됩니다.
