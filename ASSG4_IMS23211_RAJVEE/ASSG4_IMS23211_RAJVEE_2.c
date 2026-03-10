#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int top;
    char A[MAX];
};

void push(struct Stack *S, char x)
{
    S->A[++S->top] = x;
}

char pop(struct Stack *S)
{
    return S->A[S->top--];
}

char peek(struct Stack *S)
{
    return S->A[S->top];
}

int isEmpty(struct Stack *S)
{
    return S->top == -1;
}

int precedence(char x)
{
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    if(x == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack S;
    S.top = -1;

    int i = 0, k = 0;
    char x;

    while((x = infix[i]) != '\0')
    {
        if(isalnum(x)) //check if it is operand or not, (comes under ctype.h)
        {
            postfix[k++] = x;
        }

        else if(x == '(')
        {
            push(&S, x);
        }

        else if(x == ')')
        {
            while(peek(&S) != '(')
            {
                postfix[k++] = pop(&S);
            }
            pop(&S);
        }

        else // operator
        {
            while(!isEmpty(&S) && precedence(peek(&S)) >= precedence(x))
            {
                postfix[k++] = pop(&S);
            }
            push(&S, x);
        }

        i++;
    }

    while(!isEmpty(&S))
    {
        postfix[k++] = pop(&S);
    }

    postfix[k] = '\0';

    printf("%s\n", postfix);
}

int main()
{
    char infix[100], postfix[100];

    
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    

    return 0;
}