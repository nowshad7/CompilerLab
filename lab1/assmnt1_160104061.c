#include <stdio.h>

void check_comment_space (char) ;
void block_comment () ;
void single_comment () ;

FILE *p1,*p2;

int main(void)
{
    char c;

    p1 = fopen("input1_160104061.c", "r");
    p2 = fopen("output1_160104061.txt","w");

    if(!p1)
        printf("\nFile can't be opened!");
        else
        {
            while((c = fgetc(p1)) != EOF){
                if(c=='\n')continue;
                check_comment_space(c);
            }
        }
    fclose(p1);
    fclose(p2);

    p2 = fopen("output1_160104061.txt","r");
    while((c=fgetc(p2))!=EOF)
        printf("%c",c);
    fclose(p2);

    return 0;
}

void check_comment_space(char c)
{
    char d;
    if( c == '/')
    {
        if((d=fgetc(p1))=='*')
            block_comment();
            else if( d == '/')
            {
                single_comment();
            }
                else
                {
                    fputc(c,p2);
                    fputc(d,p2);
                }
    }
        else if (c==' ')
            {
                fputc(c, p2);
                while((c = fgetc(p1))==' '){}
                fputc(c, p2);
            }


            else fputc(c,p2);
}


void block_comment()
{
    char d,e;
    while((d=fgetc(p1))!=EOF)
    {
        if(d=='*')
        {
            e=fgetc(p1);
            if(e=='/') return;
        }
   }
}

void single_comment()
{
    char d;
    while((d=fgetc(p1))!=EOF)
    {
        if(d=='\n') return;
    }

}


