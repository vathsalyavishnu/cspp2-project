#include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
#include <errno.h>
struct word {
char str[100];    
int count;        
};
int dot(struct word words[100],struct word words1[100],int nword,int nword1);
float denom(struct word words[100],struct word words1[100],int nword,int nword1);
float result(int s,float b);
int word_freq(char* str, struct word words[]);
int file_cmp(char *file_name)       //------->>>>>>>///Selecting text files
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
char* fileopen(char* re){               //////----------->>>>>>>//opening files
    char* ch1=(char*)malloc(sizeof(char)*1000);
    FILE *fptr1;
    fptr1=fopen(re,"r+");
    if(fptr1==NULL)
        perror("no file");
    fscanf(fptr1,"%[^EOF]s",ch1); 
    return ch1;
                
}

void main(int argc,char *argv[]){
    DIR *d;
    struct dirent *dir;
    char *re[100];
    d = opendir(argv[1]);
    chdir(argv[1]);
    int i=0;
    char** Filen=(char**)malloc(sizeof(char*)*100);

    while ((dir = readdir(d)) != NULL){                /////Storing file names into string array
        if(strlen(dir->d_name)>2){

            int a = file_cmp(dir->d_name);
                if(a==0)
                {
                    Filen[i]=malloc(strlen(dir->d_name));
                    strcpy(Filen[i],dir->d_name);
                    i=i+1;
                }   
        }
            
    }
    int len;
    len=i;
    char *d1 = (char*)malloc(sizeof(char)*100);
    char *d2 = (char*)malloc(sizeof(char)*100);
    int nword=0; 
    int nword1=0;
    int dp;
    float vp;
     struct word words[100];
     struct word words1[100];
    for(int k=0;k<len;k++)
    {
      printf("        %s",Filen[k] );
    }   
    printf("\n");
    for (int k = 0; k < len; k++)
    {
      printf("%s  ",Filen[k] );
      for (int j = 0; j < len; j++)
      {
        if(strcmp(Filen[k],Filen[j])!=0 )
        {

        d1 = fileopen(Filen[k]);
        d2 = fileopen(Filen[j]);
        nword=word_freq(d1,words);
        nword1=word_freq(d2,words1);
        dp=dot(words,words1,nword,nword1);
        vp=denom(words,words1,nword,nword1);
        result(dp,vp);
      }
      else
      {
        printf("   00.00    ");
      }
      }
      printf("\n");
    }

  }
int dot(struct word words[100],struct word words1[100],int nword,int nword1)
{
int s=0;          ///////-------->>>>>>>>>> ///Finding dot product
int d=0;
for(int q=0;q<nword;q++)
{
  for(int j=0;j< nword1;j++)
   {
      if(strcmp(words[q].str,words1[j].str)==0)
      {
       s=s+words[q].count*words1[j].count;
      }
    }
}
return s;
}
float denom(struct word words[100],struct word words1[100],int nword,int nword1)
{                                               
 int h=0;
 int h1=0;                 ///------->>>>>>>    //Finding vector product
 for(int r=0;r<nword;r++)
 {
  h=h+pow(words[r].count,2);
 }
 for(int r1=0;r1<nword1;r1++)
 {
  h1=h1+pow(words1[r1].count,2);
 }
 float b=sqrt((h*h1));
 return b;
}
float result(int s,float b) // ---------- >>>>>> //Caluculating plagarism percentage
{
float x=(s/b)*100;
printf("  %0.2f  ",x);
}

int word_freq(char *str, struct word words[])  ///-------->>>>>>>  //Finding freq and splitting
{                                                                        // strings
char punct_str [] =" .,;/@#!&^(){}[]|""><?$*_-+=~`%':!?'\"\n\t"; 
char *tmp_str;  
char *wptr;     
int nword;       
int i;
nword = 0;
tmp_str = strdup(str);        
wptr = strtok(tmp_str, punct_str);   
while (wptr != NULL)
{
    for(i = 0; i < nword; i++)
    {

        if (strcmp(wptr,words[i].str) == 0)
            break; 
    }
        if (i < nword) 
            words[i].count++;    
        else
        {            
        strcpy(words[nword].str, wptr); 
        words[nword].count= 1; 
        ++nword;    
        }
wptr = strtok(NULL, punct_str);
}
return nword;
}
