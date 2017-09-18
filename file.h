#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * fileoperation(char *filepath)
{
   FILE * fp;
   fp = fopen(filepath,"r");
   char *ptr=NULL;
   char c='\0';
   ptr = (char*)malloc(sizeof(char));
   int i = 0, j = 1;
   while (c != EOF)
   {
         c = fgetc(fp);
         if(c >= 65 && c <= 90)
         {
             c = c+32;
             ptr[i++] = c;
             ptr = realloc(ptr, i+1);
         }
         else if(c == 32 ||( c >= 97 && c<= 122) )
         {
             ptr[i++] = c;
             ptr = realloc(ptr,i+1);
         }
   }
   ptr[i] = '\0';
   fclose(fp);
   return ptr;
}
