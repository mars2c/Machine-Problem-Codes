#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Structure for the players' positions
typedef struct PlayerPosition{
   int A;
   int B;
   int C;
   int D;
}Player;

// Structure for the Snakes' positions
typedef struct SnakesPosition{
	int Xstart;
	int Xend;
	int Ystart;
	int Yend;
	int Zstart;
	int Zend;
}Snake;

// Structure for the Ladders' positions
typedef struct LaddersPosition{
	int Lstart;
	int Lend;
	int Mstart;
	int Mend;
	int Nstart;
	int Nend;
}Ladder;

// Generate the snake starting position
// Snake start should be greater than 19
int snakepos_start(){
   int Sstart;
   int flag = 0;
   
   while(flag == 0){
      Sstart = 0;
      srand(time(NULL));
      Sstart = (rand() % 99) + 1;
      if(Sstart > 19){
           flag = 1;
      }//if end
   }//while end
   return Sstart;
}//snakepos_start() end

// Generate the snake end position
// Snake end should be less than 80 and at least 20 steps below the start position 
int snakepos_end(int Sstart){
   int Send;
   int flag = 0;
   
   while(flag == 0){
      Send = 0;
      Send = (rand() % 98) + 1;
      if(Send < 80){
         if(Send <= (Sstart - 20)){
            flag = 1;
         }//if end
      }//if end
   }//while end
   return Send;
}//snakepos_end() end

// Generate the ladder start position (1 - 80)
// Ladder start should be less than 81 so that end will be up to 99 only.
int ladderpos_start(){
   int Lstart;
   int flag = 0;

   while(flag == 0){
      Lstart = 100;
      Lstart = (rand() % 98) + 1;
        if(Lstart < 81){    
            flag = 1;
        }//if end
    }//while end
    return Lstart;
}//ladderpos_start() end

// Generate the ladder end position (21 - 99)
// Ladder end position should be above above 20 and at least 20 steps from ladder start
int ladderpos_end(int Lstart){
   int Lend;
   int flag = 0;
   
   while(flag == 0){
      Lend = 0;
      Lend = (rand() % 99) + 1;
      if(Lend > 20){
         if(Lend >= (Lstart + 19)){
            flag = 1;
         }//if end
      }//if end
   }//while end
   return Lend;
}//ladderpos_end() end

