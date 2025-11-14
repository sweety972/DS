#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node*next;
    struct node*tail;
};
struct node*creatnode(int value){
    struct node*newnode=malloc(sizeof(struct node*));
    newnode->data=value;
    newnode->next=  NULL;
    return newnode;
}
struct node*insertatbeg(int value,struct node*tail){
    struct node*newnode=creatnode(value);
    if(tail==NULL){
        tail=newnode;
           tail->next=newnode;
            
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
        }
       
        return tail;

}
struct node*insertatend(int value,struct node*tail){
struct node*newnode=creatnode(value);
if(tail==NULL){
    newnode=newnode->next;
    tail=newnode;
}
else{
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}

return tail;
}
struct node*insertatpos(int pos,int value,struct node*tail){
    struct node*newnode=creatnode(value);
    struct node*temp=tail->next;
    int i=1;
    if(pos<0){
        printf("invalid pos");
    }
    else if(pos==1){
        insertatbeg(value,tail);
    }
    else{
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return tail;

}
void display(struct node*tail){
    if(tail==NULL){
        printf("empty");
        return;
    }
    else{
        struct node*temp=tail->next;
                do{
            printf("%d",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
}
struct node*deleteatbeg(struct node*tail){
   struct node*temp=tail->next;
   if(tail==NULL){
    printf("list is empty");
    return tail;
   }
    else if(temp==tail){
      free(temp);
      tail=NULL;
    }
    else{
        tail->next=temp->next;
        free(temp);
    }
    return tail;
    
}
struct node*deleteatend(struct node*tail){
    struct node*previous;
    struct node*temp=tail->next;
    if(tail==NULL){
        printf("empty");
        return tail;
    }
    else if(tail==temp){
        temp=0;
        free(temp);
    }
    else{
        while(temp->next!=tail->next){
            previous=temp;
            temp=temp->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(temp);
        
    }
    return tail;
    
}
struct node*deleteatpos(int pos,struct node*tail){
    struct node*temp=tail->next;
    struct node*nextnode;
    int i;
    if(pos<0){
        printf("invalid");
    }
    if(pos==1){
        deleteatbeg(tail);
    }
    else{
        while(i>pos){
            temp=temp->next;
            i++;
       }
       nextnode=temp->next;
       temp->next=nextnode->next;
       free(nextnode);  
      }
      return tail;
}
void search(int value,struct node*tail){
    struct node*temp=tail->next;
    if(tail==NULL){
        printf("dont exist");
        return;
    }
    int pos=1;
    do{
    if(temp->data==value){
        printf("value of is",pos);
        return;
    }
    temp=temp->next;
    pos++;
    }while(temp!=tail->next);
    printf("not found",pos);
}
struct node*reverse(struct node*tail){
    
    if(tail==NULL){
        printf("tail is empty");
        return tail;
    }
    struct node*prev=tail;
    struct node*current=tail->next;
    struct node*nextnode;
    struct node*head=tail->next;
    do{
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
        
    }while(current!=tail->next);
    head->next=prev;
    tail=head;
    return tail;
}




int main()
{
    struct node*tail=NULL;
    tail=insertatbeg(23,tail);
     tail=insertatbeg(20,tail);
      tail=insertatbeg(19,tail);
      tail=insertatend(45,tail);
      tail=insertatbeg(34,tail);
      tail=insertatpos(2,56,tail);
      tail=deleteatbeg(tail);
      tail=deleteatend(tail);
      tail=deleteatpos(2,tail);
      search(20,tail);
      search(21,tail);
      tail=reverse(tail);
      display(tail);
      

}