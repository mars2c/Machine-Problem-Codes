#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int snakepos_start(){
    int Sstart = 0;

    while(Sstart < 20){
        Sstart = (rand() % 99) + 1;
    }

printf("[debug] Start = %d\n", Sstart);
    return Sstart;
}

int snakepos_end(int Sstart){
    int Send = 100;
    int flag;

    flag = 0;

    while(flag == 0){
        Send = (rand() % 98) + 1;
        if(Send < 80){
            if(Send <= (Sstart - 20)){
                flag = 1;
            }
        }
    }

printf("[debug] Send = %d\n", Send);
    return Send;
}

int ladderpos_end(int Lstart){
    int Lend = 0;

    while(Lend < 20){
        Lend = (rand() % 99) + 1;
    }

    return Lend;
}

int ladderpos_start(){
    int Lstart = 100;
    int flag;

    flag = 0;

    while(flag == 0){
        Lstart = (rand() % 98) + 1;
        if(Lstart < 80){    
            flag = 1;
        }
    }
    return Lstart;
}

//For board positioning
void createSnakeLadder(char *array){
    int i;
    int s1, s2, s3;
    int S1, S2, S3;
    int l1, l2, l3;
    int L1, L2, L3;

/*        for(int ctr = 0; ctr < 100; ctr++){

        printf("k: %c ", array[ctr]);
    }
*/

//Snakes random positions //X, Y, Z
S1 = 0;
    S1 = snakepos_start();//Snek start 1
    array[S1] = 'X';
    printf("[debug] arrayS1: S1: %d %c\n", S1, array[S1]);
s1 = 0;
    s1 = snakepos_end(S1);//snek end 1
    printf("[debug] before arrays1: %c\n", array[s1]);
    if(array[s1] == ' '){
        array[s1] = 'x';
    }
    else{
        while(array[s1] != ' '){
            s1 = snakepos_end(S1);
        }
        array[s1] = 'x';
    }
    printf("[debug] arrays1: s1:%d %c\n", s1, array[s1]);
S2 = 0;
    S2 = snakepos_start();//Snek start 2
    if(array[S2] == ' '){
        array[S2] = 'Y';
    }
    else{
        printf("[debug] S2: %c\n", array[S2]);
        while(array[S2] != ' '){
            S2 = snakepos_start();
        }
        array[S2] = 'Y';
    }
    printf("[debug] arrayS2: S2: %d %c\n", S2, array[S2]);
s2 = 0;
    s2 = snakepos_end(S2);//snek end 2
    if(array[s2] == ' '){
        array[s2] = 'y';
    }
    else{
        while(array[s2] != ' '){
            s2 = snakepos_end(S2);
        }
        array[s2] = 'y';
    }
    printf("[debug] arrays2: s2:%d %c\n", s2, array[s2]);
S3 = 0;
    S3 = snakepos_start();//Snek start 3
    if(array[S3] == ' '){
        array[S3] = 'Z';
    }
    else{
        while(array[S3] != ' '){
            S3 = snakepos_start();
        }
        array[S3] = 'Z';
    }
    printf("[debug] arrayS3: S3:%d %c\n", S3, array[S3]);
s3 = 0;
    s3 = snakepos_end(S3);//snek end 3
    if(array[s3] == ' '){
        array[s3] = 'z';
    }
    else{
        while(array[s3] != ' '){
            s3 = snakepos_end(S3);
        }
        array[s3] = 'z';
    }
    printf("[debug] arrays3: s3:%d %c\n", s3, array[s3]);
    printf("\n [debug] inside createSnakeLadder; after s3\n");

//Ladder random positions //L, M, N
L1 = 0;
    L1 = ladderpos_start();//Ladder start 1
    if(array[L1] == ' '){
        array[L1] = 'L';
    }
    else{
        while(array[L1] != ' '){
            L1 = ladderpos_start();
        }
        array[L1] = 'L';
    }
    printf("[debug] L1:%d arrayL1: %c\n", L1, array[L1]);
    printf("\n [debug] inside createSnakeLadder; after L1\n");
l1 = 0;
    l1 = ladderpos_end(L1);//ladder end 1
    if(array[l1] == ' '){
        array[l1] = 'l';
    }
    else{
        while(array[l1] != ' '){
            l1 = ladderpos_end(L1);
        }
        array[l1] = 'l';
    }
    printf("[debug] l1:%d arrayl1: %c\n", l1, array[l1]);
    printf("\n [debug] inside createSnakeLadder; after l1\n");
L2 = 0;
    L2 = ladderpos_start();//Ladder start 2
//    printf("array %d: %c \n", L2, array[L2]);
    if(array[L2] == ' '){
        array[L2] = 'M';
    }
    else{
        while(array[L2] != ' '){
            L2 = ladderpos_start();
        }
        array[L2] = 'M';
    }
    printf("[debug] L2:%d arrayL2: %c\n", L2, array[L2]);
    printf("\n [debug] inside createSnakeLadder; after L2\n");
l2 = 0;
    l2 = ladderpos_end(L2);//ladder end 2
    if(array[l2] == ' '){
        array[l2] = 'm';
    }
    else{
        while(array[l2] != ' '){
            l2 = ladderpos_end(L2);
        }
        array[l2] = 'm';
    }
    printf("[debug] l2:%d arrayl2: %c\n", l2, array[l2]);
    printf("\n [debug] inside createSnakeLadder; after l2\n");
L3 = 0;
    L3 = ladderpos_start();//Ladder start 3
    array[L3] = 'N';
    if(array[L3] == ' '){
        array[L3] = 'N';
    }
    else{
        while(array[L3] != ' '){
            L3 = ladderpos_start();
        }
        array[L3] = 'N';
    }
    printf("[debug] L3:%d arrayL3: %c\n", L3, array[L3]);
l3 = 0;
    l3 = ladderpos_end(L3);//ladder end 3
    if(array[l3] == ' '){
        array[l3] = 'n';
    }
    else{
        while(array[l3] != ' '){
            l3 = ladderpos_end(L3);
        }
        array[l3] = 'n';
    }
    printf("[debug] l3:%d arrayl3: %c\n", l3, array[l3]);
        printf("\n [debug] inside createSnakeLadder; after Ladder\n");

    for(int ctr = 0; ctr < 100; ctr++){

        printf("%d: %c ", ctr, array[ctr]);
    }

}//end createSnakeLadder function

