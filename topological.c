#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
int stack[MAX];
int top=-1;
int adj[MAX][MAX];
int visited[MAX];
int n;
void push(int start){
    stack[++top]=start;
}
int pop(){
    return stack[top--];
}
void dfs(int v){
    visited[v]=true;
    for(int i=0;i<n;i++){
        if(adj[v][i] && !visited[i]){
            dfs(i);
    }
}   
push(v);
}
int main(){
    printf("enter the matrix");
    scanf("%d",&n);
    printf("enter the adjacency");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
    scanf("%d",&adj[i][j]);
        }    
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    while(top!=-1){
        printf("%d",pop());
    }
    return 0;

}