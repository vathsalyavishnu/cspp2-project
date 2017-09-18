#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergesort.h"
void appendr(char s[], char c){
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

void removeSpaces(char str[])
{

    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';
}

long sum(long a[],int k){
    long s = 0;
    for(int i=0;i<k;i++)
        s += a[i];
    return s;
}
long intersect(long array1[], long array2[], long array[],int size1,int size2)
{
    int i = 0, j = 0, k = 0;

    while ((i < size1) && (j < size2))
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}

double hashc(char* s){
    double sum;
    sum = s[0]*10000 + s[1]*1000 + s[2]*100 + s[3]*10 + s[4];
    return sum;
}

int hashv( char text[],long hash[]){

    char word[1000][10];
    int k = 0;
    for(int i = 0; i < strlen(text)-4; i++){

        strcpy(word[k],"");
        for(int j = i; j < i + 5; j++){
            appendr(word[k],text[j]);
        }
        hash[k] = hashc(word[k]);

        k ++;
    }
    for(int i = 0; i < k; i++)
        hash[i] = hash[i]%10007;
    return k;
}

float finger(char text11[],char text22[]){
    printf("%s\t %s\n",text11,text22 );
    char text1[1000];
    char text2[1000];
    long hash1[1000];
    long hash2[1000];
    long hash[1000];
    strcpy(text1,text11);
    strcpy(text2,text22);

    removeSpaces(text1);
    removeSpaces(text2);

    int k1 = hashv(text1,hash1);
    int k2 = hashv(text2,hash2);

    merge(hash1,0,k1-1);
    merge(hash2,0,k2-1);
    int k = intersect(hash1,hash2,hash,k1,k2);



    printf("\n");
    float per = sum(hash,k)*200/(sum(hash1,k1)+sum(hash2,k2));
    printf("%f",per);   
    return per;
}

