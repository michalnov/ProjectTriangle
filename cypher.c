#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  FILE *fr, *fw;
  fr = fopen("cypher.txt", "r");
  fw = fopen("decyphered.txt", "w");
  if(fr==NULL)
	{
		printf("File error");
		return 1;
	}
	else
	{
		if(fw==NULL)
		{
			fclose(fr);
			printf("File error");
			return 1;
		}
		else{}
	}
  char c;
  while ((c = fgetc(fr)) != EOF) {
    if (c == '%') {
      c = ' ';
      fputc(c, fw);
    }
    else if (isalpha(c)) {
      c = c -1;
      if (c == '@') {
        c = 'Z';
      }
      else if (c == 96) {
        c = 'z';
      }
      else{
        if (c == 'i') {
          c = 'y';
        }
        else if (c == 'y') {
          c = 'i';
        }
        else if (c == 'I') {
          c = 'I';
        }
        else if (c == 'Y') {
          c = 'Y';
        }
        else{

        }
      }
      fputc(c, fw);
    }
    else
    {
      fputc(c, fw);
    }

  }
  fclose(fw);
  fclose(fr);
  return 0;
}
