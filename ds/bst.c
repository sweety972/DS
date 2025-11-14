#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createnode(int value){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node*insert(int value,struct node*root){
    if(root==NULL){
        root=createnode(value);
        return root;
    }
    if(root->data>value){
      root->left=insert(value,root->left);
    }
    if(root->data<value){
        root->right=insert(value,root->right);
    }
    return root;
}
struct node*inordersuccessor(struct node*root){
    struct node*temp=root;
    while(temp!=NULL && temp->left!=NULL){
     temp=temp->left;
    }
    return temp;
}
struct node*delete(struct node*root, int value){
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
            free (root);
            return NULL;
        }
    
    if(root->left==NULL){
        struct node*temp=root->right;
        free(root);
        return temp;
    }
    if(root->right==NULL){
        struct node*temp=root->left;
        free(root);
        return temp;
    }
    else{
        struct node*temp=inordersuccessor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
     
    }
    }
    return root;
    }
    void inorderTraversal(struct node*root){
        if(root==NULL){
            return;
        }
        inorderTraversal(root->left);
        printf("%d",root->data);
        inorderTraversal(root->right);
    }
    void preorder(struct node*root){
        if(root==NULL){
            return;
        }
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(struct node*root){
        if(root==NULL){
            return;
         }
         postorder(root->left);
         postorder(root->right);
         printf("%d",root->data);
    }
    struct node*search(int value,struct node*root){
        if(root==NULL){
            printf("element does not exist....");
            return NULL;
        }
        if(root->data==value){
            printf("element exist...");
        }
        if(root->data>value){
            search(value,root->left);
        }
        if(root->data<value){
            search(value,root->right);
        }
    }

int main(){
    struct node*root=NULL;
    root=insert(30,root);
    root=insert(25,root);
    root=insert(23,root);
    root=insert(34,root);
    inorderTraversal(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    search(34,root);
    root=delete(root,30);
    inorderTraversal(root);
}