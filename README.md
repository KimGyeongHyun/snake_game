# snake_game

C language study

# 작동 방식

    Window, Frame, Element
        Window: 터미널을 가득 채우는 윈도우
            - Main menu window
            - Game window
        Frame: 윈도우 내부 작은 프레임
            - Main menu frame
            - Logo frame
            - Score frame
            - game frame
            ...
        Element: 프레임 내부 실제 게임 데이터가 표현되는 요소
            - snake
            - apple, spike
            - score
            ...

    Window 에서 Frame 객체 생성,
    Frame 에서 Element 객체 생성

# TODO

    메인 메뉴 선택 재구현 

        구현 항목
            1. Main menu window 에서 화살표 누를 경우 메뉴 옆에 표시해야 함 (active)
            2. Main menu window 에서 엔터 누를 경우 active 메뉴에 따라 window 가 바뀌어야 함 
                main game 단에서 window index 정보 인지 필요

        전제 

            main game 에서 있어야 할 것
                window index 
                window index enum, length 

            main menu window 에서 있어야 할 것 
                main menu frame include
                    active window index, enum, length 
                    struct{active window index, enter flag}
                    control cative window index function 
                struct 객체 생성 
                하위 함수 호출하여 객체 갱신 및 enter 조건 확인
                    enter 일 경우 
                    상위 main game 으로 정보 전달 필요 


            main menu frame 에서 있어야 할 것 
                active window index
                active window index enum, length 
                struct {active window index, enter flag}
                control active window index function
                    키보드 입력을 받아 객체 갱신
                객체 print 

            main menu 에서 있어야 할 것 - X

    사용하지 않는 include 파일 제거
    사용하지 않는 #define, 상수, 변수 제거

# Long view

    C언어 배열, 포인터, 파일 관리 방법 스터디

        포인터 사용 시점
            구조체 (전반적인 configuration data)
            전역 변수
            함수 포인터

        Visual Studio 2022 사용법
            IDE 전반적인 작동 방식
                map 파일 유무
                config(debug) 파일 유무
                sln 파일 역할
                빌드 파일 저장 경로
            RAM 사용량 및 데이터 주소 직접 확인 방법
