/*
 ============================================================================
 Name        : pedagogical.c
 Author      : carcmg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"

#define TRUE 1
#define FALSE 1

//struct to be used as a linked list to hold the name letters as they appear.  not optimal implmentation
//but then again this file pedagogical :-)
typedef struct Letter {
	char cLetter;
	struct Letter *next;
} Letter_t;

void showEyeC(int i);

int main (int argc, char * argv[])
{
    FILE *fp=0;
    FILE *fp2=0;
    int i=0;
    char myChar=EOF;
    Letter_t * cC = NULL;
    cC = malloc(sizeof(Letter_t));

    if (argc< 3)
    {
       printf("l2w - usage : infilename outfilename\n");
       return FALSE;
    }
    else if (cC == NULL)
    {
        printf("l2w - failed to allocate Letter_t\n");
        return FALSE;

    }


    printf("opening file %s\n", argv[1]);
    fp = fopen(argv[1],"r");
    printf("opening file %s\n", argv[2]);
    fp2 = fopen(argv[2],"a+");
    if (fp && fp2)
    {
       printf("success opening files %s and %s\n", argv[1],argv[2]);
       do
       {
          myChar = fgetc(fp);
          showEyeC(i++);
          if (myChar!=EOF)
          {
             fputc(myChar,fp2);
             if (myChar=='\n')
             {
//                fputs("\r\n",fp2);
                fputc('\r',fp2);
             }
      		if (myChar=='c' ||
        		myChar=='a' ||
      		    myChar=='r' ||
      		    myChar=='c' ||
      		    myChar=='m' ||
      		    myChar=='g' )
      		{
      			//add to linked list;
      		}
          }
       } while (myChar!=EOF);

       fclose(fp);
       fclose(fp2);
    }
    else if ( !fp )
    {
       printf("failed to open file %s\n", argv[1]);
       return FALSE;
    }
    else if ( !fp2 )
    {
       printf("failed to open file %s\n", argv[2]);
       return FALSE;
    }

    free(cC);
    printf("\rdone \n");
    return TRUE;

}

void showEyeC(int i)
{
        if (i%2)
        {
            printf("%d/ ",i);
        }
        else
        {
            printf("\\%d",i);
        }
        fflush(stdout);    //needed in ubuntu, otherwise stdout is not updated on the printf
//        sleep(1);
        printf("\r      \r"); //clear the line
}

