#include<stdio.h>
#include<string.h>


	void search(char string[],char pat[])
	{
		int hashvalue=0;
		int hash_substr=0;
		int i,j,P=1;
		int m=strlen(pat),n=strlen(string);
		int p=3;  //p is the prime number
		for(i=0;i<strlen(pat);i++)
		{
			hashvalue=hashvalue*p+(pat[i]-'a');
			hash_substr=hash_substr*p+(string[i]-'a');
			P=P*p;
		}
		printf("hash reqd: %d   ",hashvalue);
		printf("hash substr: %d  ",hash_substr);
		printf("P=%d    ",P);
		for(j=0;j<n-m;j++)
		{
			if(hashvalue==hash_substr)
			{
				/*int count=0;
				for(i=0;i<strlen(pat);i++)
				{
					if(string[i+j]!=pat[i])
						break;
					else
						count++;
				}
				if(count>0)*/             //This is required if its hashed
				printf("There is a matching at %d",j);
				return;
			}
			//printf("hash substr%d: %d   ",j,hash_substr);	
			printf("         %d         ",(string[j+m]-'a'));	
			printf("         %d         ",(string[j]-'a'));	
			hash_substr=(((hash_substr-((string[j]-'a')*(P/p)))*p+(string[j+m]-'a')));
			printf("hash substr%d: %d   ",j+1,hash_substr);
			
	}
	return;
	}
			
int main()
{
	char string[]="bcdeabc";
	char pat[]="cde";
	search(string,pat);
	return 0;
}			
