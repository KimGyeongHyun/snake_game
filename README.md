# snake_game

C language study

# TODO

    메인메뉴 인덱스 전역 변수 작동 방식 구상 - 완료
        menu window 에 어떤 메뉴가 active 상태인지 결정하는 extern 변수 선언 (menuIndex)
        menu frame 에서 해당 변수를 포인터로 받아 제어
        menu에서 enter 입력 시 상위 game 에서 menuIndex 를 받아 어떤 window 를 출력할지 windowIndex 에 갱신
        menuIndex -> windowIndex 변환을 위한 내부 const 배열 사용

    game frame 구상 및 작성

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
