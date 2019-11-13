#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lexemes_Separation();
int check_keyword(char lexeme[]);
int checkId(char lexeme[]);
int check_operator(char lexeme[]);
int check_number(char lexeme[20]);
int check_bracket(char lexeme[]);
int check_separator(char lexeme[]);

FILE *f1,*f2,*f3;

int main()
{
    char c;
    f1 = fopen("scanned.txt", "r");
    f2 = fopen("lexemes.txt", "w");


    lexemes_Separation();

    fclose(f1);
    fclose(f2);

    printf("Input File:\n\n");
    f1 = fopen("scanned.txt", "r");
    while((c=fgetc(f1))!=EOF)
    {
        printf("%c",c);
    }
    printf("\n\n\n");
    f1 = fopen("lexemes.txt", "r");
    printf("Lexemes Separated by Space: \n\n");
    while((c=fgetc(f1))!=EOF)
    {
        printf("%c",c);
    }
    printf("\n\n\n");
    f1 = fopen("lexemes.txt", "r");
    f2 = fopen("tokens.txt", "w");
    char str[50];
    while(fscanf(f1, "%s", &str)!=EOF)
    {
        if(check_keyword(str))
            fprintf(f2, "[kw %s] ", str);
        else if(check_operator(str))
            fprintf(f2, "[op %s] ", str);
        else if(check_bracket(str))
            fprintf(f2, "[par %s] ", str);
        else if(check_separator(str))
            fprintf(f2, "[sep %s] ", str);
        else if(checkId(str))
            fprintf(f2, "[id %s] ", str);
        else if(check_number(str))
            fprintf(f2, "[num %s]", str);
        else
        {
            fprintf(f2, "[unkn %s]", str);
            f3 =fopen("Error.txt","w");
            fprintf(f3, "Error : unknown %s", str);
            fclose(f3);
        }
    }
    fclose(f1);
    fclose(f2);
    printf("Final Result: \n\n");
    f1 = fopen("tokens.txt", "r");
    while((c=fgetc(f1))!=EOF)
    {
        printf("%c",c);
    }
    printf("\n\n\n");
    f3 =fopen("Error.txt","r");
    while((c=fgetc(f3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(f3);
    printf("\n\n");
    return 0;
}

int lexemes_Separation()
{
    char c;
    while((c=fgetc(f1))!=EOF)
    {
        if(!isalnum(c) && c!=' ' && c!='_' && c!='.')
            fputc(' ', f2);
        fputc(c, f2);
        if(c=='>' || c=='<'|| c=='=' || c=='!')
        {
            char ch;
            if((ch=fgetc(f1))=='=')
            {
                fputc(ch, f2);
                fputc(' ', f2);
            }
            else
            {
                fputc(' ', f2);
                fputc(ch, f2);
                if(!isalnum(ch) && ch!=' ' && ch!='_' && ch!='.')
                    fputc(' ', f2);
            }
        }
        else if(!isalnum(c) && c!=' ' && c!='_' && c!='.')
            fputc(' ', f2);
    }
    return 0;
}

int check_keyword(char lexeme[])
{
    int i, s=0;
    char keywords[][15] = {"int","ﬂoat","double","char","return","if","else","else if","while","for","case","do while","goto"};
    for(i=0; i<12; i++)
        if(!strcmp(lexeme,keywords[i]))
        {
            s=1;
            break;
        }
    return s;
}

int checkId(char lexeme[])
{
    int i, s=0, l;
    l=strlen(lexeme);
    if((isalpha(lexeme[0])) || (lexeme[0]=='_'))
        s=1;
    if(s==1)
    {
        for(i=1; i<l; i++)
        {
            if(!isalnum(lexeme[i]) && lexeme[i]!='_'&& !isalpha(lexeme[i]))
            {
                s=0;
                break;
            }
        }
    }
    return s;
}
int check_operator(char lexeme[])
{
    int i, l,s=0;
    l=strlen(lexeme);
    if(l==1 && (lexeme[0]=='>' || lexeme[0]=='+' || lexeme[0]=='-' || lexeme[0]=='*' || lexeme[0]=='/' || lexeme[0]=='<' || lexeme[0]=='='))
        return 1;
    else if(l==2 && (lexeme[0]=='>' || lexeme[0]=='<'|| lexeme[0]=='=' || lexeme[0]=='!') && lexeme[1]=='=')
        s=1;
    else s=0;
    return s;
}
int check_number(char lexeme[20])
{
    int i, l, s;
    i=0;
    if(isdigit(lexeme[i]))

    {
        s=1;
        i++;
    }
    else if(lexeme[i]=='.')
    {
        s=2;
        i++;
    }
    else s=0;
    l=strlen(lexeme);
    if(s==1)
        for(; i<l; i++)
        {
            if(isdigit(lexeme[i]))
                s=1;
            else if(lexeme[i]=='.')
            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }
    if(s==2)
        if(isdigit(lexeme[i]))
        {
            s=3;
            i++;
        }
        else s=0;
    if(s==3)
        for(; i<l; i++)
        {
            if(isdigit(lexeme[i]))
                s=3;
            else
            {
                s=0;
                break;
            }
        }
    if(s==3) s=1;
    return s;
}
int check_bracket(char lexeme[])
{
    int l = strlen(lexeme);
    return (l==1 && (lexeme[0]=='(' || lexeme[0]==')' || lexeme[0]=='{' || lexeme[0]=='}' || lexeme[0]=='[' || lexeme[0]==']'));
}

int check_separator(char lexeme[])
{
    int i, l;
    l=strlen(lexeme);
    if(l==1 && (lexeme[0]==',' || lexeme[0]==39 || lexeme[0]==';' || lexeme[0]=='"'))
        return 1;
    else
        return 0;
}
