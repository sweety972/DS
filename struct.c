#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int main()
{
    int i,n;
    n=0;
    struct node*temp,*head;
    head=malloc(sizeof(struct node*));
    head=0;
    while(n==0)
    {
        struct node*newnode=malloc(sizeof(struct node*));
        printf("enter your number");
        scanf("%d",&i);
        newnode->data=i;
        newnode->next=0;
        if(head==0)
        {
          head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
         printf("do you want to continue(0/1)");
        scanf("%d",&n);      
    }
    printf("linked list\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    
}