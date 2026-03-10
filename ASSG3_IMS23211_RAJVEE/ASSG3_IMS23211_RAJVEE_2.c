#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int *A;
    int capacity;
};

int StackEmpty(struct Stack *S) {
    return (S->top == -1);
}

int StackFull(struct Stack *S) {
    return (S->top == S->capacity - 1);
}

void Push(struct Stack *S, int k) {
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

int main() {
    int n;
    
    if (scanf("%d", &n) != 1)
        return 0;

    struct Stack S;
    S.capacity = n;
    S.top = -1;
    S.A = (int*)malloc(n * sizeof(int));

    char cmd;
    int x;

    while (scanf(" %c", &cmd) != EOF) {
        if (cmd == 'i') {
            scanf("%d", &x);
            Push(&S, x);
        }
        else if (cmd == 'd') {
            Pop(&S);
        }
        else if (cmd == 'e') {
            CheckEmpty(&S);
        }
        else if (cmd == 't') {
            break;
        }
    }

    free(S.A);
    return 0;
}
