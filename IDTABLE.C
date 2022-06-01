#include<stdio.h>
#include<conio.h>

//defines number of input
#define NUM 10

struct student
{
	char name[50];
	int age;
	char gender;
};

//create border to the table
void das(int dash)
{
	int i;
	printf("+");
	for(i = 0 ; i < dash ; i++)
		printf("-");
	printf("+");
}

//@return - it returns the size of longest string "name" from the input
//it always returns the value more than 4 to keep the Name column looks in shape
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
	if(longest < 4)
		return 4;
	
	return longest;
}

//createing the variable of type struct student
struct student s;

//special function to print the Name column 
//having width 2 characters more than the 
//longest name
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
	//dummy variable is used to eliminate the problem
	//of escaping the character input after integer input
	char dummy;
	//buffer is used to store the input name
	char buffer[8000];
	//table headers
	char name[5] = "Name";
	char age[4] = "age";
	char gender[7] = "gender";

	clrscr();
	
	//input data
	for(i = 0 ; i < NUM ; i++)
	{
		printf("\nEnter the name : ");
		scanf("%[^\n]s",buffer);
		for(count = 0 ; count < 49 ; count++)
		{
			if((buffer[count] >= 65 && buffer[count] <= 90)	|| (buffer[count] >= 97 && buffer[count] <= 122) || buffer[count] == ' ')
			{
				s[i].name[count] = buffer[count];
			}
			else
			{
				break;
			}
		}
		printf("Enter your age : ");
		scanf("%d",&s[i].age);
		scanf("%c",&dummy);
		printf("Enter your gender : ");
		scanf("%c",&s[i].gender);
		scanf("%c");
	}

	//stores the size of longest string (always 4 or more than 4)
	longest = checkLongest(s);

	//table size is dependent on the length of longest name
	dash = longest + 18 + 2; //longest(Name) + age and gender + extra space

	//output
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
