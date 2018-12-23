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

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ELEMENTS  4

struct node {
    char* card;
    struct node *next;
};
struct node *head;

//void insert(int x) 
//{
    //struct node *temp = malloc(sizeof(struct node));
    //temp->card = x;
    //temp->next = NULL;

    //if (head != NULL)
        //temp->next = head;
    //head = temp;
//}

void copy(char array[][4])                         //copying array elements and create linked list
{
  struct node*temp = malloc(sizeof(struct node));
  temp -> card = array[1];
  temp -> next = NULL;
  head = temp;
  int i;
  
  for(i = 0; i < 26; i++)
  {
    struct node*temp2 = malloc(sizeof(struct node));
    temp -> next= temp2;
    temp2 -> card = array[i];
    temp2 -> next = NULL;
    temp = temp2;
  }  
}

void printlist() {
    struct node *temp = head;
    printf("List is : \n");

    while(temp != NULL)
    {
      printf(" %s \n",temp -> card);
      temp = temp -> next;

    }
    printf("\n");
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
  
    //for(index = 0; index < 26; index++)
    //{
      //printf("%s\n", cards[index]);
    //}
	
	copy(cards);
    printlist();
  }
  

  fclose(file);
}