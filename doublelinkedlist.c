#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*createnode(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;
    return newnode;
}
struct node*head;
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
    struct node*temp=head;
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
struct node*insertatpos(int pos,int value){
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
        return head;
    }
struct node*deleteatbeg(){
    struct node*temp=head;
    head=head->next;
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
        printf("found");
        return head;
    }
    temp=temp->next;
    i++;
    }
    printf("not found");

}
struct node*rev(){
    struct node*next=NULL;
    struct node*prev=NULL;
    struct node*temp=NULL;
    struct node*cur=head;
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
    int swapped;
    struct node*ptr;
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

int main(){
    struct node*head;
    head=insertatbeg(34);
     head=insertatbeg(44);
      head=insertatbeg(24);
       head=insertatbeg(94);
      
       head=rev();
       display(head);
       sort();
       head=rev();
       display(head);
       
}