// Draw the Snake and Ladder array[100]
void drawSnakeLadder(int start, int end, int direction, char *slarray){
    int ctr;

    // If array is to be processed in ascending order
    if(direction == 0){
        for(ctr=0; ctr < 10; ctr++){
            printf("   %c",*(slarray + (start + ctr)));
        }
    }
    // If array is to be processed in descending order
    else if(direction == 1){
        for(ctr=0; ctr < 10; ctr++){
            printf("   %c",*(slarray + (end - ctr)));
        }
    }
}// end of drawSnakeLadder

// Draw the player[100][4]  using the supplied start and end index
/*void drawPlayer(char *array, int start, int end, int direction){
    int ctr,players;

    // If array is to be processed in ascending order
    if(direction == 0){
        for(ctr=0; ctr < 10; ctr++){
            for(players=0; players < 4; players++){
                printf("%c",*(*(array + (start+ctr) ) + players))
            }        
        }
    } // end direction==0
    // If array is to be processed in descending order
    else if(direction == 1){
        for(ctr=0; ctr < 10; ctr++){
           for(players=0; players < 4; players++){
                printf("%c",*(*(array + (end-ctr) ) + players))
            }        
        }
    } // end direction==1
    else
        printf("ERROR: Wrong direction was supplied");
} // end drawArray()
*/

// Draw the lines of the board
void drawBorder(){
    int ctr, loop; 

    // Print the start side border
    printf("|");
    // Print the middle lines
    for(loop=0; loop < 10; loop++){
        for( ctr=0; ctr < 5; ctr++){
            if((loop == 9) && (ctr == 4))
                printf("|");
            else if(ctr == 4)
                printf("+");
            else
                printf("-");
        }
    }
    // Move to the next line
    printf("\n");
} // end drawBorder()

int dieroll(int dice){

    srand(time(0));
    dice = (rand() % 6) + 1;

    return dice;
}//end dieroll 

int main(){
    int a, b, c, d;
    int dice;
    int player, win, ctr;
    char slarr[100];
    char *sl;

//initialize slarr
    for(ctr = 0; ctr < 100; ctr++){
        slarr[ctr] = ' ';
    }

    createSnakeLadder(slarr);
    player = 0;
    win = 0;

    while(win == 0){
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(99, 90, 1, slarr);//descend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(80, 89, 0, slarr);//ascend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(79, 70, 1, slarr);//descend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(60, 69, 0, slarr);//ascend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(59, 50, 1, slarr);//descend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(40, 49, 0, slarr);//ascend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(39, 30, 1, slarr);//descend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(20, 29, 0, slarr);//ascend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(19, 10, 1, slarr);//descend
        printf("\n");
        drawBorder();
        printf("\n");
        drawSnakeLadder(0, 9, 0, slarr);//ascend
        printf("\n");
        drawBorder();

        if(player == 0){
            printf("a's turn.\n");
            printf("a, press <Enter> to roll.\n");
            printf("a rolls a %d", dieroll(dice));
        }
        else if(player == 1){
            printf("b's turn.\n");
            printf("b, press <Enter> to roll.\n");
            printf("a rolls a %d", dieroll(dice));
        }
        else if(player == 2){
            printf("c's turn.\n");
            printf("c, press <Enter> to roll.\n");
            printf("a rolls a %d", dieroll(dice));
        }
        else{ //if(player == 3){
            printf("d's turn.\n");
            printf("d, press <Enter> to roll.\n");
            printf("a rolls a %d", dieroll(dice));
        }


        if(player == 0){
            player = 1;
        }
        else if(player == 1){
            player = 2;
        }
        else if(player == 2){
            player = 3;
        }
        else{
            player = 0;
        }

    win = 1;

    }


    return 0;
}


/*int boardfunc(char *in){
    char board[20][10];
    int s1, s2, s3;
    int S1, S2, S3;
    int L1, L2, L3;
    int l1, l2, l3;

    

    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|#   |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |%c  |\n");
    printf("|----+----+----+----+----+----+----+----+----+----|\n");



}//end board func
*/