# snake_game

C language study

# TODO

    game window 구상 및 작성
        1. game frame 구현 - 완료
        2. score frame 구현 - 완료
        3. snake, apple, spike, score 등의 변수 선언 및 초기화
            game window 에 선언, 하위 frame 이나 element 에서 제어하도록 구조 설계
                snake 의 경우 링크드 리스트로 관리
            keyboard 입력 define 은 system 쪽에 배치, menu 와 game 에서 둘 다 사용하도록 설계
        4. ms delay 구현
            loop 문에 sleep 을 사용하여 카운터 적용


    사용하지 않는 include 파일 제거

    사용하지 않는 #define, 상수, 변수 제거

# Long view

    C언어 배열, 포인터, 파일 관리 방법 스터디

        C언어 링크드 리스트 구현 스터디
            Snake 몸체 만드는 데 활용

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