/* Do this function at the start of the game
Generate the 3 Snakes random start/end positions
Generate the 3 Ladder random start/end positions
Snake starts/ends will have letters "X", "Y", "Z" / "x", "y", "z"
Ladder starts/ends will have letters "L", "M", "N" / "l", "m", "n"
*/
void createSnakeLadder(char (*SLarray)[4], Snake *snake, Ladder *ladder){
   int i;
   int s1, s2, s3;
   int S1, S2, S3;
   int l1, l2, l3;
   int L1, L2, L3;
   
   // Snake start X
   S1 = 0;
   S1 = snakepos_start();
   *(*(SLarray + S1) + 0) = 'X';
   snake->Xstart = S1 + 1;
   
   // Snake end x
   s1 = 0;
   s1 = snakepos_end(S1);
   if(*(*(SLarray + s1) + 0) == ' '){
      *(*(SLarray + s1) + 0) = 'x';
   }else{
      while(*(*SLarray + s1) + 0 != ' '){        //Repeat until finding an empty location
         s1 = snakepos_end(S1);
      }//while end
      *(*(SLarray + s1) + 0) = 'x';
   }//if-else end
   snake->Xend = s1 + 1;
   
   // Snake start Y
   S2 = 0;
   S2 = snakepos_start();
   if(*(*(SLarray + S2) + 0) == ' '){
      *(*(SLarray + S2) + 0) = 'Y';
   }else{
      while(*(*(SLarray + S2) + 0) != ' '){
         S2 = snakepos_start();
      }//while end
      *(*(SLarray + S2) + 0) = 'Y';
   }//if-else end
   snake->Ystart = S2 + 1;
   
   // Snake end y
   s2 = 0;
   s2 = snakepos_end(S2);
   if(*(*(SLarray + s2) + 0) == ' '){
      *(*(SLarray + s2) + 0) = 'y';
   }else{
      while(*(*(SLarray + s2) + 0) != ' '){
         s2 = snakepos_end(S2);
      }//while end
      *(*(SLarray + s2) + 0) = 'y';
   }//if-else end
   snake->Yend = s2 + 1;
   
   // Snake start Z
   S3 = 0;
   S3 = snakepos_start();
   if(*(*(SLarray + S3) + 0) == ' '){
      *(*(SLarray + S3) + 0) = 'Z';
   }else{
      while(*(*(SLarray + S3) + 0) != ' '){
         S3 = snakepos_start();
      }//while end
      *(*(SLarray + S3) + 0) = 'Z';
   }//if-else end
   snake->Zstart = S3 + 1;
   
   // Snake end z
   s3 = 0;
   s3 = snakepos_end(S3);
   if(*(*(SLarray + s3) + 0) == ' '){
      *(*(SLarray + s3) + 0) = 'z';
   }else{
      while(*(*(SLarray + s3) + 0) != ' '){
         s3 = snakepos_end(S3);
      }//while end
      *(*(SLarray + s3) + 0) = 'z';
   }//if-else end
   snake->Zend = s3 + 1;
   
   //Ladder start L
   L1 = 0;
   L1 = ladderpos_start();
   if(*(*(SLarray + L1) + 0) == ' '){
      *(*(SLarray + L1) + 0) = 'L';
   }else{
      while(*(*(SLarray + L1) + 0) != ' '){
         L1 = ladderpos_start();
      }//while end
      *(*(SLarray + L1) + 0) = 'L';
   }//if-else end
   ladder->Lstart = L1 + 1;
   
   //Ladder end l
   l1 = 0;
   l1 = ladderpos_end(L1);
   if(*(*(SLarray + l1) + 0) == ' '){
      *(*(SLarray + l1) + 0) = 'l';
   }else{
      while(*(*(SLarray + l1) + 0) != ' '){
         l1 = ladderpos_end(L1);
      }//while end
      *(*(SLarray + l1) + 0) = 'l';
   }//if-else end
   ladder->Lend = l1 + 1;
    
   //Ladder start M
   L2 = 0;
   L2 = ladderpos_start();
   if(*(*(SLarray + L2) + 0) == ' '){
      *(*(SLarray + L2) + 0) = 'M';
   }else{
      while(*(*(SLarray + L2) + 0) != ' '){
         L2 = ladderpos_start();
      }//while end
      *(*(SLarray + L2) + 0) = 'M';
   }//if-else end
   ladder->Mstart = L2 + 1;
   
   //Ladder end m
   l2 = 0;
   l2 = ladderpos_end(L2);
   if(*(*(SLarray + l2) + 0) == ' '){
      *(*(SLarray + l2) + 0) = 'm';
   }else{
      while(*(*(SLarray + l2) + 0) != ' '){
         l2 = ladderpos_end(L2);
      } //while end
      *(*(SLarray + l2) + 0) = 'm';
   }//if-else end
   ladder->Mend = l2 + 1;
   
   //Ladder start N
   L3 = 0;
   L3 = ladderpos_start();   
   if(*(*(SLarray + L3) + 0) == ' '){
      *(*(SLarray + L3) + 0) = 'N';
   }else{
      while(*(*(SLarray + L3) + 0) != ' '){
         L3 = ladderpos_start();
      }//while end
      *(*(SLarray + L3) + 0) = 'N';
   }//if-else end
   ladder->Nstart = L3 + 1;
   
   //Ladder end n
   l3 = 0;
   l3 = ladderpos_end(L3);
   if(*(*(SLarray + l3) + 0) == ' '){
      *(*(SLarray + l3) + 0) = 'n';
   }else{
      while(*(*(SLarray + l3) + 0) != ' '){
         l3 = ladderpos_end(L3);
      }//while end
      *(*(SLarray + l3) + 0) = 'n';
   }//if-else end
   ladder->Nend = l3 + 1;
   
/*   //For debugging purposes only. We print the contents of the SLarray
   for(int ctr = 0; ctr < 100; ctr++){
      printf("%d:%c ", ctr, SLarray[ctr][0]);
      if((ctr % 10) == 0)
          printf("\n");
   }
*/
}//createSnakeLadder() end

