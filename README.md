# snake_game

C language study

# TODO

    메인메뉴 인덱스 전역 변수 작동 방식 구상
        menu index enter -> window index 전환 방식 구상
        index 변수 선언 파일 위치 결정
        구조체 형식 사용 고려 (config 구조체)
        모든 메뉴 진입 정상 작동 테스트

    game frame 구상 및 작성

# Long view

    C언어 배열, 포인터, 파일 관리 방법 스터디

        상수 배열 헤더 선언
            헤더에 extern const 선언, 실행 파일에 정의
            extern 없이 const 선언할 경우 해당 헤더를 include 하는 모든 실행 파일이 const 변수를 RAM 메모리에 올림

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
