/*Simple hangman used to practice C
 * maximum amount of trys is 10
 * predefined words in a list
 * could be expanded in the future 
 * to practice dynamic allocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randWord();
void getWord(char listWords[6][16], int word, char *ptrSolution);
void print(char *ptrSolution); //used to debug
int isInWord(char userGuess, char *ptrSolution);
void initBoard(char *ptrSolution, int *boardSize, char *currentBoard);
void updateBoard(char *ptrSolution, char *userGuess, char *currentBoard);
void printBoard(char *currentBoard, int boardSize);
int winGame(char *ptrSolution, char *currentBoard);

int main(void){
   
   char guessWords[6][16] = {"knight", "hornet", "defender", "dimitri", "edelgard", "claude"};
   char ptrSolution[10], currentBoard[10];
   char userGuess;
   int trys, boardSize;
   trys = 10;
   boardSize = 0;

   getWord(guessWords, randWord(), ptrSolution);   
   print(ptrSolution); //used to debug
   initBoard(ptrSolution, &boardSize, currentBoard);

   //If havent won the game in equal or less than 10 trys
   while( ((winGame(ptrSolution, currentBoard) == 0)) && (trys > 0)){
      printf("%s", "Guess a letter: ");
      userGuess = getchar();
      while(getchar() != '\n');//flush the buffer to read just one char
      printf("%c", '\n');     
      if(isInWord(userGuess, ptrSolution) == 0){
         trys--;
         printBoard(currentBoard, boardSize);
         printf("%s\n", "Incorrect guess");
      }
      else{
         updateBoard(ptrSolution, &userGuess, currentBoard);
         printBoard(currentBoard, boardSize);
         printf("%s\n", "Correct guess");
      }
   }

   (trys > 0) ? printf("%s\n", "You won!") : printf("%s\n", "You lost :(");
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

// used to debug
void print(char *ptrSolution){
   int i;
   for(i = 0; i < 10; i++){
      printf("%c", ptrSolution[i]);
   }
   printf("%c",'\n');  
}

//get the user's char and compare to each letter in the solution
//if 0 not in word if 1 then it is in the word
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
   printf("%c", '\n');
}

int winGame(char *ptrSolution, char *currentBoard){
   int solutionSize, counter, i;
   solutionSize = 0;
   counter = 0;
   i = 0;

   while(ptrSolution[i] != '\0'){
      solutionSize++;
      if(ptrSolution[i] == currentBoard[i]){
         counter++;
      }
      i++;
   }
   return (solutionSize == counter) ? solutionSize : 0;
}
