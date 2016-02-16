#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void split (char [], char [], char [], char []);

int main()
{

	char name[80], line[80], comm[20], p1[10], p2[10];
	int len, n;

	// Initialize char arrays
	comm[0] = '\0';
	p1[0] = '\0';
	p2[0] = '\0';

	// Promnt user for command line
	printf("Please enter a command: ");
	fgets(line, 80, stdin);

	// Split up the line into the command and parameters
	split(line, comm, p1, p2);

	// Display the command and parameters
	printf("Command: %s\n", comm);
	printf("P1: %s\n", p1);
	printf("P2: %s\n", p2);

	return 0;
}

void split( char line[], char comm[], char p1[], char p2[])
{

	int len, i, j;
        char temp1[20];

	temp1[0] = '\0';
	
	// Make sure there are no new lines in string
	len = strlen(line);
        if ( line[len-1] == '\n')
		line[len-1] = '\0';

	i = 0; 
	j = 0;
	// To find the position of the first characters
	while ( line[i] == ' ')
		i++;

	while( line[i] != '\0')
	{

		temp1[j] = line[i];
		++j;
		++i;
		
		if (line[i] == ' ')
		{
			temp1[j] = '\0';
			break;
		}
	}
	
	strcpy(comm, temp1);

	if ( line[i] != '\0' )
	{
		j = 0;
		// To find the position of the first characters
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


		strcpy(p1, temp1);
	}

	
	if ( line[i] != '\0' )
	{
		j = 0;
		// To find the position of the first characters
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


		strcpy(p2, temp1);
	}
	

}
