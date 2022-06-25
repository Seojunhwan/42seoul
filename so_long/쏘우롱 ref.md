쏘롱 참고한 자료들
정말 감사합니다.

[42doc](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

[solong guide](https://techdebt.tistory.com/29#recentComments)

[minilbx guide](https://velog.io/@jeunghoon/MiniLibX%EB%A5%BC-%EA%B3%B5%EB%B6%80%ED%95%B4%EB%B3%B4%EC%9E%90#16T)

[code example](https://bigpel66.oopy.io/library/c/etc/3)

[정리천재](https://github.com/terry-yes/mlx_example)

예외처리 
- argc, argv 확인
- 맵파일이 없는 경우
- 맵 뚫려있는 경우
- 맵 확장자 체크
- 플레이어 두 명
- P,C,E 하나 이상 (플레이어는 1명 고정), C, E 다수 ok
- 맵이 직각 사각형이여야 함
- 맵 한 줄 비워있는지 확인? (개행 두 번 연속 확인)

라이브러리 설치해서 창 띄우기
키 hook
images 사용해서 이미지 넣어보기
파일 가져와서 맵 만들기
게임처럼 동작하도록 만들기
에러 처리
평가 준비

leaks

컴파일 -g 플래그 사용
lldb ./a.out


순서

libft [make]
get_next_line [libft -> make]
mlx [make]
so_long