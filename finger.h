int store_kgram(char fn[50], char f[100][100])            

{
	FILE *fp;
	fp=fopen(fn,"r");
	char c;
	int i=0,j=0;
	while(1)
	{
		c=fgetc(fp);

		int ascii=(int)(c);         
		if(c==EOF)
		
			break;
		
		else if(c==' '|| c=='\n')           
		{
			f[i][j]='\0';
			i++;
			j=0;
			
		}
		if((ascii>=65 && ascii <=90) || (ascii>=97 && ascii<=122))
		{
		f[i][j]=c;
		strlwr(f[i]);            
		j++;

		

		}

	}
	int len=i+1;
	
	fclose(fp);
	return len;
}
int remove_spaces(char f[100][100],int len,int hash[100])     
{
	char a[500]={'\0'};
	int i=0,j,p=0,q,r,x,y;
	char rd[100][100]={'\0'};
 	int arraylen=0;
	while(i<len)
	{
		j=0;
		while(f[i][j]!='\0')
		{
			a[p]=f[i][j];
			p++;
			j++;
		}
		i++;		
	}
	int k=5;
	for(i=0;i<strlen(a)-9;i++)
	{
		p=0;
		y=i;
		while(p<k){     
			rd[i][p]=a[y];
			p++;
			y++;
		}

	}
	long long s;
	int g=0;
	for(q=0;q<i;q++)
	{
		s=0;
		g=0;
		for(r=0;r<strlen(rd[q]);r++)     
		{
			s+=(rd[q][r]*pow(k,k-(r+1))); 
			g=s%10007;
			hash[q]=g;



		}
		
	}
	arraylen=q;
	return arraylen;
	
}