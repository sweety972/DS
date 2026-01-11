#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL;
struct node*createnode(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;
    return newnode;
}
struct node*insertatbeg(int value){
    struct node*newnode=createnode(value);
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
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
    newnode->prev=temp;
    return head;
}
struct node*insertatpos(int value,int pos){
    struct node*newnode=createnode(value);
    struct node*temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
     newnode->prev=temp;
     newnode->next->prev=newnode;
    return head;
}
struct node*deleteatbeg(){
    struct node*temp=head;
    head=temp->next;
    free(temp);
    return head;
}
struct node*deleteatend(){
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}
struct node*deleteatpos(int pos){
    struct node*temp=head;
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return head;
}
struct node*search(int value){
    struct node*temp=head;
    int i=1;
    while(temp!=NULL){
        if(temp->data==value){
        printf("found\n");
        return head;
        }
        temp=temp->next;
       i++;
    }
    printf("not found\n");
    
}
struct node*rev(){
    struct node*next=NULL;
    struct node*prev=NULL;
    struct node*cur=head;
    struct node*temp=NULL;
    while(cur!=NULL){
        temp=cur->prev;
        cur->prev=cur->next;
        cur->next=temp;
        cur=cur->prev;
    }
    if(temp!=NULL)
    head=temp->prev;
    return head;
    
}
struct node*sort(){
    struct node*ptr;
    int swapped;
    do{
        ptr=head;
        swapped=0;
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
void display(struct node*ptr){
    struct node*temp;
    temp=ptr;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node*head;
    head=insertatbeg(2);
    head=insertatbeg(3);
    head=insertatbeg(4);
    head=insertatend(8);
    head=insertatpos(7,2);
    display(head);
    head=rev();
    display(head);

}
