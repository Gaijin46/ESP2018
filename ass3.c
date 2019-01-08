//-----------------------------------------------------------------------------
// ass3.c
//
// This program represents the classic game 'Solitaire'.
// The order of the card is given by a config file. 
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

// Structure for linked lists, represents the stacks.
struct _List_ {
  char* card_;
  struct _List_ * next_;
  struct _List_ * prev_;
};
struct _List_ * draw_;
struct _List_ * stack_1_;
struct _List_ * stack_2_;
struct _List_ * stack_3_;
struct _List_ * stack_4_;
struct _List_ * deposit_1_;
struct _List_ * deposit_2_;

//------------------------------------------------------------------------------
///
/// Prints out the game table.
/// Is refreshed after every turn.
///
///
/// @param i counter
///
/// @return void function
//
  printf("List is : \n");
  
  while(draw_ != NULL)
  {
    printf(" %s \n",draw_ -> card_);
    draw_ = draw_ -> next_;
  }
 printf("\n");
}
void table()
{
  printf("0   | 1   | 2   | 3   | 4   | DEP | DEP\n");
  printf("---------------------------------------\n");
  int i = 0;
  //for(i = 16; i > 0; i--);
  while( i < 16)
  {
	if(draw_ != NULL)
	{
      if(draw_ -> prev_ == NULL)
	  {
	    if(strcmp(draw_ -> card_, "B10") && strcmp(draw_ -> card_, "R10"))
          printf("%s  |", draw_ -> card_);
        else
	      printf("%s |", draw_ -> card_);
	  }
	  else
	    printf("X   |");
  
      draw_ = draw_ -> next_;
    }
	else
	  printf("    |");
	
	if(stack_1_ != NULL)
	{
	  if(strcmp(stack_1_ -> card_, "B10") && strcmp(stack_1_ -> card_, "R10"))
        printf(" %s  |", stack_1_ -> card_);
      else
	    printf(" %s |", stack_1_ -> card_);
	  stack_1_ = stack_1_ -> next_;
	}
	else
	  printf("     |");
  
    if(stack_2_ != NULL)
	{
	  if(strcmp(stack_2_ -> card_, "B10") && strcmp(stack_2_ -> card_, "R10"))
        printf(" %s  |", stack_2_ -> card_);
      else
	    printf(" %s |", stack_2_ -> card_);
	  stack_2_ = stack_2_ -> next_;
	}
	else
	  printf("     |");
	
	if(stack_3_ != NULL)
	{
	  if(strcmp(stack_3_ -> card_, "B10") && strcmp(stack_3_ -> card_, "R10"))
        printf(" %s  |", stack_3_ -> card_);
      else
	    printf(" %s |", stack_3_ -> card_);
	  stack_3_ = stack_3_ -> next_;
	}
	else
	  printf("     |");
  
    if(stack_4_ != NULL)
	{
	  if(strcmp(stack_4_ -> card_, "B10") && strcmp(stack_4_ -> card_, "R10"))
        printf(" %s  |", stack_4_ -> card_);
      else
	    printf(" %s |", stack_4_ -> card_);
	  stack_4_ = stack_4_ -> next_;
	}
	else
	  printf("     |");
  
    if(deposit_1_ != NULL)
	{
	  if(strcmp(deposit_1_ -> card_, "B10") && strcmp(deposit_1_ -> card_, "R10"))
        printf(" %s  |", deposit_1_ -> card_);
      else
	    printf(" %s |", deposit_1_ -> card_);
	  deposit_1_ = deposit_1_ -> next_;
	}
	else
	  printf("     |");
  
    if(deposit_2_ != NULL)
	{
	  if(strcmp(deposit_2_ -> card_, "B10") && strcmp(deposit_2_ -> card_, "R10"))
        printf(" %s  \n", deposit_2_ -> card_);
      else
	    printf(" %s \n", deposit_2_ -> card_);
	  deposit_2_ = deposit_2_ -> next_;
	}
	else
	  printf("     \n");
	i++;
  }
}

