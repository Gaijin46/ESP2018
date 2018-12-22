//-----------------------------------------------------------------------------
// ass3.c
//
// This program encrypts plain text. It it cycles each letter of the input
// through the english alphabet, using the modulo of 256 divided 
// by the input strings' length.
// 
// 
// Group: Group 02, study assistant Martin Haubenwallner
//
// Authors: Philipp Bardakji 11701628
//          Kenan Mujic 11771967
//-----------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Card_
{
  char color_;
  char value_;
}Card;

typedef enum _CardValue_
{
  A = 1,
  J = 11,
  Q = 12,
  K = 13
} CardValue;

int main(int argc, char* argv[])
{
  FILE *file;
  char config[52][5];
  char cards[26][4];
  int index;
  int read;
  
  
  if(argc != 2)
  {
    printf("[ERR] Usage: ./ass3 [file-name]\n");
    return 0;
  }
  
  file = fopen(argv[1], "r");
  //fread(&cardType, sizeof(struct _Card_), 1, file);
  
  if(file == NULL)
  {
	printf("[ERR] could not read file!\n");
    return 1;	
  }
  for(index = 0; index < 52; index++)
  {
    read = fscanf(file, "%s[]", &config[index]);
  }

  if(read != 1)
    printf("[ERR] Invalid file!\n");
  else
  {
    for(index = 0; index < 26; index++)
    {
      struct Card(index);
      Card.color(index) = config[(index*2)][0];
	  Card.value(index) = config[((index*2)+1)];
	}
    //for(index = 0; index < 26; index++)
    //{	  
      //cards[index][0] = config[(index*2)][0];
	  //cards[index][1] = 0;
      //strcat(cards[index], config[((index*2)+1)]);
    //}
  
    //for(index = 0; index < 26; index++)
    //{
      //printf("%s\n", cards[index]);
    //}
  }
  
  fclose(file);
}