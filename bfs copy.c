#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int vertex){
    if(front==-1){
        front=0;
    }
    queue[++rear]=vertex;
}
int dequeue(){
    if(rear==-1 || front>rear){
        return -1;
    }
    return queue[front++];
}
void bfs(int start){
    for (int i=0;i<n;i++){
        visited[i]=0;
    }
    enqueue(start);
    visited[start]=1;
    while(rear>=front){
        int current=dequeue();
        printf("%d",current);
        for(int i=0;i<n;i++){
            if(adj[current][i]==1 && !visited[i]){
               enqueue(i);
               visited[i]=1; 
            }
        }
    }
}
int main(){
    int start;
    printf("enter the number of matrix");
    scanf("%d",&n);
    printf("enter the adjacecny matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
    scanf("%d",&adj[i][j]);
        }
    }
    printf("enter to start");
        scanf("%d",&start);
        bfs(start);
        return 0;
    
}