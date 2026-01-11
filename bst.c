#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createnode(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=value;
    return newnode;
}
struct node*insert(struct node*root,int value){
   if(root==NULL){
    root=createnode(value);
    return root;
   }
   if(root->data>value){
    root->left=insert(root->left,value);
   }
   if(root->data<value){
    root->right=insert(root->right,value);
   }
   return root;
}
struct node*inordersuccessor(struct node*root){
struct node*temp=root;
if(temp!=NULL && temp->left!=NULL){
    temp=temp->left;
}
return temp;
}
void inordertraversal(struct node*root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    printf("%d",root->data);
    inordertraversal(root->right);
}
void preordertraversal(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d",root->data);
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(struct node*root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    printf("%d",root->data);
}
struct node*delete(struct node*root,int value){
    if(root==NULL){
        return root;
    }
    if(root->data>value){
        root->left=delete(root->left,value);
        
    }
    if(root->data<value){
        root->right=delete(root->right,value);
        
    }
    if(root->data==value){
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node*temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node*temp=inordersuccessor(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);

        }
        return root;

    }
}
struct node*search(struct node*root,int value){
    if(root==NULL){
        printf("elements does not exist");
        return NULL;
    }
    if(root->data==value){
        printf("element exist");
    }
    if(root->data>value){
        search(root->left,value);
    }
    if(root->data<value){
        search(root->right,value);
    }
}
int main(){
    struct node*root=NULL;
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,70);
    postordertraversal(root);
    delete(root,40);
    preordertraversal(root);
    search(root,80);
}