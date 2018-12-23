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
#include<malloc.h>

struct _DrawStack_ {
  char* card;
  struct _DrawStack_ *next;
};
struct _DrawStack_*head_0;

struct _Stack1_ {
  char* card;
  struct _Stack1_ *prev;
  struct _Stack1_ *next;
};
struct _Stack1_*head_1;

void printlist() {
  struct _DrawStack_*node_0 = head_0;
  printf("List is : \n");
  
  while(node_0 != NULL)
  {
    printf(" %s \n",node_0 -> card);
    node_0 = node_0 -> next;
  }
 printf("\n");
}

void copyToDrawStack(char array[][4])
{
  struct _DrawStack_*node_0 = malloc(sizeof(struct _DrawStack_));
  node_0 -> card = array[0];
  node_0 -> next = NULL;
  head_0 = node_0;
  int i;
  for(i = 1; i < 26; i++)
  {
	struct _DrawStack_*node_1 = malloc(sizeof(struct _DrawStack_));
	node_0 -> next = node_1;
	node_1 -> card = array[i];
    node_1 -> next = NULL;
	node_0 = node_1;
  }

  printlist();
}

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
    read = fscanf(file, "%s", &config[index]);
  }
  
  fclose(file);
  
  if(read != 1)
    printf("[ERR] Invalid file!\n");
  else
  {	
    for(index = 0; index < 26; index++)
    {	  
      cards[index][0] = config[(index*2)][0];
	  cards[index][1] = 0;
      strcat(cards[index], config[((index*2)+1)]);
    }
	copyToDrawStack(cards);
  }
  

  
}