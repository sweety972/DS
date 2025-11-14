#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;
void push(int start){
    top++;
    stack[top]=start;
}
int pop(){
    return stack[top--];
}
void dfs(int start,int vertex){
    int flag=0;
    for(int i=0;i<vertex;i++){
        visited[i]=0;
    }
    push(start);
    printf("%d\t",start);
    visited[start]=1;
while(top!=-1){
    flag=0;
for(int i=0;i<vertex;i++){
    if(adj[start][i]==1 && !visited[i]){
        push(i);
        printf("%d\t",i);
        visited[i]=1;
        start=i;
        flag=1;
        break;
    }
}
    if(flag==0){
        pop();
        if(top!=-1){
          start=stack[top];
        }

    }
}
}
int main()
{
    int start,n;
    printf("enter the vertex");
    scanf("%d",&n);
    printf("enter the adjacency");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("enter the start");
        scanf("%d",&start);
        
    dfs(start,n);

}

