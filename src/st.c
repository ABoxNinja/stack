#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* profile;

void nl()
{
    profile = getenv("USERPROFILE");
    const char* last_sep = strrchr(profile,'\\');
    printf("\033[1;32m-> \033[0m");
    if (last_sep != NULL)
    {
        const char *name = last_sep + 1;
        char lower[256];
        int i;

        for (i = 0; name[i] != '\0'; ++i)
        {
            lower[i] = tolower(name[i]);
        } 
        lower[i] = '\0';

        printf("\033[1;34m%s\033[0m ", lower);
    }
    else
    {
        printf("fatal: error extracting name from dir value is NULL");
    }
}

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
            if (strcmp(input, "ping\n") == 0) {
                printf("pong\n");
                nl();
            }
            else if (strcmp(input, "pong\n") == 0) {
                printf("ping\n");
                nl();
            }
            else if ((strcmp(input, "clear\n"))==0)
            {
                printf("\033[2J\033[H");
                nl();
            }
            else if ((strcmp(input, "clean\n"))==0)
            {
                printf("\033[2J\033[H");
                nl();
            }
            else if ((strcmp(input,"info\n"))==0)
            {
                printf("\e[0;34mStack terminal was made by \e[44mABoxNinja\e[0;34m on \e[1;34mGitHub\e[0m\n");
                nl();
            }
            else if ((strcmp(input,"help\n"))==0)
            {
                printf("\e[44mCOMMANDS\e[0m\n");
                printf("\e[1;34m ping\e[0m"); printf("\e[0;30m  test command\e[0m\n");
                printf("\e[1;34m pong\e[0m"); printf("\e[0;30m  test command\e[0m\n");
                printf("\e[1;34m clean\e[0m"); printf("\e[0;30m  clear the output\e[0m\n");
                printf("\e[1;34m clear \e[0m"); printf("\e[0;30m  clear the output\e[0m\n");
                printf("\e[1;34m info\e[0m"); printf("\e[0;30m  return terminal info\e[0m\n");
                printf("\e[1;34m help\e[0m"); printf("\e[0;30m  current command\e[0m\n");
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