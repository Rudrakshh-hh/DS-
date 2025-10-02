// Infix to Postfix

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
int top=-1;
char stack[max];
void push(char ch){
    if(top==max-1){
        printf("Stack Overflow");
        exit(0);
    }
    stack[++top]=ch;
}
char pop(){
    if(top==-1){
        return '\0';
    }
    return stack[top--];
}
char peek(){
    if(top==-1){
        return '\0';
    }
    return stack[top];
}
int precedence(char ch){
    switch(ch){
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void infToPost(char* infix,char* postfix){
    int k=0;
    for(int i=0;infix[i]!='\0';i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch=='(')
            push(ch);
        else if(ch==')'){
            while(peek()!='(' && peek()!='\0')
                postfix[k++]=pop();
            pop();  // Pops out the ( bracket
        }
        else{
            while(precedence(peek())>=precedence(ch)&&peek()!='(')
                postfix[k++]=pop();
            push(ch);
        }
    }
    while(top!=-1)
        postfix[k++]=pop();
    postfix[k]='\0';
}

int main(){
    char infix[]="A+B-(C/D)/E",postfix[max];

    printf("Infix Expression-  %s",infix);

    infToPost(infix,postfix);
    printf("\nPostfix Expression-  %s",postfix);
    return 0;
}