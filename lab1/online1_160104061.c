
#include <stdio.h>


FILE *p1;
int l_count,i;
int l_n[100];


int main(void)
{
    char c;
    l_count=1;
    i=0;

    p1 = fopen("input.c", "r");
    if(!p1)
        printf("\nFile can't be opened!");
        else
        {
            while((c = fgetc(p1)) != EOF){
                if(c=='\n')l_count++;
                check_printf(c);
            }
        }
    fclose(p1);
    int j=0;
    while(l_n[j]!='\0'){
        printf("%d ",l_n[j]);
        j++;
    }


    return 0;
}
void check_printf(char c)
{
    char d;
    if( c == 'p')
    {
        if((c=fgetc(p1))=='r'){
            if((c=fgetc(p1))=='i'){
                if((c=fgetc(p1))=='n'){
                    if((c=fgetc(p1))=='t'){
                        if((c=fgetc(p1))=='f'){
                            l_n[i]=l_count;
                            i++;
                            return 0;
                        }
                    }
                }
            }
        }

    }
    return 0;
}
