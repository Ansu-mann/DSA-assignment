#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#define max 30
char stack[max];
int top=-1;
bool is_Full(){
    if(top==max-1)
    return 1;
    else
    return 0;
}
bool is_Empty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(char ele){
    if(is_Full())
    printf("stack overflow");
    else
    stack[++top]=ele;
}
char pop(){
    char ele;
    if(is_Empty())
    printf("stack overflow");
    else
    ele=stack[top--];
    return ele;
}
int operate(char op){
    switch(op){
        case '^':
        case '*':
        case '%':
        case '/':
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
void postfix_Evaluation(char postfix[]){
    char ch,n;
    int i,op1,op2;
    for(i=0;postfix[i]!='\0';i++){
        ch=postfix[i];
        if(isdigit(ch))
        push(ch);
        else if(isalpha(ch)){
            printf("Enter the value:");
            scanf("%c",&n);
            push(n);
        }
        else if(operate(ch)){
            op2=pop()-48;
            op1=pop()-48;
            switch(ch){
                case '^':
                n=pow(op1,op2);
                push(n+48);
                break;
                case '*':
                n=op1*op2;
                push(n+48);
                break;
                case '/':
                n=op1/op2;
                push(n+48);
                break;
                case '%':
                n=op1%op2;
                push(n+48);
                break;
                case '+':
                n=op1+op2;
                push(n+48);
                break;
                case '-':
                n=op1-op2;
                push(n+48);
                break;
            }
        }
    }
    n=pop()-48;
    printf("The result of the postfix expression:%d",n);
}
int main(){
    char postfix[max];
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    postfix_Evaluation(postfix);
    return 0;
}
