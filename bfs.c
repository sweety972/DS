#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int top=-1;
int visited[MAX];
int stack[MAX];
int n;
void push(int start){
    if(top==-1){
        top++;
    }
        stack[top]=start; 
}
int pop(){
    if(top=-1){
        printf("underflow");
        return -1;
    }
    return stack[top--];
}
void dfs(int start){
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    push(start);
    printf("%d",start);
    visited[start]=1;
    while
}

