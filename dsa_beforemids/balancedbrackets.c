#include<stdio.h>
#include<string.h>
typedef struct Stack{
    char data[1000];
    int top;
} Stack;

void push(Stack* st,char d)
{
    st->top+=1;
    st->data[st->top]=d;
}

int isempty(Stack* st)
{
    if(st->top==-1)
        return 1;
    else
        return 0;
}

void pop(Stack* st)
{
    if(!isempty(st))
    {
        st->top-=1;
    }
    else
	printf("Cant pop");
}


char* isBalanced(char* s) {
    Stack sub;
    Stack* st=&sub;
    st->top=-1;
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
            {push(st,s[i]);}
        else{
            if(isempty(st))
                {return "NO";}
            if((s[i]=='}' && st->data[st->top]=='{' )|| (s[i]==']' && st->data[st->top]=='[' )||(s[i]==')' && (st->data[st->top]=='(')))
                {pop(st);}
	    else 
		return "NO";
    }}
    if(isempty(st))
        return "YES";
    else
        return "NO";

}

int main()
{
	char s[1000]=")}]([}((}}})[}])([}({){([}}](){{){){]{][]{}[)[][(][])([((([[)}[]{]))}{[)[})({{[)([)(}[)(]{(}(]}[][{)[}{]])(}){]]))[(][][{]{[)})]({)]))[[])(])([[({)";
	printf("%s",isBalanced(s));
	return 0;
}

