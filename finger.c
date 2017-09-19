#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
# include "finger.h"
int hash1[100]={0};
int hash2[100]={0};
int cmp_file(char *file_name)                       
{
    char *cmpr = (char *) malloc(sizeof(char) * 3);
    cmpr = "txt";
    char *ret;
    int a;
    ret = strstr(file_name,cmpr);          
    if(ret == NULL)
    {
        ret="file cannot be open";
    }
    a=strcmp(ret,cmpr);
    return a;
}

void percent_commonhash(int hash1[100], int arraylen1, int hash2[100], int arraylen2) 
{
	int i,j,e=0;
	float percent=0;
	for(i=0;i<arraylen1;i++)
	{
		for(j=0;j<arraylen2;j++)
		{
			if(hash1[i]==hash2[j])
			{
				e=e+1;
			}
		}
	}
	percent=(float)(2*e)/(arraylen1+arraylen2);
	printf("%10.2f",percent*100 );

}
void main(int argc,char *argv[]){        
    DIR *d;                                   
    struct dirent *dir;
    char *re[100];
    d = opendir(argv[1]);                
    int i=0;
    char** Filen=(char**)malloc(sizeof(char*)*100);
    while ((dir = readdir(d)) != NULL){                        
        if(strlen(dir->d_name)>2){
            int a = cmp_file(dir->d_name);       
                if(a==0)                                    
                {
                    Filen[i]=malloc(strlen(dir->d_name));
                    strcpy(Filen[i],dir->d_name);
                    i=i+1;
                }   
        }
            
    }
     for(int y=0;y<i;y++){                  
        printf("     ");
        printf("%8s",Filen[y] );
     }
  
    int k=0,r=0;
     float e[i][i];
     for(int t=0;t<i;t++){
        printf("\n%8s",Filen[t] );
         for(int n=0;n<i;n++){
            if(Filen[t]!=Filen[n]){    
            	char f1[100][100]={'\0'};
				char f2[100][100]={'\0'};
				int len1=store_kgram(Filen[t],f1);          
				int len2=store_kgram(Filen[n],f2);
				int arraylen1=remove_spaces(f1,len1,hash1);  
				int arraylen2=remove_spaces(f2,len2,hash2);
				percent_commonhash(hash1,arraylen1,hash2,arraylen2);  
				}
				else{
					float e=0.00;           
				printf("%10.2f");     
				}
			}
		}
	}