// Draw the Snake and Ladder array[100][4]
void drawSnakeLadder(int start, int end, int direction, char (*slarray)[4]){
   int ctr,loop;

   if(direction == 0){                           //Ascending order ex. 1-10
      for(ctr=0; ctr < 10; ctr++){
         for(loop=0; loop < 4; loop++){
            if(loop == 3){
               printf("%c", *(slarray + (start + ctr))[0]);
            }else{
               printf(" ");
            }//if-else end
         }//for end
      }//for end
   }else if(direction == 1){                     //Descending order ex. 11-20
      for(ctr=0; ctr < 10; ctr++){
         for(loop=0; loop < 4; loop++){
            if(loop == 3){
               printf("%c", *(slarray + (end - ctr))[0]);
            }else{
               printf(" ");
            }//if-else end
         }//for end
      }//for end
    }//if-else end
}//drawSnakeLadder() end

//Draw the players position
void drawPlayer(int start, int end, int direction, char (*playerArr)[4]){
   int ctr, loop;

   if(direction == 0){                           //Ascending order ex. 1-10
      for(ctr=0; ctr < 11; ctr++){
         for(loop=0; loop < 4; loop++){
            printf("%c", *(*(playerArr + (start + ctr)) + loop));
         }//for end
      }//for end
   }else if(direction == 1){                     //Descending order ex. 11-20
      for(ctr=0; ctr < 10; ctr++){
         for(loop=0; loop < 4; loop++){
            printf("%c", *(*(playerArr + (end + 1 - ctr)) + loop));
         }//for end
      }//for end
   }//if-else end
}//drawPlayer() end

// Draw the game the board
void drawBoard(int start, int direction){
   int ctr, loop; 

   if(direction == 0){                           //Descending numbers
      for(loop=0; loop < 10; loop++){
         for( ctr=0; ctr < 4; ctr++){
            if(((start - loop) == 100) && (ctr == 1)){
               printf("%d", start - loop);
               break;
            }else if(ctr == 3){
               printf("%d", start - loop);
            }else if((ctr == 0) || (ctr == 1)){
               printf(" ");
            }else{
            }//if-else end
         }//for end

      }//for end
   }else if(direction == 1){                     //Ascending numbers
      for(loop=0; loop < 10; loop++){
         for( ctr=0; ctr < 4; ctr++){
            if(ctr == 3){
               if((start + loop) < 10){
                  printf("0%d", start + loop);
               }else {
                  printf("%d", start + loop);
               }//if-else end
            }else if((ctr == 0) || (ctr == 1)){
               printf(" ");
            }else{
            }//if-else end
         }//for end

      }//for end
   }else{                                        //Boundary
      for(loop=0; loop < 10; loop++){
         for( ctr=0; ctr < 4; ctr++){
            if((loop == 9) && (ctr == 4))
               printf("|");
            else
                printf("-");
         }//for end    
      }//for end    
   }//if-else end
    // Move to the next line
    //printf("\n");
}//drawBorder() end

//Roll the dice
int dieroll(){
   int dice = 0;
   
   srand(time(0));
   dice = (rand() % 6) + 1;

   return dice;
}//dieroll() end 

