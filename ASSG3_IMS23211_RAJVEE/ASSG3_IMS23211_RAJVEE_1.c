#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

struct Node* createNode(int k) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return NULL;
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, int k) {
    struct Node* newNode = createNode(k);
    if (!newNode) return;
    newNode->next = *head;
    *head = newNode;
}

void insertTail(struct Node** head, int k) {
    struct Node* newNode = createNode(k);
    if (!newNode) return;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

struct Node* search(struct Node* head, int k) {
    while (head) {
        if (head->key == k) return head;
        head = head->next;
    }
    return NULL;
}

void insertAfter(struct Node** head, int k, int y) {
    struct Node* yNode = search(*head, y);
    if (!yNode) return;
    struct Node* newNode = createNode(k);
    if (!newNode) return;
    newNode->next = yNode->next;
    yNode->next = newNode;
}

void insertBefore(struct Node** head, int k, int y) {
    if (*head == NULL) return;
    if ((*head)->key == y) {
        insertFront(head, k);
        return;
    }
    struct Node* temp = *head;
    while (temp->next && temp->next->key != y) temp = temp->next;
    if (!temp->next) return;
    struct Node* newNode = createNode(k);
    if (!newNode) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int k) {
    if (*head == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = *head, *prev = NULL;
    if (temp->key == k) {
        *head = temp->next;
        printf("%d\n", temp->key);
        free(temp);
        return;
    }
    while (temp && temp->key != k) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("-1\n");
        return;
    }
    prev->next = temp->next;
    printf("%d\n", temp->key);
    free(temp);
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("%d\n", temp->key);
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = *head, *prev = NULL;
    if (!temp->next) {
        printf("%d\n", temp->key);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d\n", temp->key);
    free(temp);
    prev->next = NULL;
}

void searchKey(struct Node* head, int k) {
    printf("%d\n", search(head, k) ? 1 : -1);
}

int main() {
    struct Node* head = NULL;
    char cmd;
    int x, y;
    while (scanf(" %c", &cmd) != EOF) {
        switch (cmd) {
            case 'f': scanf("%d", &x); insertFront(&head, x); break;
            case 't': scanf("%d", &x); insertTail(&head, x); break;
            case 'a': scanf("%d %d", &x, &y); insertAfter(&head, x, y); break;
            case 'b': scanf("%d %d", &x, &y); insertBefore(&head, x, y); break;
            case 'd': scanf("%d", &x); deleteNode(&head, x); break;
            case 'i': deleteFirst(&head); break;
            case 'l': deleteLast(&head); break;
            case 's': scanf("%d", &x); searchKey(head, x); break;
            case 'e': return 0;
        }
    }
    return 0;
}