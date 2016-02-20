#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
char * s_gets(char * st, int n);
void split (char [], char [], char [], char []);
void clear(char[], int n);
void authenticator(char [], char [], char []);
void displayCommnads();

int main()
{
        system("clear");

	char name[80], line[80], comm[20], p1[10], p2[10];
	int len, n;
	_Bool findComm = 1;

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

void authenticator(char comm[], char p1[], char p2[])
{
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

void clear( char string[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                string[i] = '\0';

}

void displayCommnads()
{

        printf("\nload filename\nexecute\ndebug\ndump start end\nhelp\nassemble filename\ndirectory\nexit\n\n");

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
