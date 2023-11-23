#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/commands.h"

int main()
{
    printf("\033[2J\033[H");
    nl();
    char input[64];
    while(1)
    {
        fgets(input, sizeof(input), stdin);
        
        if (input != NULL)
        {
            char nbfr[sizeof(input)];
            strcpy(nbfr,input);
            size_t nlp = strcspn(nbfr, "\n");
            if (nbfr[nlp] == '\n') {
                nbfr[nlp] = '\0';
            }
            //Command list add \n at the end of your command.
            if ((strcmp(input, "clear\n"))==0 || (strcmp(input, "clean\n"))==0)
            {
                printf("\033[2J\033[H");
                nl();
            }
            else if ((strcmp(input,"info\n"))==0)
            {
                printf("\e[0;34mStack terminal was made by ABoxNinja on \e[1;34mGitHub\e[0m\n");
                nl();
            }
            else if ((strcmp(input,"help\n"))==0)
            {
                help();
                nl();
            }
            else if ((strcmp(input ,"\n"))==0)
            {
                nl();
            }else {
                printf("\e[0;31mfatal: \"%s\" is not a valid command\e[0m\n",nbfr);
                nl();
            }
        }
    }
    return 0;
}