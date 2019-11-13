#include<stdio.h>
#include<string.h>
void A(void);
void X(void);
char str[10];
int f=0;
int i=0;
int l;

int main(void) {

	printf("CFG:");
	printf("\n\tA -> aXd\n\tX -> bbX\n\tX -> bcX\n\tX -> ep\n");
	int n,m=0;
	printf("\nHow many test: ");
	scanf("%d",&n);
	while(n!=0){
        i=0;
        f=0;
        n--;
        m++;
        printf("\nTest: %d", m);
        printf("\nEnter a string to parse: ");
        scanf("%s", str);

        l = strlen(str);
        if (l>=2)  A();
        else
            printf("\nResult: Invalid String\n");

        if (f)
            printf("\nResult: Valid String\n");
        else
            printf("\nResult: Invalid String\n");
	}
    return 0;
}

void A() {
    if(l==2 && str[0]=='a'&& str[1]=='d'){
            f=1; return;
    }
    else if(l>2 && str[0]=='a'&& str[l-1]=='d'){
        i++;
        X();
    }
    return;
}

void X() {
    if(i<(l-2)){
        if (str[i] == 'b'&& str[i+1] == 'b'){
            i=i+2;
            X();
        }
        else if (str[i] == 'b'&& str[i+1] == 'c'){
            i=i+2;
            X();
        }
    }
    else if(i==(l-1)){f=1;return;}
    else{f=0;return;}
}
