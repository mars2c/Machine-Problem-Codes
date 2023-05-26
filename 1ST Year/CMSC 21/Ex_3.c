#include <stdio.h>

int subboard(char in[9]){
    char board[3][3] = {{in[0],in[1],in[2]},{in[3],in[4],in[5]},{in[6],in[7],in[8]}};

        printf("\n");
        printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
        printf("\n");

return 0;
}

int getindex(int row, int col){
    if(row == 0 && col == 0){
        return 0;
    }
    else if(row == 0 && col == 1){
        return 1;
    }
        else if(row == 0 && col == 2){
        return 2;
    }
        else if(row == 1 && col == 0){
        return 3;
    }
        else if(row == 1 && col == 1){
        return 4;
    }
        else if(row == 1 && col == 2){
        return 5;
    }
        else if(row == 2 && col == 0){
        return 6;
    }
        else if(row == 2 && col == 1){
        return 7;
    }
        else if(row == 2 && col == 2){
        return 8;
    }
    else{
        return 9;
    }
}

int checkwin(char in[9]){

    if(in[0] == in[1] && in[0] == in[2] && in[0] != ' '){
        return 1;
    }
    else if(in[0] == in[3] && in[0] == in[6] && in[0] != ' '){
        return 1;
    }
    else if(in[0] == in[4] && in[0] == in[8] && in[0] != ' '){
        return 1;
    }    
    else if(in[1] == in[4] && in[1] == in[7] && in[1] != ' '){
        return 1;
    }
    else if(in[2] == in[5] && in[2] == in[8] && in[2] != ' '){
        return 1;
    }
    else if(in[2] == in[4] && in[2] == in[6] && in[2] != ' '){
        return 1;
    }
    else if(in[3] == in[4] && in[3] == in[5] && in[3] != ' '){
        return 1;
    }
    else if(in[6] == in[7] && in[6] == in[8] && in[6] != ' '){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    char in[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int rowsize, colsize, row, col, i, j;
    int win, player, index;
    char flag;

    win = 0;
    rowsize = 3;
    colsize = 3;
    row = 0;
    col = 0;
    player = 0;
    flag = ' ';

    subboard(in);

    while(win == 0){

        if(player == 0){
            printf("X's turn\n\n");
        }
        else{
            printf("O's turn\n\n");
        }

        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);

        index = getindex(row, col);

        if(in[index] != ' '){
            printf("\n(%d, %d) Occupied/Does not exist\n\n", row, col);
            continue;
        }

        if(player == 0){
            in[index] = 'X';
            flag = 'X';
        }
        else{
            in[index] = 'O';
            flag = 'O';
        }

        subboard(in);
        if(checkwin(in) == 1){
            printf("%c wins! Congratulations!", flag);
            win = 1;
        }
        
        if(player == 0){
            player = 1;
        }
        else{
            player = 0;
        }


    }

return 0;    
}