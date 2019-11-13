#include<stdio.h>
#include<string.h>
int Expr(int s, int e);
int Term(int s, int e);
int Factor(int s, int e);
int isID(char c);
char str[10];
int decission;
int l;

int Expr(int s, int e) {

    int i,flag1,flag2;
    int j=e;
    int k=0;
    ///if(s>=e-1)return 0;
    printf("%d",e);
    for(i=s;i<=j;i++){
        if(str[i]=='+'||str[i]=='-'){
            flag1 = Term(s,i-1);
            flag2 = Term(i+1,e);

            if(flag1 && flag2)
                return 1;
            else return 0;
        }
        else {
            flag1= Term(s,e);
            if(flag1) return 1;
            else return 0;
        }
    }
    return 0;
}

int Term(int s,int e){
    int i,flag1,flag2;
    int j=e;
    int k=0;

    ///if(s>=e-1)return 0;
    for(i=s;i<=j;i++){
             printf("%d",i);
        if(str[i]=='*'||str[i]=='/'){
            flag1 = Factor(s,i-1);
            flag2 = Factor(i+1,e);
            if(flag1 && flag2)
                return 1;
            else return 0;
        }
        else {
            flag1= Factor(s,e);
            if(flag1) return 1;
            else return 0;
        }
    }
}

int Factor(int s, int e){
int i=s;
int j=e;
int flag1,flag2;
printf("Fuck you\n");
///if(s>=e-1)return 0;
if((i-j)==0){
    flag1=isID(str[i]);
    flag2=isdigit(str[i]);
    if(flag1||flag2) return 1;
    else return 0;
   }

  /* else if(s<e){
        flag1=Expr(i,j);
        if(flag1) return 1;
        else return 0;
   }
  // if(s>=e)
  return 0;
*/
}

int isID(char c){
if (c=='a'||c=='b'||c=='c'||c=='d'||c=='e')
    return 1;
else
    return 0;
}

int main() {

	printf("CFG:");
	printf("\n<Exp>: <Term> + <Term> | <Term> - <Term> | <Term>\n<Term> :<Factor> * <Factor> | <Factor> / <Factor> | <Factor>\n<Factor>:( <Exp> ) | ID | NUM\nID : a|b|c|d|e\nNUM :0|1|2|…|9\n");

        printf("\nEnter a string to parse: ");
        scanf("%s", str);

        l = strlen(str);
        decission= Expr(0,l-1);
        if (decission)
            printf("\nResult: Valid String\n");
        else
            printf("\nResult: Invalid String\n");

    return 0;
}



