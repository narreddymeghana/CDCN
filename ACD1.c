#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[])
{
    char keywords[][10] = {
        "int", "float", "char", "if",
        "else", "while", "for", "return"
    };

    int n = 8;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    FILE *fp;
    char ch, word[100];
    int i;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Ignore spaces, tabs and newlines */
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            continue;
        }

        /* Identifier or Keyword */
        if (isalpha(ch) || ch == '_')
        {
            i = 0;

            while (isalnum(ch) || ch == '_')
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';

            if (isKeyword(word))
                printf("%s -> Keyword\n", word);
            else
                printf("%s -> Identifier\n", word);

            ungetc(ch, fp);
        }

        /* Number */
        else if (isdigit(ch))
        {
            i = 0;

            while (isdigit(ch))
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';

            printf("%s -> Number\n", word);

            ungetc(ch, fp);
        }

        /* Comments and division operator */
        else if (ch == '/')
        {
            ch = fgetc(fp);

            if (ch == '/')
            {
                /* Ignore single-line comment */
                while ((ch = fgetc(fp)) != '\n' && ch != EOF)
                    ;
            }
            else if (ch == '*')
            {
                /* Ignore multi-line comment */
                char prev = 0;

                while ((ch = fgetc(fp)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }
            else
            {
                printf("/ -> Operator\n");
                ungetc(ch, fp);
            }
        }

        /* Operators */
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '=' || ch == '<' || ch == '>')
        {
            char next = fgetc(fp);

            if ((ch == '=' && next == '=') ||
                (ch == '<' && next == '=') ||
                (ch == '>' && next == '='))
            {
                printf("%c%c -> Operator\n", ch, next);
            }
            else
            {
                printf("%c -> Operator\n", ch);
                ungetc(next, fp);
            }
        }

        /* Special symbols */
        else if (ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' ||
                 ch == '[' || ch == ']' ||
                 ch == ';' || ch == ',')
        {
            printf("%c -> Special Symbol\n", ch);
        }

        /* Unknown character */
        else
        {
            printf("%c -> Unknown\n", ch);
        }
    }

    fclose(fp);

    return 0;
}
