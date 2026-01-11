#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*rear=NULL;
struct node*front=NULL;
void enqueue(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(rear==NULL){
        rear=front=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        
    }
}
int dequeue(){
    struct node*temp=front;
    if(front==NULL){
        printf("underflow");
    }
    else{
    int value=temp->data;
    front=front->next;
    free(temp);
    return value;
    }

}
struct node*display(){
    struct node*temp=front;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
struct node*peek(){
    if(front==NULL){
        printf("empty");
    }
    else{
        printf("top element is %d",front->data);
    }
    
}
int main(){
    enqueue(20);
    enqueue(70);
    
    peek();
    display();

}