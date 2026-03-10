#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Stack {
    int top;
    char *A;
    int capacity;
};

int StackEmpty(struct Stack *S) {
    return (S->top == -1);
}

int StackFull(struct Stack *S) {
    return (S->top == S->capacity - 1);
}

void Push(struct Stack *S, char k) {
    if (StackFull(S)) {
        return;   
    }
    S->top++;
    S->A[S->top] = k;
}

void Pop(struct Stack *S) {
    if (StackEmpty(S)) {
        printf("-1\n");
        return;
    }
    printf("%d\n", S->A[S->top]);
    S->top--;
}

void CheckEmpty(struct Stack *S) {
    if (StackEmpty(S))
        printf("-1\n");
    else
        printf("1\n");
}


void IsPalindrome(char *str)
{
    
    char newArr[100];
    int n,i;
    int count=strlen(str);
    

    struct Stack S;
    S.capacity = count;
    S.top = -1;
    S.A = (char*)malloc(count * sizeof(char));

    for(i=0;i<count;i++)
    {
        Push(&S,str[i]);
    }

    for(i=0;i<count;i++)
    {
        newArr[i]= S.A[S.top];
        S.top--;
    }

    newArr[count]='\0';

    int result = (strcmp(str, newArr) == 0);
    free(S.A);
    

    if (result) printf("1");
    else printf("0");

}

int main() {
    int n;
    char str[100];
    
    scanf("%s",&str);

    IsPalindrome(str);

    return 0;
}