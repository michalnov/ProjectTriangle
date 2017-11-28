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
  char key[38][2], swap, swap2;
  i = 0;
  while ((fscanf(fr_key, "%c%c%c%c", &key[i][0], &swap, &key[i][1], &swap2) ) != EOF) {
    i++;
    if (i > 37) {
      break;
    }
  }
  i--;
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
      if (isalnum(swap)) {
        if (islower(swap)) {
          toupper(swap);
          upper = 1;
        }
        for (j = 0; j < i; j++) {
          if (swap == key[j][1]) {
            swap = key[j][0];
            break;
          }
        }
        if (upper == 1) {
          tolower(swap);
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
