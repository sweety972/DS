#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*top=NULL;
struct node*push(int value){
struct node*newnode=malloc(sizeof(struct node));
newnode->data=value;
newnode->next=top;
top=newnode;
// printf("%d",value);
}
struct node*pop(){
    if(top==NULL){
        return NULL;
    }
    struct node*temp=top;
    int value=temp->data;
    top=top->next;
    free(temp);
    
    
}
struct node*peek(){
    if(top==NULL){
        printf("empty");
    }
    else{
        printf("top elements is %d",top->data);
    }
}
struct node*display(){
    struct node*temp=top;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }

}
int main(){
    struct node*top=NULL;
    top=push(20);
    top=push(40);
    top=pop();
    display();

}
