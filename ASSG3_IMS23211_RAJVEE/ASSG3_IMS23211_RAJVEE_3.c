#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* CreateNode(int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void Push(Stack* S, int x) {
    Node* temp = CreateNode(x);
    temp->next = S->top;
    S->top = temp;
}

int StackEmpty(Stack* S) {
    if (S->top == NULL)
        return 1;
    else
        return 0;
}

int Pop(Stack* S) {
    if (StackEmpty(S))
        return -1;
    Node* temp = S->top;
    int value = temp->data;
    S->top = temp->next;
    free(temp);
    return value;
}

int main() {
    Stack S;
    S.top = NULL;
    char ch;
    int x;

    while (1) {
        scanf(" %c", &ch);

        if (ch == 'i') {
            scanf("%d", &x);
            Push(&S, x);
        }
        else if (ch == 'd') {
            printf("%d\n", Pop(&S));
        }
        else if (ch == 'e') {
            if (StackEmpty(&S))
                printf("-1\n");
            else
                printf("1\n");
        }
        else if (ch == 't') {
            break;
        }
    }

    return 0;
}
