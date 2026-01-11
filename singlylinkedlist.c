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
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
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
            printf("found\n");
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
    int swapped;
    struct node*ptr;
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
void display(struct node*ptr){
    struct node*temp;
    temp=ptr;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    int choice,pos,n;
    do{
    printf("enter the beggining of node to be inserted\n ");
    printf("inserted at end\n");
    printf("insert atposition\n");
    printf("enter the choice\n");
    printf("deleteatbg\n");
    printf("deleteatend\n");
    printf("deleteatpos\n");
    printf("sort\n");
    printf("rev\n");
    printf("search\n");
    printf("display\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("enter the number");
        scanf("%d",&n);
        insertatbeg(n);
        break;
        case 2:
        printf("enter the number");
        scanf("%d",&n);
        insertatend(n);
        break;
        case 3:
        printf("enter the number");
        scanf("%d",&n);
        printf("enter the position");
        scanf("%d",&pos);
        insertatpos(pos,n);
        break;
        case 4:
        display(head);
        break;
        case 5:
        deleteatbeg();
        break;
        case 6:
        deleteatend();
        break;
        case 7:
        printf("enter the position");
        scanf("%d",&pos);
        deleteatpos(pos);
        break;
        case 8:
        sort();
        break;
        case 9:
        rev();
        break;
        case 10:
        printf("enter the value to search");
        scanf("%d",&n);
        search(n);
        break;
        default:
        printf("invalid choice");
    }
    }while(choice!=11);
}