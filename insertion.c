#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;

};
int main()

{
    int n,i;
struct node*head,*temp;

head= malloc(sizeof(struct node));
head=0;
do
{

struct node*newnode=malloc(sizeof(struct node));
printf("do you want to continue (0,1)");
scanf("%d",&n);
printf("enter the value");
scanf("%d",&i);
newnode->data=i;
newnode->next=0;

if(head==0)
{
    temp=newnode;
    head=newnode;

}
else{
    temp->next=newnode;
    temp=newnode;
}
}
while(n!=1);
printf("linked list\n");
temp = head;
while(temp != 0)
{
    printf("%d\n", temp -> data);
    temp = temp -> next;
}
}
