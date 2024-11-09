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

    menu 도 element 로 봐야할지 생각, 구상 - 완료
        element 로 보고 window 를 변경할 땐 해당 element 를 참고만 하는 방식으로 작성하기

    snake, apple 출력 방식 검토
        현재 gameWindow 에서 Element 내 출력 함수를 불러와 출력 중
        gameFrame 에서 작동하는 코드는 empty frame 출력 뿐
        gameFream 에서 element 출력이 되어야 함
        Windown 와 Frame 에서 선언해야 하는 변수를 명확하게 구별할 필요 있음
            score 는 window, 그 외 snake, apple, spike 는 frame ...

    코드 다듬기
        gameWindow 에서 각 element 호출 방식 재확인
        gameWindow, snake, apple 함수, 변수 정리, 리팩토링
        주석 추가
        향후 수정할 점 정리

    game window 구상 및 작성
        1. snake, apple, spike, score 등의 기능 구현

            snake 길이에 따른 apple 랜덤 추가 구현
                snake 길이 리턴 함수 구현
                향후 spike 도 해당 타이밍에 함께 추가

            게임 조건 구현 (snake 모듈화 방식)
                snake 가 gameFrame 에서만 동작하도록 구현
                spike 구현
                snake 가 본인 몸을 물었을 경우 게임 오버 구현

        2. 게임 작동 방식 구현

            다른 브랜치에서 구상


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
