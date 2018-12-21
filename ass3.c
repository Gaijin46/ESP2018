//-----------------------------------------------------------------------------
// ass3.c
//
// This program encrypts plain text. It it cycles each letter of the input
// through the english alphabet, using the modulo of 256 divided 
// by the input strings' length.
// 
// 
// Group: Group 02, study assistant Martin Ferdinand Haubenwallner
//
// Authors: Philipp Bardakji 11701628
//          Kenan Mujic 11771967
//-----------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  FILE *fp;
  char config[52][5];
  char cards[26][3];
  
  int index;
  int character;
  
  fp = fopen("config.txt", "r");
  if(fp == NULL)
  {
	printf("[ERR] could not read file!");
    return 1;	
  }
  for(index = 0; index < 52; index++)
  {
    fscanf(fp, "%s[]", &config[index]);
  }

 //for(index =0; index < 5; index++)
  //{
	//if(config[index] == 32)
    //{  
      //config[index] = config[(index) + 1];
      //config[index + 1] = "/0";
	//}
  //}

  for(index = 0; index < 26; index++)
  {	  
    cards[index][0] = config[(index*2)][0];
	cards[index][1] = 0;
    strcat(cards[index], config[((index*2)+1)]); 
  }

  for(index = 0; index < 26; index++)
  {
    printf("%s\n", cards[index]);
  }
  
  

  fclose(fp);
}