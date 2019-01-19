
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char **arg){
	
	
	   FILE *fileprocess1,*fileprocess2;
	fileprocess1=fopen("text.txt","r");            		//file to be read having comments
	fileprocess2=fopen("without_comments.txt","w");		//file to be created and write code without comments 
	char c;
	c=fgetc(fileprocess1);
	while(c!=EOF)
	{
		if(c=='/')
		{
			if((c=fgetc(fileprocess1))=='/') 					//simple logic of checking till EOF end of file 
			{
				while((c=fgetc(fileprocess1))!='\n'&&(c!=EOF));
			}
			else if(c=='*')
			{
				code:
				while((c=fgetc(fileprocess1))!='*'&&(c!=EOF));
				if(c=='*')
				{
					if((c=fgetc(fileprocess1))!='/')
						goto code;						//using goto to start from block again
				}
			}
			else
			{
				fputc('/',fileprocess2);
				fputc(c,fileprocess2);
			}
		}
		else
		{
			fputc(c,fileprocess2);
		}
		c=fgetc(fileprocess1);
	}
	fclose(fileprocess1);
	fclose(fileprocess2);
	printf("New File wrote by the name of: withoutcomment.txt\n"); 
   
	
    return 0;
	
}
