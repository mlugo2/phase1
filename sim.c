#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
char * s_gets(char * st, int n);
void split (char [], char [], char [], char []);
void clear(char[], int n);

int main()
{
        system("clear");

	const char *commands[8];

	commands[0] = "assemble";
	commands[1] = "debug";
	commands[2] = "directory";
	commands[3] = "dump";
	commands[4] = "execute";
	commands[5] = "exit";
	commands[6] = "help";
	commands[7] = "load";

	char name[80], line[80], comm[20], p1[10], p2[10];
	int len, n;
	_Bool findComm = 1;

	do{
                // This function clears command and parameters
                clear(comm, 20);
                clear(p1, 10);
                clear(p2, 10);

		// Promnt user for command line
		printf("~command>: ");
		s_gets(line, 80);

		// Split up the line into the command and parameters
		split(line, comm, p1, p2);


                // Display command and parameters
                printf("Command: @%s@\n", comm);
                printf("P1: %s\n", p1);
                printf("P2: %s\n", p2);

	}while(!strcmp(comm,"exit") == 0);
        printf("Thank you! Bye~\n");

	return 0;
}

void clear( char string[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                string[i] = '\0';

}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	// Look for newline
		if(find)			// if the address is not NULL,
			*find = '\0';		// place a null character there
		else
			while (getchar() != '\n')
				continue;	//dispose of rest of line
	}
	return ret_val;
}

void split( char line[], char comm[], char p1[], char p2[])
{

	int len, i, j;
        char temp1[20];

	temp1[0] = '\0';

	i = 0;
	j = 0;
	// To find the position of the first character
	while ( line[i] == ' ')
		i++;

	while( line[i] != '\0')
	{

		temp1[j] = line[i];
                
		++j;
		++i;
 
		if (line[i] == ' ' || line[i] == '\0')
		{
			temp1[j] = '\0';
			break;
		}

                
	}
        
       
	strcpy(comm, temp1);

	// To find the position of the first characters
	while ( line[i] == ' ')
		i++;

	if ( line[i] != '\0' )
	{
		j = 0;
		while( line[i] != '\0')
		{

			temp1[j] = line[i];

			++j;
			++i;

			if (line[i] == ' ' || line[i] == '\0')
			{
				temp1[j] = '\0';
				break;
			}
		}


		strcpy(p1, temp1);
	}


	// To find the position of the first characters
	while ( line[i] == ' ')
		i++;

	if ( line[i] != '\0' )
	{
		j = 0;
		while( line[i] != '\0')
		{

			temp1[j] = line[i];

			++j;
			++i;

			if (line[i] == ' ' || line[i] == '\0')
			{
				temp1[j] = '\0';
				break;
			}
		}


		strcpy(p2, temp1);
	}


}
