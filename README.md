# snake_game

C language study

# TODO

    game window 구상 및 작성
        1. game frame 구현 - 완료
        2. score frame 구현 - 완료
        3. snake, apple, spike, score 등의 변수 선언 및 초기화
            game window 에 선언, 하위 frame 이나 element 에서 제어하도록 구조 설계
                snake 의 경우 링크드 리스트로 관리

                이동 로직 구현

                    // prevX 는 포인터에 갱신할 위치
                    c// urrX 는 다음 포인터에 갱신할 위치

                    현재 x를 currX 에 저장
                    현재 x를 갱신
                    포인터 이동

                    반복
                    {
                        prevX 에 currX 저장
                        현재 x를 currX 에 저장
                        현재 x를 prevX로 갱신
                        포인터 이동
                    } 포인터가 NULL이 아닐 때까지 반복


                snake가 본인 위치만 알고 있을 때 showSnake 문제점
                    마지막 snake 가 지나간 곳은 ' '로 지워야 함
                    snakeBody 는 자기 자신의 위치 정보만 가지고 있고, 지나간 곳의 정보를 가지고 있지 않음
                    snakeBody 객체로만은 showSnake 할 경우 지나간 곳에 대한 정보가 없기 때문에 지울 수가 없음

                    해결점
                        1. move 내 show 수행
                            moveSnake 에 지나간 곳에 대한 정보가 남아 있음
                            move 를 하면서 동시에 show 를 하면 가능함
                            단점: move 와 show 모듈화 불가
                        2. snake 가 지나간 자리에 대해서 정보를 가지게 하게끔 함 (tail 이후에 객체 하나 더 연결, 해당 객체는 지나간 자리를 나타냄)
                            move와 show 모듈화 가능
                            간단한 구현
                            단점
                                1. snake 객체에 snake 가 아닌 지나간 자리 객체 추가 -> 단일 책임 원칙 위반 가능성

                        2번 방법으로 해결 진행





            keyboard 입력 define 은 system 쪽에 배치, menu 와 game 에서 둘 다 사용하도록 설계 - 완료
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