//------------------------------------------------------------------------------
///
/// Distributes the cards onto the stacks at 
/// the beginning of the game.
///
///
/// @param card_x_ pointer used to create nodes inside the linked list.
/// @param i counter
///
/// @return void function
//
void distribute(char array[][4])
{
  struct _List_ * card_1_ = malloc(sizeof(struct _List_));
  struct _List_ * card_2_ = malloc(sizeof(struct _List_));
  struct _List_ * card_3_ = malloc(sizeof(struct _List_));
  struct _List_ * card_4_ = malloc(sizeof(struct _List_));
  struct _List_ * card_5_ = malloc(sizeof(struct _List_));
  struct _List_ * card_6_ = malloc(sizeof(struct _List_));
  struct _List_ * card_7_ = malloc(sizeof(struct _List_));
  struct _List_ * card_8_ = malloc(sizeof(struct _List_));
  struct _List_ * card_9_ = malloc(sizeof(struct _List_));
  struct _List_ * card_10_ = malloc(sizeof(struct _List_));
  struct _List_ * card_11_ = malloc(sizeof(struct _List_));
  struct _List_ * card_12_ = malloc(sizeof(struct _List_));
  struct _List_ * card_13_ = malloc(sizeof(struct _List_));
  struct _List_ * card_14_ = malloc(sizeof(struct _List_));
  struct _List_ * card_15_ = malloc(sizeof(struct _List_));
  struct _List_ * card_16_ = malloc(sizeof(struct _List_));
  struct _List_ * card_17_ = malloc(sizeof(struct _List_));
  struct _List_ * card_18_ = malloc(sizeof(struct _List_));
  struct _List_ * card_19_ = malloc(sizeof(struct _List_));
  struct _List_ * card_20_ = malloc(sizeof(struct _List_));
  struct _List_ * card_21_ = malloc(sizeof(struct _List_));
  struct _List_ * card_22_ = malloc(sizeof(struct _List_));
  struct _List_ * card_23_ = malloc(sizeof(struct _List_));
  struct _List_ * card_24_ = malloc(sizeof(struct _List_));
  struct _List_ * card_25_ = malloc(sizeof(struct _List_));
  struct _List_ * card_26_ = malloc(sizeof(struct _List_));
  
  int i = 0;
  
  card_1_ -> card_ = array[i];
  card_1_ -> prev_ = stack_1_;
  card_1_ -> next_ = NULL;
  i++;
  
  card_2_ -> card_ = array[i];
  card_2_ -> prev_ = stack_2_;
  card_2_ -> next_ = card_5_;
  i++;
  
  card_3_ -> card_ = array[i];
  card_3_ -> next_ = card_6_;
  card_3_ -> prev_ = stack_3_;
  i++;
  
  card_4_ -> card_ = array[i];
  card_4_ -> next_ = card_7_;
  card_4_ -> prev_ = stack_4_;
  i++;
  
  card_5_ -> card_ = array[i];
  card_5_ -> next_ = NULL;
  card_5_ -> prev_ = card_2_;
  i++;
  
  card_6_ -> card_ = array[i];
  card_6_ -> next_ = card_8_;
  card_6_ -> prev_ = card_3_;
  i++;
  
  card_7_ -> card_ = array[i];
  card_7_ -> next_ = card_9_;
  card_7_ -> prev_ = card_4_;
  i++;
  
  card_8_ -> card_ = array[i];
  card_8_ -> next_ = NULL;
  card_8_ -> prev_ = card_6_;
  i++;
  
  card_9_ -> card_ = array[i];
  card_9_ -> next_ = card_10_;
  card_9_ -> prev_ = card_7_;
  i++;
  
  card_10_ -> card_ = array[i];
  card_10_ -> next_ = NULL;
  card_10_ -> prev_ = card_9_;
  i++;
  
  card_11_ -> card_ = array[i];
  card_11_ -> next_ = card_12_;
  card_11_ -> prev_ = draw_;
  i++;
  
  card_12_ -> card_ = array[i];
  card_12_ -> next_ = card_13_;
  card_12_ -> prev_ = card_11_;
  i++;
  
  card_13_ -> card_ = array[i];
  card_13_ -> next_ = card_14_;
  card_13_ -> prev_ = card_12_;
  i++;
  
  card_14_ -> card_ = array[i];
  card_14_ -> next_ = card_15_;
  card_14_ -> prev_ = card_13_;
  i++;
  
  card_15_ -> card_ = array[i];
  card_15_ -> next_ = card_16_;
  card_15_ -> prev_ = card_14_;
  i++;
  
  card_16_ -> card_ = array[i];
  card_16_ -> next_ = card_17_;
  card_16_ -> prev_ = card_15_;
  i++;
  
  card_17_ -> card_ = array[i];
  card_17_ -> next_ = card_18_;
  card_17_ -> prev_ = card_16_;
  i++;
  
  card_18_ -> card_ = array[i];
  card_18_ -> next_ = card_19_;
  card_18_ -> prev_ = card_17_;
  i++;
  
  card_19_ -> card_ = array[i];
  card_19_ -> next_ = card_20_;
  card_19_ -> prev_ = card_18_;
  i++;
  
  card_20_ -> card_ = array[i];
  card_20_ -> next_ = card_21_;
  card_20_ -> prev_ = card_19_;
  i++;
  
  card_21_ -> card_ = array[i];
  card_21_ -> next_ = card_22_;
  card_21_ -> prev_ = card_20_;
  i++;
  
  card_22_ -> card_ = array[i];
  card_22_ -> next_ = card_23_;
  card_22_ -> prev_ = card_21_;
  i++;
  
  card_23_ -> card_ = array[i];
  card_23_ -> next_ = card_24_;
  card_23_ -> prev_ = card_22_;
  i++;
  
  card_24_ -> card_ = array[i];
  card_24_ -> next_ = card_25_;
  card_24_ -> prev_ = card_23_;
  i++;
  
  card_25_ -> card_ = array[i];
  card_25_ -> next_ = card_26_;
  card_25_ -> prev_ = card_24_;
  i++;
  
  card_26_ -> card_ = array[i];
  card_26_ -> next_ = NULL;
  card_26_ -> prev_ = card_25_;
  i++;
  
  draw_ = card_11_;
  stack_1_ = card_1_;
  stack_2_ = card_2_;
  stack_3_ = card_3_;
  stack_4_ = card_4_;
  deposit_1_ = NULL;
  deposit_2_ = NULL;

  table();
  
  free(card_1_);
  free(card_2_);
  free(card_3_);
  free(card_4_);
  free(card_5_);
  free(card_6_);
  free(card_7_);
  free(card_8_);
  free(card_9_);
  free(card_10_);
  free(card_11_);
  free(card_12_);
  free(card_13_);
  free(card_14_);
  free(card_15_);
  free(card_16_);
  free(card_17_);
  free(card_18_);
  free(card_19_);
  free(card_20_);
  free(card_21_);
  free(card_22_);
  free(card_23_);
  free(card_24_);
  free(card_25_);
  free(card_26_);
}

