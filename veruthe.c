#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
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
struct node*insertatbeg(struct node*head,int value){
    struct node*newnode=createnode(value);
    newnode->next=head;
    head=newnode;
    return head;
}int oddsum(struct node*head){
    if(head==NULL){
        return 0;
    }
    int sum=0;
    struct node*temp=head;
    
    while(temp!=NULL){
        if(temp->data%2!=0){
            sum+=temp->data;
        }
        temp=temp->next;
    }

    return sum;
}
int larnum(struct node*head){
    struct node*temp=head->next;
    int max=temp->data;
    while(temp!=NULL){
    if(temp->data>max){
        max=temp->data;
        temp=temp->next;
    }
}
    return max;
}
int main(){
    struct node*head=NULL;
    head=insertatbeg(head,56);
    head=insertatbeg(head,85);
    head=insertatbeg(head,23);
    int sum=oddsum(head);
    printf("sum of odd numbers %d",sum);
    int max=larnum(head);
    printf("largest number %d",larnum);
    display(head);


}
