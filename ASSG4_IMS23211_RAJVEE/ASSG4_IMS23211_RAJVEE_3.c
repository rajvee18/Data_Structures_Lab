#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


typedef struct 
{
    int items[MAX];
    int top;
} Stack;


void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s) 
{
    return s->top == -1;
}

void push(Stack *s, int val) 
{
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = val;
    }
}

int pop(Stack *s) 
{
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return 0; 
}


int EvaluatePostfix(char *postfix) 
{
    Stack s;
    init(&s);
    char *token = strtok(postfix, " ");
    
    while (token != NULL) {
        if (isdigit(token[0])) { 
            push(&s, atoi(token));
        } else { // Operator
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (token[0]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break; 
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}

int main() {
    char postfix[MAX];
    fgets(postfix, MAX, stdin); 
    postfix[strcspn(postfix, "\n")] = 0;
    printf("%d\n", EvaluatePostfix(postfix));
    return 0;
}