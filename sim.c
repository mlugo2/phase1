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

	// Promnt user for name
	printf("Please enter your name: ");
	fgets(name, 80, stdin);
	len = strlen(name)-1;
	if ( name[len] == '\n')
		name[len] = '\0';

	// Promnt user for command line
	printf("Hello %s! Please enter a command: ",name);
	fgets(line, 80, stdin);

	// Split up the line into the command and parameters
	split(line, comm, p1, p2);


	printf("\nHere is the line you entered: %s\n", line);
	printf("Command: %s\n", comm);
	printf("P1: %s\n", p1);
	printf("P2: %s\n", p2);

	return 0;
}

void split( char line[], char comm[], char p1[], char p2[])
{

	printf("\nHere is the line recieved: %s\n", line);	

	int len, i, j;
        int start = 0, end = 0;         // Hold location for start and end of sinle word.
        char temp1[10], temp2[10], temp3[10], temp4[10] temp5[10];

	len = strlen(line);

        if ( line[len-1] == '\n')
		line[len-1] = '\0';

	i = 0;
        j = 0;
   
        // In case any spaces are pressed before the command
        while ( line[i] == ' ')  
        {       i++; 
                start = i; 
        }

        


        printf("%d", start);

}
