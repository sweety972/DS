#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

/*struct node* createNode(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}*/

int main()
{
    struct node* head = NULL;

    struct node* first = (struct node*)malloc(sizeof(struct node));
    first -> data = 10;
    first -> next = NULL;
    head = first;

    struct node* second = (struct node*)malloc(sizeof(struct node));
    second -> data = 20;
    second -> next = NULL;
    first -> next = second;

    
    struct node* third = (struct node*)malloc(sizeof(struct node));
    third -> data = 30;
    third -> next = NULL;
    second -> next = third;

    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}