#include <stdio.h>

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //3*3 게임판

void printBoard () { //현재 게임판 상태를 출력
    printf("\n");
    for (int i=0; i<3; i++) {
        printf("| %c | %c | %c |\n",board[i][0],board[i][1],board[i][2]);
    }
    printf("\n");
}

int checkWin() {
    for (int i=0; i<3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) //가로 한줄 완성
            return 1;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) //세로 한줄 완성
            return 1;
    }

    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) // '\' 대각선 완성
        return 1;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) // '/' 대각선 완성
        return 1;

    return 0; // 아직 완성 없음
}

int main() {
    int gameResult = 0; //게임이 진행중이면 0, 누구 한명이 이겼으면 1
    int turn = 0; //게임이 진행된 턴 수
    int player = 1; //플레이어 1 = 1, 플레이어 2 = 2
    int selectNumber;
    int row; //게임판의 행
    int column; //게임판의 열
    char mark; //O 또는 X

    printf("틱텍토 게임을 시작합니다.\n");
    printf("플레이어 1은 o, 플레이어 2는 x로 표시됩니다.\n");
    printf("한줄을 먼저 완성하면 이기고 두 플레이어 모두 완성하지 못하면 무승부로 게임이 종료됩니다.\n");

    while (gameResult == 0 && turn < 9) {

        printBoard();

        if (turn % 2 == 0)
            player = 1;
        else
            player = 2;

        if (player == 1)
            mark = 'o';
        else
            mark = 'x';

        printf("플레이어 %d 차례입니다. 번호를 입력하세요(1~9) : ",player);
        scanf("%d",&selectNumber);

        row = (selectNumber-1) / 3; //입력한 번호의 행을 행렬식(0~2)으로 입력
        column = (selectNumber-1) % 3; //입력한 번호의 열을 행렬식으로(0~2)으로 입력

        if (selectNumber >= 1 && selectNumber <= 9 && board[row][column] != 'o' && board[row][column] != 'x') {
            board[row][column] = mark;
            turn++;
            gameResult = checkWin();
        }
        else
            printf("선택할 수 없는 번호입니다. 다른 번호를 선택하세요.\n");

    }

    printBoard();

    if (gameResult == 1) {
        printf("플레이어 %d가 승리하였습니다.\n",player);
    }
    else if (turn == 9) {
        printf("무승부 입니다.\n");
    }

    return 0;
}

