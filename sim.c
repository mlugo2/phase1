/********************************************************
*  Marco Lugo                                           *
*  CMPE 3334                                            *
*  2/21/2015                                            *
*                                                       *
*  This program is a simulation of a command line       *
*  interpreter. For phase 1 only the commands:          *
*  help, directory, and exit are implemented but        *
*  all commands are recognized.                         *
********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
char * s_gets(char * st, int n);
void split (char [], char [], char [], char []);
void clear(char[], int n);
void authenticator(char [], char [], char []);
void displayCommnads();
void welcomeMessage();

int main()
{
        // char arrays for input, command, and parameters
	char line[80], comm[20], p1[10], p2[10];

        // Display welcome message
        welcomeMessage();

	do{
                // These functions clear command and parameters
                clear(comm, 20);
                clear(p1, 10);
                clear(p2, 10);

		// Promnt user for command line
		printf("~command>: ");
		s_gets(line, 80);

		// Split up the line into the command and parameters
		split(line, comm, p1, p2);

                // This function authenticates commands and parameters
                authenticator(comm, p1, p2);

	}while(!strcmp(comm,"exit") == 0 || p1[0] != '\0');
        printf("Thank you! Bye~\n");

	return 0;
}


/********************************************************
*               authenticator()                         *
*                                                       *
*  This fucntion takes three char arrays as paramters.  *
*  Using embedded if/else statements it determines      *
*  which commands require paramaters as well as which   *
*  don't.                                               *
********************************************************/
void authenticator(char comm[], char p1[], char p2[])
{

        /* If no paramaters needed only parameter 1 is checked.
           If only one parameter is needed both parameters are checked.
           If two parameters are needed both are checked.
        */
        if(!strcmp(comm,"load"))
                 {
                        if(p1[0] == '\0')
                                printf("Error: Parameter needed.\n");
                        else if(p2[0] != '\0')
                                printf("Error: Second parameter not required.\n");
                        else
                                printf("Command is %s.\n", comm);
                }
        else if(!strcmp(comm,"execute"))
                {
                        if(p1[0] != '\0')
                                printf("Error: No parameters needed.\n");
                        else
                                printf("Command is %s.\n", comm);
                }
        else if(!strcmp(comm,"debug"))
                {
                        if(p1[0] != '\0')
                                printf("Error: No parameters needed.\n");
                        else
                                printf("Command is %s.\n", comm);
                }
        else if(!strcmp(comm,"dump"))
                {
                        if(!strcmp(p1,"start") == 0)
                                printf("Error: First parameter incorrect.\n");
                        else if(!strcmp(p2,"end") == 0)
                                printf("Error: Second parameter incorrect.\n");
                        else
                                printf("Command is %s.\n", comm);
                }
        else if(!strcmp(comm,"help"))
                {
                        if(p1[0] != '\0')
                                printf("Error: No parameters needed.\n");
                        else
                                displayCommnads();
                }
        else if(!strcmp(comm,"assemble"))
                {
                        if(p1[0] == '\0')
                                printf("Error: Parameter needed.\n");
                        else if(p2[0] != '\0')
                                printf("Error: Second parameter not required.\n");
                        else
                                printf("Command is %s.\n", comm);
                }
        else if(!strcmp(comm,"directory"))
                system("ls");
        else if(!strcmp(comm,"exit"))
                 {
                        if(p1[0] != '\0')
                                printf("Error: No parameters needed.\n");
                }
        else
        {
               printf("Error: %s in not a valid command.\n", comm); // ¯\_(ツ)_/¯
               displayCommnads();
        }
}

/********************************************************
*                       clear()                         *
*                                                       *
*  This fucntion takes any given char array and fills   * 
*  it with null characters to erase previous inputs.    *
********************************************************/
void clear( char string[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                string[i] = '\0';

}

/********************************************************
*                  displayCommnads()                    *
*                                                       *
*  This fucntion displays all available commands and    *
*  parameters.                                          *
********************************************************/
void displayCommnads()
{

        printf("\nload filename\nexecute\ndebug\ndump start end\nhelp\nassemble filename\ndirectory\nexit\n\n");

}

/********************************************************
*                     s_gets()                          *
*                                                       *
*  This fucntion takes in a char array and array length *
*  to get rid of any '\n'.
********************************************************/
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


/********************************************************
*                       split()                         *
*                                                       *
*  This fucntion takes in the users input and divides   *
*  into the cammand and two parameters. Any more        *
*  parameters than two are ignored.                     *
********************************************************/
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

void welcomeMessage()
{
        static unsigned char asciipic_txt[] = {                                                
        0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x5f, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5f, 0x5f, 0x5f,
        0x5f, 0x5f, 0x20, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x20, 0x0a, 0x2f, 0x20,
        0x20, 0x5f, 0x5f, 0x5f, 0x28, 0x5f, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x20, 0x5f, 0x20, 0x20,
        0x2f, 0x20, 0x20, 0x5f, 0x5f, 0x5f, 0x7c, 0x0a, 0x5c, 0x20, 0x60, 0x2d,
        0x2d, 0x2e, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x5f, 0x20, 0x5f, 0x5f,
        0x5f, 0x20, 0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x5c, 0x20,
        0x60, 0x2d, 0x2d, 0x2e, 0x20, 0x0a, 0x20, 0x60, 0x2d, 0x2d, 0x2e, 0x20,
        0x7c, 0x20, 0x7c, 0x20, 0x27, 0x5f, 0x20, 0x60, 0x20, 0x5f, 0x20, 0x5c,
        0x20, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x60, 0x2d, 0x2d,
        0x2e, 0x20, 0x5c, 0x0a, 0x2f, 0x5c, 0x5f, 0x5f, 0x2f, 0x20, 0x7c, 0x20,
        0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20, 0x7c, 0x20,
        0x5c, 0x20, 0x5c, 0x5f, 0x2f, 0x20, 0x2f, 0x5c, 0x5f, 0x5f, 0x2f, 0x20,
        0x2f, 0x0a, 0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x7c, 0x5f, 0x7c, 0x5f,
        0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x7c, 0x5f, 0x7c, 0x20, 0x20, 0x5c,
        0x5f, 0x5f, 0x5f, 0x2f, 0x5c, 0x5f, 0x5f, 0x5f, 0x5f, 0x2f, 0x0a

        };

        system("clear");
        printf("%s\n", asciipic_txt);
        printf("Welcome to Sim OS 1.0\n");
        printf("For supported commands type: help\n\n");

}
