#include<bits/stdc++.h>
using namespace std;
vector<string>v;
vector<string>v1,v2,global,che;
struct node{
  string str;
  int line;
}array1[100010];
int vary=0;
string str1[100010]={"return","{","}","(",")","if","else","int","float","double","=",",",";","+","-","*","<","main","void"};
bool check(string str)
{
    int count1=0;
    int x=(int)str[0];
    if(x!=0) return true;
    else return false;
}
bool cmp(node A,node B)
{
    return A.line<B.line;
}
void id()
{
    for(int i=0;i<v1.size();i++)
    {
        int t1=0,t=0,count1=0;
        for(int j=0;j<19;j++){
            if(str1[j]==v1[i]) t=1;
        }
        for(int j=0;j<v1[i].size();j++){
            if(isdigit(v1[i][j])) count1++;
            if(v1[i][j]=='.' && t1==0){ count1++; t1=1;}
        }
        if(t==0 && count1!=v1[i].size() && v1[i]!="true"){
            v2.push_back(v1[i]);
        }
    }
    cout<<1;
    for(int i=0,j=2;i<v1.size();i++)
    {
        if(v1[i]=="true"){
            cout<<endl;
            cout<<j<<"  ";
            j++;
            continue;
        }
        for(int k=0;k<v2.size();k++)
        {
            if(v2[k]==v1[i]){
                cout<<"id ";
                break;
            }
        }
        cout<<v1[i]<<" ";
    }
    cout<<endl<<endl<<endl;
}
void Duplicate()
{
    int count1=1;
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]=="true"){
            count1++;
            continue;
        }
        if(v1[i]=="{" || v1[i]=="}") continue;
        string s=v1[i];
        if(v1[i]==s){
            i++;
            int t=0;
            while(v1[i]==s){
                if(t==0){
                    array1[vary].str="Duplicate Line at";
                    array1[vary].line=count1;
                    vary++;
                    t=1;
                }
                i++;
            }
            i--;
        }
    }
}
void if_else()
{
   int count1=1,count2=0;
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]=="true"){
            count1++;
            continue;
        }
        if(v1[i]=="if") count2++;
        else if(v1[i]=="else") count2--;
        if(count2<0){
            array1[vary].str="Unmatched else,if at";
            array1[vary].line=count1;
            vary++;
            count2=0;
        }
    }
}
void Bracket()
{
    int count1=1,count2=0,c=-1,count3=0,c1=-1;
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]=="true"){
            count1++;
            continue;
        }
        if(v1[i]=="("){
            count2++;
            c=count1;
        }
        else if(v1[i]==")"){
            count2--;
            c=count1;
        }
        if(v1[i]=="{"){
            count3++;
            c1=count1;
        }
        else if(v1[i]=="}"){
            count3--;
            c1=count1;
        }
        if(count2<0){
            array1[vary].str="Unmatched brackets at";
            array1[vary].line=c;
            vary++;
            count2=0;
        }
        if(count3<0){
            array1[vary].str="Unmatched brackets at";
            array1[vary].line=c1;
            vary++;
            count3=0;
        }
    }
    if(count2>0){
        array1[vary].str="Unmatched brackets at";
        array1[vary].line=c;
        vary++;
        count2=0;
    }
    if(count3>0){
        array1[vary].str="Unmatched brackets at";
        array1[vary].line=c1;
        vary++;
        count3=0;
    }
}

int main()
{
    string str;
    while(getline(cin,str)){
        if(str=="ok")
            break;
        v.push_back(str);
    }
    cout<<endl<<endl;
    for(int i=0;i<v.size();i++)
    {
        string str1="";
        int t=0;
        for(int j=0;j<v[i].size();j++)
        {
            if(t==1) continue;
            if(v[i][j]=='*' && v[i][j+1]=='/'){
                t=0;
                j++;
                continue;
            }
            if(v[i][j]=='/' && v[i][j+1]=='/') break;
            if(v[i][j]=='/' && v[i][j+1]=='*'){t=1; continue;}
            if(v[i][j]==' '){
              if(check(str1)) v1.push_back(str1);
              str1="";
            }
            else if(v[i][j]==','){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(",");
                str1="";
            }
            else if(v[i][j]==';'){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(";");
                str1="";
            }
            else if(v[i][j]=='('){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back("(");
                str1="";
            }
            else if(v[i][j]==')'){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(")");
                str1="";
            }
            else if(v[i][j]=='{'){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back("{");
                str1="";
            }
            else if(v[i][j]=='}'){
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back("}");
                str1="";
            }
            else if(v[i][j]=='<'){
                string p="<";
                int k=j+1;
                if(j+1<v[i].size()){
                    if(v[i][k]=='='){
                        p+="=";
                        j++;
                    }
                    else if(v[i][k]=='<'){
                        p+="<";
                        j++;
                    }
                }
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else if(v[i][j]=='>'){
                string p="=";
                int k=j+1;
                if(j+1<v[i].size()){
                    if(v[i][k]=='='){
                        p+="=";
                        j++;
                    }
                    else if(v[i][k]=='>'){
                        p+=">";
                        j++;
                    }
                }
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else if(v[i][j]=='='){
                string p="=";
                int k=j+1;
                if(j+1<v[i].size()){
                    if(v[i][k]=='='){
                        p+="=";
                        j++;
                    }
                }
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else if(v[i][j]=='*'){
                string p="*";
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else if(v[i][j]=='+'){
                string p="+";
                int k=j+1;
                if(j+1<v[i].size()){
                    if(v[i][k]=='+'){
                        p+="+";
                        j++;
                    }
                    else if(v[i][k]=='='){
                        p+="=";
                        j++;
                    }
                }
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else if(v[i][j]=='-'){
                string p="-";
                int k=j+1;
                if(j+1<v[i].size()){
                    if(v[i][k]=='-'){
                        p+="-";
                        j++;
                    }
                    else if(v[i][k]=='='){
                        p+="=";
                        j++;
                    }
                }
                if(check(str1)){
                    v1.push_back(str1);
                }
                v1.push_back(p);
                str1="";
            }
            else{
              str1+=v[i][j];
            }
        }
        if(str1!=""){
            v1.push_back(str1);
        }
        v1.push_back("true");
    }
    id();
    Duplicate();
    if_else();
    Bracket();
    sort(array1,array1+vary,cmp);
    for(int i=0;i<vary;i++)
    {
        cout<<array1[i].str<<" "<<array1[i].line<<endl;
    }
}
