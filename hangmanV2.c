#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  FILE *fr;
  fr = fopen("wordlist.txt", "r");
  srand(time(NULL));
  int whatword = 0;
  int i = 0, j = 0, k = 0;
  whatword = rand()%58106+2;
  char c;
  char secret[30], guess[30], unused[60], print[30], swap[30], single, singleup, singledown;
  strcpy(guess, "");
  strcpy(unused, "a b c d e f g h i j k l m n o p q r s t u v w z");

  for (i = 0; i < whatword; i++) {
    do {
    } while(c = getc(fr) != '\n');
  }
  k = 0;
  do {
    c = getc(fr);
    if (c != '\n') {
      secret[k] = c;
    }
    else
    {
      secret[k] = '\0';
    }
    k++;
  } while(c != '\n');
  int won = 0;
  int len = strlen(secret);
  int right = 0, try;
  try = len+2;
  for ( i = 0; i < len; i++)
  {
    print[i] = '_';
    print[i+1] = '\0';
  }
  fclose(fr);
  printf("The secret word is %d characters long.\n", len);
  printf("You have %d attempts\n\n", try);
  do {
    printf("%s\n", print);
    printf("You can use: %s\n", unused);
    printf("%s", "Your guess: ");
    scanf("%s", guess);
    right = 0;
    if (strlen(guess) > 1) {
      if (strcmp(guess,secret) == 0) {
        printf("Yes You won! Secret word is: %s\n", secret);
        won = 1;
        return 0;
      }
      else
      {
        try--;
        printf("Wrong you have %d attempts\n\n", try);
      }
    }
      c = guess[0];
      for (i = 0; i < len; i++) {
        if (c == secret[i]) {
          right++;
          print[i] = c;
        }
        else
        {}
      }
      if (right > 0) {
      }
      else
      {
        try--;
        printf("Wrong you have %d attempts\n\n", try);
      }
    if (strcmp(secret, print) == 0) {
      printf("Yes You won! Secret word is: %s\n", secret);
      won = 1;
      return 0;
    }
    for (i = 0; i < 48; i++) {
      if (c == unused[i]) {
        unused[i] = '-';
      }
      else{}
    }
    if (try == 0) {
      printf("Secret word was: %s\n", secret);
    }
  } while(won == 0 && try > 0);

}
