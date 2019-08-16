#include<stdio.h>
char a[10];
int top=-1;
void push(char i)
{
    a[++top]=i;
}
void pop()
{
    top--;
}
int check(char x[])
{
    int i;
    char sym;
    for(i=0;x[i]!='\0';i++)
    {
        sym=x[i];
        if(sym=='(' || sym=='{' || sym=='[')
        push(sym);
        else if(sym==')' )
        {
            if(a[top]=='(')
            pop();
            else return 0;
        }
        else if(sym=='}' )
        {
            if(a[top]=='{')
            pop();
            else return 0;
        }
        else if(sym==']' )
        {
            if(a[top]=='[')
            pop();
            else return 0;
        }
        if(top==-1)
        return 1;

    }
}
void main()
{
    char e[10];
    printf("Enter expression\n");
    scanf("%s",e);
    if(check(e))
    printf("Balanced\n");
    else
    printf("Unbalanced\n");
}
