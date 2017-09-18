#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include <math.h>
#include "fp.h"

int main(int argc,char  *argv[])
{
    char folder[1000];
    DIR *d;
    float percentage[100];
    struct dirent *dir;
    if(argc == 2){
        d=opendir(argv[1]);
        strcpy(folder,argv[1]);
        strcat(folder,"//");
    }
    else{

        d = opendir(".");
        strcpy(folder,".");
        strcat(folder,"//");
    }
    char *file_name_array[10];
    char *fg;
    int i = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char* ch=dir->d_name;
            if(strstr(ch,".txt")!=NULL)
            {
                file_name_array[i] = (char*)calloc(sizeof(char), sizeof(strlen(ch)));
                strcpy(file_name_array[i],ch);
                i++;
            }
        }  
        closedir(d);
    }
    int counter = 0;
    char *str1;	
    char *str2;
    int filesCount=i;
   
    float matrix [filesCount][filesCount];
    matrix[0][0]=100.00;
    for(int j = 0;j<i;j++)
    {

        for(int k = j+1;k<i;k++)
        {
            char file_path[1000];
            char file_path2[1000];
            strcpy(file_path,folder);
            strcat(file_path,file_name_array[j]);
            str1  = fileoperation(file_path);
            strcpy(file_path2,folder);
            strcat(file_path2,file_name_array[k]);
            str2 = fileoperation(file_path2);
            percentage[counter] = finger(str1,str2);
            matrix[j][k]=percentage[counter];
            matrix[k][j]=percentage[counter];
            counter++;
            
       }
    }
     printf("\t");
    for(int i = 0;i<filesCount;i++){
        printf("%12s",file_name_array[i] );
        matrix[i][i]=100.00;
    }
     printf("\n");
     for(int i = 0;i<filesCount;i++)
     {
        printf("%s",file_name_array[i] );
        for (int j = 0; j < filesCount; j++)
        {
            printf("%12.2f",matrix[i][j]);
        }
        printf("\n");
    }
 }   

