#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*createnode(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;
    return newnode;
}
void display(struct node*ptr){
    struct node*temp;
    temp=ptr;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
struct node*insertatbeg(int value){
    struct node*newnode=createnode(value);
    newnode->next=head;
    head=newnode;
    return head;
}
struct node*insertatend(int value){
    struct node*newnode=createnode(value);
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return newnode;
}
struct node*insertatpos(int pos,int value){
    struct node*newnode=createnode(value);
    struct node*temp=head;
    int i=1;
    if(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node*deleteatfirst(){
    struct node*temp=head;
    head=temp->next;
    free(temp);
    return head;
}
struct node*deleteatend(){
    struct node*temp=head;
    struct node*prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return head;
}
struct node*deleteatpos(int pos){
    struct node*temp=head;
    struct node*prev=NULL;
    int i=1;
    while(i<pos){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
    return head;
    
}
struct node*search(int value){
    struct node*temp=head;
    int i=1;
    while(temp!=NULL){
    if(temp->data==value){
        printf("found");
        return head;
    }
    temp=temp->next;
    i++;
}
printf("not found");
}
struct node*rev(){
    struct node*prev=NULL;
    struct node*next=NULL;
    struct node*cur=head;
    while(cur!=NULL){
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
        
    }
    head=prev;
    return head;
}
struct node*sort(){
    struct node*ptr;
    int swapped;
    do{
    swapped=0;
    ptr=head;
    while(ptr->next!=NULL){
        if(ptr->data>ptr->next->data){
        int temp=ptr->data;
        ptr->data=ptr->next->data;
        ptr->next->data=temp;
        swapped=1;
    }
    ptr=ptr->next;
}
}while(swapped);
return head;
}
int main()
{
    struct node*head=NULL;
    head=insertatbeg(23);
    head=insertatbeg(67);
    head=insertatbeg(66);
    head=insertatend(56);
    head=insertatpos(2,90);
    
    head=search(90);
    head=rev();
    display(head);
    sort();
    head=rev();
    display(head);
}