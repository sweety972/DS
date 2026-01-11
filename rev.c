#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[50];
    struct node*next;
    struct node*prev;
};
struct node*head=NULL;
struct node*createnode(char value[]){
struct node*newnode=malloc(sizeof(struct node));
    strcpy(newnode->data,value);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct node*insertatend(char value[]){
    struct node*newnode=createnode(value);
    struct node*temp=head;
    if(head==NULL){
        head=newnode;
        return head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp; 
    return head;  
}
void display(){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%s",temp->data);
        temp=temp->next;
    }
}
struct node*rev(){
    struct node*cur=head;
    struct node*temp=NULL;
    while(cur!=NULL){
        temp=cur->prev;
        cur->prev=cur->next;
        cur->next=temp;
        cur=cur->prev;
    }
    if(temp!=NULL){
        head=temp->prev;
    }
}
int main(){
    int n;
    char name[50];
    printf("enter number of string");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("enter the string");
        scanf("%s",&name);
        insertatend(name);
    }
    rev();
    display();
}