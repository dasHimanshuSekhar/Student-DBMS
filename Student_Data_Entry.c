#include<stdio.h>
#include <stdlib.h>
struct student
{
	int studentid;
	char studentname[50];
	char department[50];
	char yearofaddmission[10];
	struct DOB
	{
		int date;
		int month;
		int year;
	}dob;
};
struct student s[50];
//struct DOB dob;
int main()
{
	int i=0;
	char choice='Y';
	FILE *f;
	f=fopen("student.dat","a+");
	if(f==NULL)
	{
		printf("ERROR");
		exit (1);
	}
	i=0;
	printf("\t\t\t\t\t\t\t*****--------:STUDENT DATABASE ENTRY POINT:--------*****\n");
	printf("\n\n**INSTRUCTION:");
	printf("\nPlease Go As Per Instruction Due To Case-Sensitive:*\n\n");
	while(choice=='Y' || choice=='y')
	{		
		printf("Enter Student Id:");
		scanf("%d",&s[i].studentid);
		fprintf(f,"| %.10d\t",s[i].studentid );
		while((getchar())!='\n');
		printf("Enter Student Name:");
		scanf("%[^\n]",s[i].studentname);
		fprintf(f,"| %-50s\t",s[i].studentname);
		while((getchar())!='\n');
		printf("Enter Department:");
		scanf("%[^\n]",s[i].department);
		fprintf(f,"| %-50s\t",s[i].department);
		while((getchar())!='\n');
		printf("Enter Year Of Addmission:");
		scanf("%[^\n]",s[i].yearofaddmission);
		fprintf(f,"| %-10s\t",s[i].yearofaddmission);
		while((getchar())!='\n');
		printf("Enter the DOB in Below Asking Format:-\n\n");
		printf("Enter Date:");
		scanf("%d",&s[i].dob.date);
		printf("Enter Month:");
		scanf("%d",&s[i].dob.month);
		printf("Enter Year:");
		scanf("%d",&s[i].dob.year);
		fprintf(f,"| %.2d-%.2d-%.4d\t|\n",s[i].dob.date,s[i].dob.month,s[i].dob.year);
		while((getchar())!='\n');
		printf("\nEnter 'y' else 'n':");
		scanf("%c",&choice);
		i++;
	}
	return 0;
}