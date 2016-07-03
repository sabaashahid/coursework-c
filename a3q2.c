/**************************************************************
*                                                              *
* Name: A3Q2.c                                                 *
* Purpose:                                                     *
* This program will create scrambled words by circularly       *
* rotating the middle characters of each word by 1 character.  *	 
* It then places the scrambled words, 1 per line in an output  *   
* file.                                                        *
*        						       *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2016-05-12: Sabaa Shahid - created			       *
*                                                              *
\**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /* needed to use exit() */

char* scramble(char* str); //function prototype

int main()
{
	char word[80]; 	    //word is less than 80 characters long
	FILE *fpin, *fpout; //declare two FILE pointers
	int i, count = 0;

	//open input file
	fpin = fopen ("dict.txt", "r");
	//error message if file not found
	if (fpin == NULL)
	{
            printf("Error- input file not found.\n");
	}
    	else
    	{
		/* open the output file */
		fpout = fopen("scramble.txt", "w");
		fscanf (fpin,"%d",&count);
		for (i=0; i<count; i++)
		{
			fscanf (fpin,"%s",word);
			fprintf (fpout,"%s\n", scramble(word));
		}
	}
	return 0;
}

/**************************************************************
*                                                              *
* Name       : scramble                                        *
* Description:                                                 *
* This function scrambles the middle letters but leaves the    *
* and last characters of the word in the same place	       	   *
*       						       						   *
*                                                              *                               
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2016-05-11: Sabaa Shahid - created                           *
*                                                              *
\**************************************************************/

char* scramble(char* str)
{
	int len = strlen(str);
	char *newStr = (char*)malloc(sizeof(char) * len);
	int i, index=0;
	newStr[index++] = str[0]; //copy first character
	for (i=2; i < len-1; i ++)
	{
		newStr[index++] = str[i];
	}
	newStr[index++] = str [1];
	newStr[index++] = str [len-1];	//copy last character
	newStr[index] = '\0';
	return newStr;
}
