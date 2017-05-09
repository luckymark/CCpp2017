#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* append(Node *node, int data);
void display();
void reverse(Node *now, bool is_first);
int find(int data, bool use_last);

Node *head;

int main()
{
    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    Node *now = head;

    for(int i = 0; i < 15; ++i)
    {
        now = append(now, i);
    }
    now = append(now, 5);
    printf("%d\n", find(5, false));
    printf("%d\n", find(5, true));
    printf("%d\n", find(5, true));
    display();
    reverse(head->next, true);
    display();
    return 0;
}

Node* append(Node *node, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = node->next;
    node->next = new_node;
    return new_node;
}

void display()
{
    Node *now = head->next;
    do
    {
        printf("%d\n", now->data);
        now = now->next;
    }while(now != NULL);
}

void reverse(Node *now, bool is_first)
{
    if(now->next != NULL)
    {
        reverse(now->next, false);
    }
    else
    {
        head->next = now;
        return;
    }
    now->next->next = now;
    if(is_first)
    {
        now->next = NULL;
    }
}

int find(int data, bool use_last)
{
    static Node *now;
    static int count;
    if(!use_last)
    {
        now = head->next;
        count = 0;
    }
    else
    {
        ++count;
        now = now->next;
    }
    while(now != NULL && now->data != data)
    {
        ++count;
        now = now->next;
    }
    if(now != NULL && now->data == data)
    {
        return count;
    }
    else
    {
        return -1;
    }
}