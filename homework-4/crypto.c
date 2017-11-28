#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  FILE *fr_key, *fr_data, *fw_output;
  fr_key = fopen("cypher-key.data", "r");
  int i = 0, j = 0, upper = 0;
  if(fr_key == NULL)
	{
		printf("File error during opening KEY file");
		return 1;
	}
  char key[38][2], swap;
  i = 0;
  while ((fscanf(fr_key, "%c%c", &key[i][0], &key[i][1]) ) != EOF) {
    i++;
    if (i > 37) {
      break;
    }
  }
  fclose(fr_key);
  fr_data = fopen("tocrypt.txt", "r");
  fw_output = fopen("cypher-text.data", "w");
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
      upper = 0;
      j = 0;
      if (isalnum(swap) == 0) {
        if (islower(swap) == 0) {
          toupper(swap);
          upper = 1;
        }
        for (j = 0; j < i; j++) {
          if (swap == key[i][1]) {
            swap = key[i][0];
          }
          else {}
        }
        if (upper == 1) {
          tolower(swap);
        }
      }
      else
      {}
      fputc(swap, fw_output);
    }
  }
  fclose(fw_output);
  fclose(fr_data);
  printf("DONE");
  return 0;
}
