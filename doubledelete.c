#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*previous;
};
struct node* createnode(int value){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->previous=NULL;
    newnode->next=NULL;
    return newnode;
}
struct node*insertatend(int value,struct node*head){
    struct node*temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node*temp2=createnode(value);
    temp->next=temp2;
    temp2->previous=temp;
    return head;
}

void display(struct node*head){
    struct node*temp;
    temp=head;
    printf("\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}
struct node*deleteatfirst(struct node*head){
head=head->next;
free(head->previous);
head->previous=NULL;
return head;
}
struct node*deleteatend(struct node*head){
    struct node*temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->previous->next=NULL;
    free(temp);
    return head;
}
struct node*deleteatposition(int position,struct node*head){
int i=1;
struct node*temp=head;
while(i<position){
temp=temp->next;
i++;
}
temp->previous->next=temp->next;
temp->next->previous=temp->previous;
free(temp);
return head;
}
struct node*insertatposition(int value,struct node*head,int position){
   int i=1;
   struct node*temp=head;
   while(i<position-1 &&temp!=NULL){
    temp=temp->next;
    i++;
   }
   struct node*temp2=createnode(value);
   temp2->previous=temp;
   temp2->next=temp->next;
   temp->next->previous=temp2;
   temp->next=temp2;
   return head;
}
struct node*insertatstart(int value,struct node*head){
    struct node*temp;
    temp=createnode(value);
    temp->next=head;
    head->previous=temp;
    head=temp;
    return head;
    
}

int main(){
    struct node*head;
    head=createnode(45);
    head=insertatend(4,head);
    head=insertatend(5,head);
    head=insertatend(6,head);
    head=insertatend(7,head);
    head=insertatend(8,head);
    head=insertatend(9,head);
    head=insertatend(15,head);
    display(head);
    head=insertatstart(34,head);
    display(head);
    head=insertatposition(89,head,5);
    display(head);
    head=deleteatfirst(head);
    display(head);
    head=deleteatend(head);
    display(head);
    head=deleteatposition(3,head);
    display(head);
}
