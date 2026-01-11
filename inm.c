#include<stdio.h>
#include<stdlib.h>
int n,i,count=1,pos,ch;
struct node{
    int data;
    struct node*next;
};
struct node*newnode ,*head,*temp,*nnode;
struct node* createnode(){
  newnode=malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
    }
struct node *insAtBeg(){
     if(head==NULL){   
    head=newnode;
    temp=newnode;
    }
    else{
    newnode->next=head;
    head=newnode;
    
    }
}
int main()
{
    head=malloc(sizeof(struct node));
    head=NULL;
    
do{
    printf("\n1.insert at beg\n2.insert at middle\n3.display\n4.exit\n5.insert at end\nenter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            nnode=createnode();
            insAtBeg();
            break;
        }
        case 2:{
            printf("enter your position");
            scanf("%d",&pos);
            temp=head;
            while(count!=pos-1){
                count++;
                temp=temp->next;
            }
            nnode=createnode();
            nnode->next=temp->next;
            temp->next=nnode;
            break;
        }
        case 3:{
            temp=head;
            while(temp!=NULL){   
            printf("%d\n",temp->data);
            temp=temp->next;
            }
            break;
        }
        case 4:
        printf("exited");
        break;
        default:
        printf("invalid");
        case 5:{
            nnode=createnode();
            if(head==NULL){   
    head=nnode;
    temp=nnode;
    }
    else{
    temp->next=nnode;
    temp=nnode;
    }
            
            
            }
        }

    
   
 


} while(ch!=4);
}