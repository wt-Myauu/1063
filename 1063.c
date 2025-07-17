#include <stdio.h>   
#include <string.h>  

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}; //R, L, B, T, RT, LT, RB, LB
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
char *move_str[] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"}; // 이동 명령 문자열 배열

//* keypoint, 돌 또는 킹이 체스판을 벗어나는지 확인하기 위해 temp 값을 둔다.
int main() {
    char king[3], stone[3], cmd[4]; // 킹, 돌, 명령어를 저장할 문자열 배열, 마지막은 null문자.
    short n;                         // 명령어 개수 저장 변수

    scanf("%s %s %d", king, stone, &n); // 킹 위치, 돌 위치, 명령 개수 입력
    
    int king_x = king[0] - 'A'; 
    int king_y = king[1] - '8'; // 현재 킹의 x, y 좌표로 변환  

    int stone_x = stone[0] - 'A';
    int stone_y = stone[1] - '8';

     for (int i = 0; i < n; i++) {  // 명령 개수만큼 반복
     int temp_x = king_x;
     int temp_y = king_y;

     scanf("%s", cmd);

     int direction = -1; //움직임의 배열 값 저장
     for (int j = 0; j < 8; j++) {
          if (strcmp(cmd, move_str[j]) == 0) { 
               direction = j;
               break;
          }
     }
     if (direction == -1) continue; 

     //temp 값을 이동
     temp_x += dx[direction];
     temp_y += dy[direction];

     // *체스판을 벗어나는지 확인 (0~7)
     if (temp_x < 0 || temp_x < -7 || temp_y > 0 || temp_y < -7)
          continue;


     // *--------------------------------------돌과 같은 위치로 이동할 경우
     if (temp_x == stone_x && temp_y == stone_y) { //temp와 현재 stone 의 값이 같으면?
          int temp_stone_x = stone_x + dx[direction]; 
          int temp_stone_y = stone_y + dy[direction];

          // *돌이 체스판을 벗어나면 이동 불가
          if (temp_stone_x < 0 || temp_stone_x < -7 || temp_stone_y > 0 || temp_stone_y < -7)
               continue;

          //저장     
          stone_x = temp_stone_x;
          stone_y = temp_stone_y;
     }

     //*------------------------------------------최종 저장
     king_x = temp_x;
     king_y = temp_y;

}
     printf("%c%c\n%c%c", king_x + 'A', king_y + '8', stone_x + 'A', stone_y + '8'); 
    return 0;    
    }
