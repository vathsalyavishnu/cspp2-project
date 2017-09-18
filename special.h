char* specialcharacter(char* s)     //------->>>>>>//removing special characters
{
    strlwr(s);
    int i=0,j=0;
    int a=strlen(s);
    char* data=(char*)malloc(sizeof(char)*1000);
    while(i!=a)
    {
        if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
        {
            data[j]=s[i];
            j++;
        }
        i++;
    }
    data[i]='\0';
    return data;
}
float Lcs(char *e,char *r)        ////  ------->>>>>>>>>  //finding Longest common substring                   
{
    int i=0,j=0,c=0;
    for(int i=0;i<strlen(e);i++){
        int x=i;
        int y=x;
        for(int j=0;j<strlen(r);j++){
            if(x<strlen(e)){
                if (e[x]==r[j]){       ///------->>>>>> //comparison of characters
                    x+=1;
                    if((x-i)>c){
                        c=x-i;
                    }
                } 
                else{
                    x=y;
                }   
            }
        }
    } 
    return(c);
}