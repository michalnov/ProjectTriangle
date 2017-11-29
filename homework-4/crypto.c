#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  FILE *fr_key, *fr_data, *fw_output;
  char opentext[50], outfile[50], keyfile[50];
  
  printf("Enter key file name: ");
  scanf("%s", keyfile);
  fr_key = fopen(keyfile , "r");
  int i = 0, j = 0;
  if(fr_key == NULL)
	{
		printf("File error during opening KEY file");
		return 1;
	}
  char key[120], swap, swap2;
  i = 0;
  while ((swap = fgetc(fr_key)) != EOF) {
    if (isalpha(swap) || isdigit(swap)) {
      key[i] = swap;
      i++;
    }
  }
  i--;
  fclose(fr_key);
  
  printf("Enter input file name: ");
  scanf("%s", opentext);
  printf("Enter output file name: ");
  scanf("%s", outfile);  
  fr_data = fopen(opentext , "r");
  fw_output = fopen(outfile , "w");

  if (fr_data == NULL)
	{
		printf("File error during opening DATA file");
    fclose(fw_output);
		return 1;
  }
  else if (fw_output == NULL) {
    printf("File error during opening OUTPUT file");
    fclose(fr_data);
		return 1;
  }

	else
	{
    while ((swap = fgetc(fr_data)) != EOF) {
      if (isalnum(swap)) {
        if (islower(swap)) {
          for (j = 0; j < i; j+=2) {
            if (swap == tolower(key[j])) {
              swap = tolower(key[j+1]);
              break;
            }
          }
        }
        else
        {
          for (j = 0; j < i; j+=2) {
            if (swap == key[j]) {
              swap = key[j+1];
              break;
            }
          }
        }
      }
      else{}
      fputc(swap, fw_output);
    }
  }
  fclose(fw_output);
  fclose(fr_data);
  printf("\nDONE\n");
  return 0;
}
