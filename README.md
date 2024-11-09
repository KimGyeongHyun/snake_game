# snake_game

C language study

# TODO

    game window 구상 및 작성
        1. snake, apple, spike, score 등의 기능 구현

            direction 을 받았을 경우 동작하게만 구현 (snake 모듈화 방식) - 완료

                gameWindow 실행 파일에서 게임 조건을 추가하여 snake 가 움직이는 타이밍 조절

                snake direction 이 이전 direction과 반대일 경우 동작하지 않아야 함
                    ->snake 가 전에 이동한 direction 을 알아야 함

                    구현
                        snake 내부에 이전에 이동한 extern direction 변수 추가
                        gameWindow 단에서 해당 변수를 확인, 반대일 경우 적절하게 처리

            snake 길이 증가 구현
            apple 과 spike 구현

            게임 조건 구현 (snake 모듈화 방식)
                snake 가 gameFrame 에서만 동작하도록 구현
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