//Draw the whole game board (border, snake-ladder position, player position) 
void drawGameBoard(char (*slarr)[4], char (*players)[4]){
   int toRight = 0;       //descending direction
   int toLeft = 1;        //acending direction
   int border = 2;
   
   printf("\n");
   drawBoard(100, border);
   printf("\n");
   drawBoard(100, toRight);
   printf("\n");
   drawSnakeLadder(90, 99, 1, slarr);//descend
   printf("\n");
   drawPlayer(90, 99, 1, players);//descend
   printf("\n");
   drawBoard(81, toLeft);
   printf("\n");
   drawSnakeLadder(80, 89, 0, slarr);//ascend
   printf("\n");
   drawPlayer(80, 89, 0, players);//ascend   
   printf("\n");
   drawBoard(80, toRight);
   printf("\n");
   drawSnakeLadder(70, 79, 1, slarr);//descend
   printf("\n");
   drawPlayer(70, 79, 1, players);//descend   
   printf("\n");
   drawBoard(61, toLeft);
   printf("\n");
   drawSnakeLadder(60, 69, 0, slarr);//ascend
   printf("\n");
   drawPlayer(60, 69, 0, players);//ascend   
   printf("\n");
   drawBoard(60, toRight);
   printf("\n");
   drawSnakeLadder(50, 59, 1, slarr);//descend
   printf("\n");
   drawPlayer(50, 59, 1, players);//descend   
   printf("\n");
   drawBoard(41, toLeft);
   printf("\n");
   drawSnakeLadder(40, 49, 0, slarr);//ascend
   printf("\n");
   drawPlayer(40, 49, 0, players);//ascend   
   printf("\n");
   drawBoard(40, toRight);
   printf("\n");
   drawSnakeLadder(30, 39, 1, slarr);//descend
   printf("\n");
   drawPlayer(30, 39, 1, players);//descend   
   printf("\n");
   drawBoard(21, toLeft);
   printf("\n");
   drawSnakeLadder(20, 29, 0, slarr);//ascend
   printf("\n");
   drawPlayer(20, 29, 0, players);//ascend
   printf("\n");
   drawBoard(20, toRight);
   printf("\n");
   drawSnakeLadder(10, 19, 1, slarr);//descend
   printf("\n");
   drawPlayer(10, 19, 1, players);//descend
   printf("\n");
   drawBoard(1, toLeft);
   printf("\n");
   drawSnakeLadder(0, 9, 0, slarr);//ascend
   printf("\n");
   drawPlayer(0, 9, 0, players);//ascend
   printf("\n");
   drawBoard(10, border);
   printf("\n");
}//drawGameBoard() end

//Check if position falls in snake or ladder position. Then update accordingly
int checkSL(int pos, Snake snk, Ladder ldr){
     if(pos == snk.Xstart){
          pos = snk.Xend;
     }else if(pos == snk.Ystart) {
          pos = snk.Yend;
     }else if(pos == snk.Zstart) {
          pos = snk.Zend;
     }else if(pos == ldr.Lstart) {
          pos = ldr.Lend;
     }else if(pos == ldr.Mstart) {
          pos = ldr.Mend;
     }else if(pos == ldr.Nstart) {
          pos = ldr.Nend;
     }else {
          //Do nothing;
     }
     return pos;
}//checkSL() end