//------------------------------------------------------------------------------
///
/// Moves cards from one stack to the other.
///
///
/// @return void fuction
//
void moveCard(char* move)
{
  // int i = 0;
  // while(i = 0)
  // {
    
  // }
// }
  printf(" %s \n", move);
}

//------------------------------------------------------------------------------
///
/// Reads user input and interprets it.
/// Compares input strings to allowed command strings.
///
/// @param input user input string
/// @param segment1 segmented part of user input
///
/// @return void function
//
void interpretUserInput()
{
  char input[25];
  fgets(input, 25, stdin);
  
  char* segment1 = strtok(input, " ");

  
  if(strcmp(input, "help\n") == 0)
  {	  
    printf("possible command:\n");
    printf("- move <color> <value> to <stacknumber>\n");
    printf("- help\n");
    printf("- exit\n");
	input[0] = 0;
	interpretUserInput();
  }
  else
  {
	if(strcmp(input, "exit\n") == 0)
    {
      return;
	}
	if(strcmp(segment1, "move") == 0)
	{
	  moveCard(segment1);	
	}
    else
    {	
      printf("[INFO] Invalid command!\n");
      interpretUserInput();  
    }
  }
  
  
}

//------------------------------------------------------------------------------
///
/// Main function opens config file, converts card format 
/// and checks for validity.
///
/// @param file file pointer
/// @param config initial array
/// @param cards formatted cards array
/// @param index counter
/// @param read checks for valid file
///
/// @return depends on error
//
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
  
  if(file == NULL)
  {
	printf("[ERR] could not read file!\n");
    return 1;	
  }
  for(index = 0; index < 52; index++)
  {
    read = fscanf(file, "%s", config[index]);
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
  distribute(cards);
  interpretUserInput();
  }
  
}