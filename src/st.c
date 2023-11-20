#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nl()
{
    char* profile = getenv("USERPROFILE");
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
        
            if (strcmp(input, "hello\n") == 0) {
            
            printf("%s\n", nbfr);
            nl();
            }else if ((strcmp(input ,"\n"))==0)
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