//Create the array for players position
void setPlayerPosition(char (*pArr)[4], Player *pstruct, int gamer, int pos){
   int ctr = 0;
   int oldpost = 0;
   
   switch(gamer){
      case 0:  // Set the new position of player A
               oldpost = pstruct->A;                    //Get the old position
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + oldpost) + ctr) == 'A'){
                     *(*(pArr + oldpost) + ctr) = ' ';  //Clear the old position in array        
                  }
               }
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + pos) + ctr) == ' '){
                     *(*(pArr + pos) + ctr) = 'A';      //Transfer in the new position
                     pstruct->A = pos;                  //Update the structure
                     break;
                  }
               }         
               break;
      case 1: //Set the new position of player B
               oldpost = pstruct->B;                    //Get the old position
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + oldpost) + ctr) == 'B'){
                     *(*(pArr + oldpost) + ctr) = ' ';  //Clear the old position in array 
                  }
               }
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + pos) + ctr) == ' '){
                     *(*(pArr + pos) + ctr) = 'B';      //Transfer in the new position
                     pstruct->B = pos;                  //Update the structure 
                     break;
                  }
               }
               break;
      case 2: //Set the new position of player C
               oldpost = pstruct->C;                    //Get the old position
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + oldpost) + ctr) == 'C'){
                     *(*(pArr + oldpost) + ctr) = ' ';  //Clear the old position in array
                  }
               }
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + pos) + ctr) == ' '){
                     *(*(pArr + pos) + ctr) = 'C';      //Transfer in the new position        
                     pstruct->C = pos;                  //Update the structure
                     break;
                  }
               }                      
               break;
      case 3: //Set the new position of player D
               oldpost = pstruct->D;                    //Get the old position
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + oldpost) + ctr) == 'D'){
                     *(*(pArr + oldpost) + ctr) = ' ';  //Clear the old position in array        
                  }
               }
               for(ctr = 0; ctr < 4; ctr++){
                  if(*(*(pArr + pos) + ctr) == ' '){                              
                     *(*(pArr + pos) + ctr) = 'D';      //Transfer in the new position
                     pstruct->D = pos;                  //Update the structure
                     break;
                  }
               }
               break;
      default:
               printf("Error: Player not in the current game \n");
               break;
   }//switch end
}//setPlayerPosition() end

void drawStatus(Player gamers, Snake *s, Ladder *l){
   printf("***** Current Position *****\n");
   printf("Player A: %d", gamers.A);
   printf("   Snake Xstart: %d", s->Xstart);
   printf("   Ladder Lstart: %d\n", l->Lstart);
   printf("Player B: %d", gamers.B);
   printf("   Snake Ystart: %d", s->Ystart);
   printf("   Ladder Mstart: %d\n", l->Mstart);
   printf("Player C: %d", gamers.C);
   printf("   Snake Zstart: %d", s->Zstart);
   printf("   Ladder Nstart: %d\n", l->Nstart);
   printf("Player D: %d\n", gamers.D);
}//drawStatus() end

void printTitle(){
   printf("\n\n");
   printf("|--------------------------------------|\n");
   printf("|---------- SNAKES AND LADDERS --------|\n");
   printf("|                                      |\n");
   printf("| Created by: Marese Casia 06/14/2021  |\n");
   printf("|                                      |\n");
   printf("| This is a 4 player game (A,B,C,D)    |\n");
   printf("|--------------------------------------|\n");
}//printTitle() end

