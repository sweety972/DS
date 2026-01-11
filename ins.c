#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main()
{
    int n,i;
    struct node*head ,*temp;
    head=malloc(sizeof(struct node));
    head=NULL;
    do{
    struct node*newnode=malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL){   
    head=newnode;
    temp=newnode;
    }
    else{
    temp->next=newnode;
    temp=newnode;
    }
    printf("do you want to continue?(0,1)");
    scanf("%d",&n);
 } while(n!=1);
 temp=head;
 while(temp!=NULL){   
    printf("%d",temp->data,"\n");
    temp=temp->next;
 }

}