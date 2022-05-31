#include<stdio.h>
#include<conio.h>

#define NUM 2

struct student
{
	char name[50];
	int age;
	char gender;
};

void das(int dash)
{
	int i;
	printf("+");
	for(i = 0 ; i < dash ; i++)
		printf("-");
	printf("+");
}

int checkLongest(struct student *s)
{
	int longest = strlen(s[0].name);
	int i = 0 ;
	int newSize = 0;
	for(i = 1 ; i < NUM ; i++)
	{
		newSize = strlen(s[i].name);
		if(longest < newSize)
			longest = newSize;
	}
	return longest;
}

struct student s;

void nameColumn(char *word, int longest)
{
	int count;
	int lengthName = strlen(word);
	if(lengthName <= longest)
	{
		lengthName = longest - lengthName + 2;
		for(count = 0 ; count < lengthName/2 ; count++)
			printf(" ");
	}
	printf("%s",word);
	if(lengthName % 2 != 0)
	{
		for(count = 0 ; count < lengthName/2 + 1 ; count++)
			printf(" ");
	}
	else
	{
		for(count = 0 ; count < lengthName/2 ; count++)
			printf(" ");
	}
}

int main( void )
{
	struct student s[10];
	int i, j, c;
	int longest;
	int count = 0;
	int dash = 33;
	char pole = '|';
	char dummy;
	char buffer[8000];
	char name[5] = "Name";
	char age[4] = "age";
	char gender[7] = "gender";

	clrscr();

	for(i = 0 ; i < NUM ; i++)
	{
		printf("\nEnter the name : ");
		scanf("%[^\n]s",buffer);
		for(count = 0 ; count < 49 ; count++)
			s[i].name[count] = buffer[count];
		printf("Enter your age : ");
		scanf("%d",&s[i].age);
		scanf("%c",&dummy);
		printf("Enter your gender : ");
		scanf("%c",&s[i].gender);
		scanf("%c");
	}

	longest = checkLongest(s);

	dash = longest + 18 + 2; //longest(Name) + age and gender + extra space

	printf("\n\nDisplay output\n");

	das(dash);

	printf("\n%c",pole);
	nameColumn(name,longest);
	printf("%c%5s%3c%8s%2c\n",pole,age,pole,gender,pole);

	das(dash);

	for(i = 0 ; i < NUM; i++)
	{
		printf("\n%c",pole);
		nameColumn(s[i].name,longest);
		printf("%-3c%-3d%3c%5c%5c",pole,s[i].age,pole,s[i].gender,pole);
	}
	printf("\n");

	das(dash);

	getch();

	return (0);
}