//This is the main program of the snakes and ladders game
//Four players 'A', 'B', 'C', 'D' can play this game
int main(){
   int a, b, c, d;
   int A, B, C, D;                  
   int posA, posB, posC, posD;      //Players
   int dice;
   int player, win, ctr;
   char slarr[100][4];              //Snake and Ladder position array
   char playerarr[100][4];          //Player position position array
   char *sl;                        //Pointer to the Snake and Ladder array
   char ch;
   
   Player playerpos = {0, 0, 0, 0}; //Initialize players' positions structure
   Snake  snake = {0, 0, 0, 0};     //Initialize snakes' positions structure
   Ladder ladder = {0, 0, 0, 0};    //Initialize ladders' positions structure

   player = 0;
   win = 0;
   A = 0;
   B = 1;
   C = 2;
   D = 3;

   //Initialize with blank space the Snakes and Ladders position array.
   //This method will be called only at the start of the game.
   memset(slarr, ' ', sizeof slarr);
   
   //Initialize with blank space the players position array.
   //This method will be called only at the start of the gaem
   memset(playerarr, ' ', sizeof playerarr);

   //Generate the Snakes and Ladder position, store in array and structure   
   createSnakeLadder(slarr, &snake, &ladder);
      
   //Draw the board at the start of the game
   printTitle();
   drawGameBoard(slarr, playerarr);    
   drawStatus(playerpos, &snake, &ladder);
   
    while(win == 0){
        if(player == 0){                                        //Player A
            printf("\nPlayer A's turn.\n");
            printf("Player A, press <Enter> to roll.");
            ch = fgetc(stdin);                                  //Get the pressed key.
            while(ch != 0x0A){
               ch = fgetc(stdin);
            }
            a = 0;
            a = dieroll();                                      //Roll the dice.
            
            //Check new position if at snake or ladder. Update position accordingly.
            posA=0;
            posA = checkSL( playerpos.A + a, snake, ladder);   
            setPlayerPosition(playerarr, &playerpos, A, posA);
            
            //Re-draw the board
            printTitle();
            drawGameBoard(slarr, playerarr);
            printf("\n Player A rolls a %d\n\n", a);
            drawStatus(playerpos, &snake, &ladder);
        }
        else if(player == 1){                                   //Player B
            printf("\nPlayer B's turn.\n");
            printf("Player B, press <Enter> to roll.");
            ch = fgetc(stdin);                                  //Get the pressed key.
            while(ch != 0x0A){
               ch = fgetc(stdin);
            }
            b=0;
            b = dieroll();                                      //Roll the dice.
            
            //Check new position if at snake or ladder. Update position accordingly.
            posB=0;
            posB = checkSL( playerpos.B + b, snake, ladder);   
            setPlayerPosition(playerarr, &playerpos, B, posB);

            //Re-draw the board
            printTitle();
            drawGameBoard(slarr, playerarr);
            printf("\n Player B rolls a %d\n\n", b);
            drawStatus(playerpos, &snake, &ladder);
        }
        else if(player == 2){                                   //Player C
            printf("\nPlayer C's turn.\n");
            printf("Player C, press <Enter> to roll.");
            ch = fgetc(stdin);                                  //Get the pressed key
            while(ch != 0x0A){
               ch = fgetc(stdin);
            }
            c=0;
            c = dieroll();                                      //Roll the dice.
  
              //Check new position if at snake or ladder. Update position accordingly.
            posC=0;
            posC = checkSL( playerpos.C + c, snake, ladder);   
            setPlayerPosition(playerarr, &playerpos, C, posC);
  
            //Re-draw the board
            printTitle();
            drawGameBoard(slarr, playerarr);
            printf("\n Player C rolls a %d\n\n", c);
            drawStatus(playerpos, &snake, &ladder);
        }
        else{                                                   //Player D
            printf("\nPlayer D's turn.\n");
            printf("Player D, press <Enter> to roll.");
            ch = fgetc(stdin);                                  //Get the pressed key
            while(ch != 0x0A){
               ch = fgetc(stdin);
            }
            d=0;
            d = dieroll();                                      //Roll the dice

            //Check new position if at snake or ladder. Update position accordingly.
            posD=0;
            posD = checkSL( playerpos.D + d, snake, ladder);   
            setPlayerPosition(playerarr, &playerpos, D, posD);
  
            //Re-draw the board
            printTitle();
            drawGameBoard(slarr, playerarr);
            printf("\n Player D rolls a %d\n\n", d);
            drawStatus(playerpos, &snake, &ladder);
        }//if-else end

        //Change player turn.
        if(player == 3){
            player = 0;
        }
        else{
           player++;
        }//if-else end
        
        //Player that reaches 100 is the winner. Game ends. 
        if(playerpos.A > 99){
           win = 1;
           printf( "\nCONGRATULATIONS Player A! You're the WINNER! \n\n");
        } else if(playerpos.B > 99){
           win = 1;
           printf( "\nCONGRATULATIONS Player B! You're the WINNER! \n\n");        
        } else if(playerpos.C > 99){
           win = 1;
           printf( "\nCONGRATULATIONS Player C! You're the WINNER! \n\n");                
        } else if(playerpos.D > 99){
           win = 1;
           printf( "\nCONGRATULATIONS Player D! You're the WINNER! \n\n");                        
        } else {
           //continue with the game...
        }//if-else end
    }//while end

    return 0;
}



