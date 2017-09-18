# include <stdio.h>
# include <stdlib.h>
#include <errno.h>
# include <string.h>
# include <dirent.h>
# include "special.h"
int file_cmp(char *file_name)     ///////------->>>>>>> //Selecting text files
{
    char *cmpr = (char *) malloc(sizeof(char) * 3);
    cmpr = "txt";
    char *ret;
    int a;
    ret = strstr(file_name,cmpr);
    if(ret == NULL)
    {
        ret="error";
    }
    a=strcmp(ret,cmpr);
    return a;
}
char* fileopen(char* re){                           //Reading files and storing text into
    char* ch1=(char*)malloc(sizeof(char)*1000);               //   character array
    FILE *fptr1;
    fptr1=fopen(re,"r+");
    if(fptr1==NULL)
        perror("no file");
    fscanf(fptr1,"%[^EOF]s",ch1); 
    return ch1;
                
}  

void main(int argc,char *argv[])
{
    DIR *d;
    struct dirent *dir;
    char *re[100];
    d = opendir(argv[1]);          ///------>>>>>  //Giving directory path
    chdir(argv[1]);
    int i=0;
    char** Filen=(char**)malloc(sizeof(char*)*100);
    while ((dir = readdir(d)) != NULL)
    {
        if(strlen(dir->d_name)>2){
            int a = file_cmp(dir->d_name);
                if(a==0)
                {
                    Filen[i]=malloc(strlen(dir->d_name));      //Storing file names into an array
                    strcpy(Filen[i],dir->d_name);
                    i=i+1;
                }   
        }
            
    }
    int len;
    len=i;
    for(int y=0;len<i;y++){
        printf("         ");
        printf("%8s",Filen[y] );
     }
  
    int k=0,r=0;
     float e[i][i];
     for(int t=0;t<i;t++){
        printf("\n%8s",Filen[t] );
         for(int n=0;n<len;n++){
            if(Filen[t]!=Filen[n]){
                char* ch1=(char*)malloc(sizeof(char)*100);
                char* ch2=(char*)malloc(sizeof(char)*100);
                 ch1=fileopen(Filen[t]);                    //file opening and storing data
                 ch2=fileopen(Filen[n]);  
                 char* n1=(char*)malloc(sizeof(char)*100);
                 char* n2=(char*)malloc(sizeof(char)*100);
                 n1=specialcharacter(ch1);
                 n2=specialcharacter(ch2);
                 float w;
                 if(strlen(n1)>strlen(n2)){
                     w=Lcs(n1,n2);
                }
                else{
                     w=Lcs(n2,n1);
                }
                            //caluculating plagarism percentage
                
                 float d=strlen(n1)+strlen(n2);            
                 float y=((2*w)/d)*100;
                 e[t][n]=y;
             }
            else{
                 e[t][n]=0;
            }
            printf("    %f        ",e[t][n] );
        }
        printf("\n");
    }
 }

