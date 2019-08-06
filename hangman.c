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

int main(void){
   
   /*array of char pointers*/
   //char *guessWords[] = {}
   char guessWords[6][16] = {"knight", "hornet", "defender", "dimitri", "edelgard", "claude"};
   char ptrSolution[10];
   int tries;
   tries = 10;
   char userGuess;
//   userGuess = '0';
   //randomly chose a word from the list to set as the answer
   //get a char from the user
   //while there are still tries compare each space with the letter guessed to the answer
   getWord(guessWords, randWord(), ptrSolution);   
   print(ptrSolution);
   while((tries > 0) && ((userGuess = getchar()) != '\n')){
      //userGuess = getchar();
      fflush(stdin);
      if(isInWord(userGuess, ptrSolution) > 0){
         printf("%s", "yes");
      }

      else{
         printf("%s", "no");
      }
      
      //printf("%s", (isInWord(userGuess, ptrSolution) > 0) ? "true" : "false");
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
   printf("\n");  
}

//get the user's char and compare to each letter in the solution
//if 0 not it word if 1 then it is in the word
int isInWord(char userGuess, char *ptrSolution){
   int i, count;
   //char userChar;
   count = 0;
   //userChar = getchar();
   for(i = 0; i < 10; i++){
      if(userGuess == ptrSolution[i]){
         count++;
      }
   }
   return count;
}




