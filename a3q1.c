/**************************************************************
*                                                              *
* Name: A3Q1.c                                                 *
* Purpose:                                                     *
* This program asks the user to input a 10 digit ISBN number.  *
* It will see if it's valid by making sure the weighted        *
* sum of the 10 digits is evenly divisible by 11 .             *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2016-05-05: Sabaa Shahid - created			       		   *
*                                                              *
\**************************************************************/


#include <stdio.h>
#include <string.h> // needed to use strlen 
#include <stdlib.h> // needed to use toupper 

#define ISBN_LENGTH 10

int valid_isbn(char *s); //function prototype for valid_isbn


int main(int argc, char **argv)
{
  char input[100];
  int isValid = -1;
  while(isValid != 0)
  {
    printf("Enter an ISBN to validate: ");
    scanf("%s", input);
    isValid = valid_isbn(input);
  }
}

/**************************************************************
*                                                              *
* Name       : valid_isbn                                        *
* Description:                                                 *
* This function validates input and tests if the ISBN is valid *
* by calculating its weighted sum and seeing if it's divisible *
* by 11.     						       *
*                                                              *                               
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2016-05-10: Sabaa Shahid - created                           *
*                                                              *
\**************************************************************/

int valid_isbn(char *s)
{

//validates input to ensure ISBN is correct length
  if (strlen(s) < ISBN_LENGTH)
  {
    printf("ISBN must be at least 10 characters\n"); 
    return -1;
  }


  int sum=0;
  int i;
  int k=10;
  int q=0;
  for(i=0; i<strlen(s); i++)
  {
    if (s[i] != '-')
    {
      if (s[i] < '0' || s[i] > '9')
      {
        if (toupper(s[i]) != 'X' || i != strlen(s)-1)
        {
          printf("Invalid character in ISBN\n");
          return -1;
        }
        else
        {
          q = 10;
        }
      }
      else
      {
        q = s[i] - '0';
      }
      sum += q*k;
      k--;
    }
  }

// checks if isbn is divisible by 11 and prints result
  if (sum % 11 == 0)
  {
    printf("ISBN %s is VALID\n", s);
    return 0;
  }
  else
  {
    printf("ISBN %s is NOT VALID\n", s);
    return -1;
  }
}
