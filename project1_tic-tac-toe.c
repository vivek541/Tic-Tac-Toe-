#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

char board[] = {'1','2','3','4','5','6','7','8','9'};
void printBoard();                                      /*keeps track of the board's current status and prints it accordingly*/

int checkPos[9] = {1,1,1,1,1,1,1,1,1};                  /*1 means slot is vacant, 0 means the opposite*/
bool allPosFilled();
int checkWin();                                         /*returns 1 if player 1 won, 2 if player 2 won else -1 if nobody has won yet*/

int main(){

    int player = 1, pos;     /*default: player 1 will make the first move in the game*/

    while(true){

        /*1. taking player input(pos)... */

        printBoard();
        printf("\nEnter the position player %d : ", player);
        scanf("%d", &pos);

        /*2. checking if the position is valid or invalid and proceeding **accordingly... */

        if(checkPos[pos-1]){
            board[pos-1] = (player == 1) ? 'X' : '0';
            checkPos[pos-1] = 0;
        }
        else{
            printf("invalid move player %d, press any key to try again...\n", player);
            getch();
            continue;
        }

        /*3. checking if somebody won or not...*/

        if(checkWin() == 1){
            printBoard();
            puts("\nplayer 1 won!\n\n");
            break;
        }
        else if(checkWin() == 2){
            printBoard();
            puts("\nplayer 2 won!\n\n");
            break;
        }
        else if(allPosFilled()){            /*when no player wins and all positions in the board are filled then there is a stalemate...*/
            printBoard();
            puts("\nstalemate!!\n\n");
            break;
        }
        else{
            player = (player == 1) ? 2 : 1;  /*switching players since no one has won yet*/
        }
    }

    return 0;
}

void printBoard(){  /*plagiarism :p */

    system("cls");
    printf("\n\n---------------------Tic Tac Toe----------------------\n\n");

    printf("            Player 1 (X)  -  Player 2 (0)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}

int checkWin(){

    //horizontal cases... r1, r2, r3

    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') return 1;
    if(board[0] == '0' && board[1] == '0' && board[2] == '0') return 2;

    if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') return 1;
    if(board[3] == '0' && board[4] == '0' && board[5] == '0') return 2;

    if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') return 1;
    if(board[6] == '0' && board[7] == '0' && board[8] == '0') return 2;

    //vertical cases... c1, c2, c3

    if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') return 1;
    if(board[0] == '0' && board[3] == '0' && board[6] == '0') return 2;

    if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') return 1;
    if(board[1] == '0' && board[4] == '0' && board[7] == '0') return 2;

    if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') return 1;
    if(board[2] == '0' && board[5] == '0' && board[8] == '0') return 2;

    //diagonal cases...

    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') return 1;
    if(board[0] == '0' && board[4] == '0' && board[8] == '0') return 2;

    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') return 1;
    if(board[2] == '0' && board[4] == '0' && board[6] == '0') return 2;

    //in case no player has won yet...

    return -1;
}

bool allPosFilled(){

    for(int i = 0; i< 9; i++) if(checkPos[i] == 1) return false;

    return true;
}
