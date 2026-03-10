#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node* create_node(int k)
{
    struct node *x = (struct node*)malloc(sizeof(struct node));
    x->key = k;
    x->next = NULL;
    x->prev = NULL;
    return x;
}


struct node* list_search(int k)
{
    struct node *temp = head;

    while(temp != NULL){
        if(temp->key == k)
            return temp;
        temp = temp->next;
    }

    return NULL;
}


void insert_front(struct node *x)
{

    if(head == NULL){
        head = x;
        return;
    }

    x->next = head;
    head->prev = x;
    head = x;
}


void insert_tail(struct node *x)
{

    if(head == NULL){
        head = x;
        return;
    }

    struct node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = x;
    x->prev = temp;
}


void insert_after(struct node *x, int y)
{

    struct node *p = list_search(y);

    if(p == NULL)
        return;

    x->next = p->next;
    x->prev = p;

    if(p->next != NULL)
        p->next->prev = x;

    p->next = x;
}


void insert_before(struct node *x, int y)
{

    struct node *p = list_search(y);

    if(p == NULL)
        return;

    if(p == head){
        x->next = head;
        head->prev = x;
        head = x;
        return;
    }

    x->next = p;
    x->prev = p->prev;

    p->prev->next = x;
    p->prev = x;
}

void delete_node(int k)
{

    struct node *x = list_search(k);

    if(x == NULL){
        printf("-1\n");
        return;
    }

    if(x == head){
        head = x->next;
        if(head != NULL)
            head->prev = NULL;
    }

    else{
        x->prev->next = x->next;

        if(x->next != NULL)
            x->next->prev = x->prev;
    }

    printf("%d\n", x->key);
    free(x);
}


void delete_initial()
{

    if(head == NULL){
        printf("-1\n");
        return;
    }

    struct node *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("%d\n", temp->key);
    free(temp);
}


void delete_last()
{

    if(head == NULL){
        printf("-1\n");
        return;
    }

    struct node *temp = head;

    if(temp->next == NULL){
        printf("%d\n", temp->key);
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    printf("%d\n", temp->key);
    free(temp);
}

int main(){

    char ch;
    int x, y;

    while(1){

        scanf(" %c", &ch);

        if(ch == 'f'){
            scanf("%d", &x);
            insert_front(create_node(x));
        }

        else if(ch == 't'){
            scanf("%d", &x);
            insert_tail(create_node(x));
        }

        else if(ch == 'a'){
            scanf("%d %d", &x, &y);
            insert_after(create_node(x), y);
        }

        else if(ch == 'b'){
            scanf("%d %d", &x, &y);
            insert_before(create_node(x), y);
        }

        else if(ch == 'd'){
            scanf("%d", &x);
            delete_node(x);
        }

        else if(ch == 'i'){
            delete_initial();
        }

        else if(ch == 'l'){
            delete_last();
        }

        else if(ch == 's'){
            scanf("%d", &x);

            if(list_search(x) != NULL)
                printf("1\n");
            else
                printf("-1\n");
        }

        else if(ch == 'e'){
            break;
        }
    }

    return 0;
}