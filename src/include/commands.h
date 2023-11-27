#ifndef COMMANDS_H
#define COMMANDS_H

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

void help()
{
    printf("\e[44mCOMMANDS\e[0m\n");
    printf("\e[1;34m clean\e[0m"); printf("\e[0;30m  clear the output\e[0m\n");
    printf("\e[1;34m clear \e[0m"); printf("\e[0;30m  clear the output\e[0m\n");
    printf("\e[1;34m info\e[0m"); printf("\e[0;30m  return terminal info\e[0m\n");
    printf("\e[1;34m help\e[0m"); printf("\e[0;30m  current command\e[0m\n");
}

void startProgram(char execPath[256])
{
    system(execPath);
}

#endif