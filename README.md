# snake_game

C language study

# TODO

    game window 구상 및 작성
        1. snake, apple, spike, score 등의 기능 구현

            snake 길이 증가, apple 구현

                apple 구현

                    gameWindow 에서 snake 확장 함수 사용
                        snake 와 apple 이 만날 경우 해당 함수 수행

                    apple 도 snake 와 같이 동적으로 할당
                        관리 방식 구상



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
