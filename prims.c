#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int visited[MAX]={0};
int adj[MAX][MAX];
int main(){
    int n,start,i,j,cost,e;
    printf("enter the number of nodes");
    scanf("%d",&n);
    printf("enter to start{0 to%d}",n-1);
    scanf("%d",&start);
    printf("enter the adjacency");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0 && i!=j){
            adj[i][j]=INT_MAX;
        }
        }
        
    }
    e=0,cost=0;
    visited[start]=1;
    while(e<n-1){
        int min=INT_MAX;
        int u=-1,v=-1;
        for(i=0;i<n;i++){
            if(visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j] && adj[i][j]<min){
                        min=adj[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            
        }
        visited[v]=1;
            printf("edges {%d,%d}=%d\n",u,v,min);
            cost+=min;
            e++;
        
    }
    printf("cost %d",cost);
        return 0;


}
