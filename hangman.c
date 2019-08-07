/*simple hangman maximum of 10 tries before the person loses
 * start with input from an array with fixed size words <= 8 chars each
 * will change this to pointers to vary word size
 *store: in an array of strings
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randWord();
void getWord(char listWords[6][16], int word, char *ptrSolution);
void print(char *ptrSolution);
int isInWord(char userGuess, char *ptrSolution);
void initBoard(char *ptrSolution, int *boardSize, char *currentBoard);
void updateBoard(char *ptrSolution, char *userGuess, char *currentBoard);
void printBoard(char *currentBoard, int boardSize);
int winGame(char *ptrSolution, char *currentBoard);

int main(void){
   
   /*array of char pointers*/
   //char *guessWords[] = {}
   char guessWords[6][16] = {"knight", "hornet", "defender", "dimitri", "edelgard", "claude"};
   char ptrSolution[10];
   int tries;
   tries = 10;
   char userGuess;
   char currentBoard[10];
   int boardSize;
   boardSize = 0;
   
   getWord(guessWords, randWord(), ptrSolution);   
   print(ptrSolution);
   initBoard(ptrSolution, &boardSize, currentBoard);

   while( !(winGame(ptrSolution, currentBoard) == 0) || (tries > 0) ){ // or won game in less or equal tries to tries
      
      printf("%s", "Guess a letter: ");
      userGuess = getchar();
      getchar();
      printf("%c", userGuess);
           
      if(isInWord(userGuess, ptrSolution) == 0){
         tries--;
         printBoard(currentBoard, boardSize);
         //printf("%s, %c", "printing user guess in if: ", userGuess);
      }
      else{
      //update board
      //printf("%c",userGuess);
      updateBoard(ptrSolution, &userGuess, currentBoard);
      printBoard(currentBoard, boardSize);
      
      //check if won game
      
      }
   }   
   return 0;
}

int randWord(){
   srand(time(NULL)); 
   int value;
   value = rand() % 6;
   return value;
}

void getWord(char listWords[6][16], int word, char *ptrSolution){
   int i;
   for(i = 0; i < 10; i++){
      ptrSolution[i] = listWords[word][i];
   }
}

void print(char *ptrSolution){
   int i;
   for(i = 0; i < 10; i++){
      printf("%c", ptrSolution[i]);
   }
   printf("%c",'\n');  
}

//get the user's char and compare to each letter in the solution
//if 0 not it word if 1 then it is in the word
int isInWord(char userGuess, char *ptrSolution){
   int i, count;
   count = 0;
   for(i = 0; i < 10; i++){
      if(userGuess == ptrSolution[i]){
         count++;
      }
   }
   return count;
}

void initBoard(char *ptrSolution, int *boardSize, char *currentBoard){
   while(*(ptrSolution++) != '\0'){
      printf("%s", "_ ");
      *(currentBoard++) = '_';
      (*boardSize)++;
   }
   printf("%c",'\n');
}

void updateBoard(char *ptrSolution, char *userGuess, char *currentBoard){
   int i;
   for(i = 0; i < 10; i++){
      if(ptrSolution[i] == *userGuess){
         *currentBoard  = *userGuess;
      }
      currentBoard++;
   }
}

void printBoard(char *currentBoard, int boardSize){
   int i;
   for(i = 0; i < boardSize; i++){
      printf("%c ", currentBoard[i]);
   }
}


int winGame(char *ptrSolution, char *currentBoard){
   int solutionSize;
   int counter;
   solutionSize = 0;
   counter = 0;
   while(*(ptrSolution++) != '\n'){
      solutionSize++;
//      currentBoard++;
      if(*ptrSolution == *currentBoard){
         counter++;
      }
      currentBoard++;
   }
   if(solutionSize == counter){
      return solutionSize;
   }
   else{
      return 0;
   }
}
