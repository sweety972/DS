#include<stdio.h>
int parent[10];
int find(int i){
while(parent[i]!=i){
    i=parent[i];
}
return i;
}
void unionset(int a,int b){
parent[a]=b;
}
int main(){
    int i,j,n;
    int adj[10][10];
    printf("enter the matrix");
    scanf("%d",&n);
    printf("enter the matrix");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0){
                adj[i][j]=__INT_MAX__;
            }
        }
    }
    for(i=0;i<n;i++){
        parent[i]=i;
    }
    int e=0,cost=0;
    while(e<n-1){
        int min=__INT_MAX__;
        int a=-1,b=-1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(adj[i][j]<min){
                    min=adj[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        int u=find(a);
        int v=find(b);
        if(u!=v){
            printf("%d-%d=%d",a,b,min);
            cost+=min;
            unionset(u,v);
            e++;
        }
        adj[a][b]=adj[b][a]=__INT_MAX__;

    }
    printf("cost=%d",cost);
}
