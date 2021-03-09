#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void line1();
void line2();
int main()
{
	char choice,fc;
	int i=0,j=0,a=0,cntr=0,nlcounter=0;
	char ch[50],ck,chl[155];
	
	FILE *f;
	f=fopen("student.dat","r");
	if(f==NULL)
	{
		printf("ERROR");
	}
	printf("\t\t\t\t\t\t\t*****--------:STUDENT DATABASE ACCESS POINT:--------*****\n");
	printf("\n\n**INSTRUCTION:");
	printf("\nPlease Go As per Instruction Due To Case-Sensitive:*");
	printf("\nMENU:");
	printf("\nCHOOSE AS YOU WANT:");
	printf("\na.To Acess All The Data");
	printf("\ns.Manual Search\n");
	scanf("%c",&choice);
	printf("\n");
	while(1)
	{
		switch(choice)
		{
		case 'a':
			line1();
			line2();
			printf("\n");
			while(1)
			{	
				fc=fgetc(f);
				if(fc==EOF)
				{
					break;
				}
				if(fc=='\n')
				{
					printf("%c",fc);
					line2();
					printf("\n");
				}
				else
				{
					printf("%c",fc);
				}
			}
			break;
		case 's':
			printf("Search:");
			while((getchar())!='\n');
			scanf("%[^\n]",ch);
			line1();
			line2();
			while(ch[cntr]!='\0')
			{
				cntr++;
			}
			while(1)
			{
				ck=fgetc(f);
				if(ck==ch[i])
				{
					i++;
					if(i==cntr)
					{
						while(1)
						{
							chl[j]=ck;
							ck=fgetc(f);
							j++;
							if(ck=='\n')
							{
								if(nlcounter==0)
								{
									printf("\n");
								}
								if(a)
								{
									printf("%.147s\n",chl);
								}
								if(!a)
								{
									printf("%.146s\n",chl);
									a=1;
								}
								line2();
								nlcounter++;
								//printf("\n");
								break;
							}
						}
					}
				}
				else
				{
					i=0;
				}
				if(ck=='\n')
				{
					nlcounter++;
					j=0;
				}
				chl[j]=ck;
				j++;
				if(ck==EOF)
				{
					break;
				}
			}
			printf("\n");

			}
		printf("q for quit from the session !\n");
		printf("else choose previous option\n");
		while((getchar())!='\n');
		scanf("%c",&choice);
		if(choice=='q')
		{
			exit(0);
		}
		fseek(f, 0, SEEK_SET);
	}
	
	return 0;
}
	void line1()
	{
		char sid[]="STUDENT ID:";
		char n[]="STUDENT NAME:";
		char d[]="DEPARTMENT:";
		char sy[]="STUDYING-YEAR:";
		char dob[]="DOB:";
			/*while(counter1<161)
		{
			if(counter1==0)
			{
				printf("+");
			}
			else if(counter1==160)
			{
				printf("+");
			}
			else
			{
				printf("-");
			}
			counter1++;
		}*/
		line2();
		printf("\n");
		printf("|%-15s",sid);
		printf("|%-55s",n);
		printf("|%-55s",d);
		printf("|%-15s",sy);
		printf("|%-15s|",dob);
		printf("\n");
		
	}
 	void line2()
 	{
 		int counter2=0;
 		counter2=0;
		while(counter2<156)
		{
			if(counter2==0)
				{
					printf("+");
				}
				if(counter2==15)
				{
					printf("+");
				}
				if(counter2==70)
				{
					printf("+");
				}
				if(counter2==125)
				{
					printf("+");
				}
				if(counter2==140)
				{
					printf("+");
				}
				if(counter2==155)
				{	
					printf("+");
				}
				if(counter2<155)
				{
					printf("-");
				}
				counter2++;
		}
		
 	}