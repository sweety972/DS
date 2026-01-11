#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,j,arr[100],value,pos,search,temp;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the elemnets to print at beginning");
    scanf("%d",&value);
    for(i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
        arr[0]=value;
        n++;
    
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("enter the value");
    scanf("%d",&value);
    printf("at pos");
    scanf("%d",&pos);
    for(i=n;i>=pos;i--){
        arr[i]=arr[i-1];
        
    }
    arr[pos]=value;
    n++;
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("insering at end");
    scanf("%d",&value);
    arr[n]=value;
    n++;
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("deleting from start");
    for(i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        
    }
    printf("enter to deleting at position");
    scanf("%d",&pos);
    for(i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
        

    }
    n--;
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        
    }
    n--;
    printf("elements");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        
    }
    printf("enter the element to search");
    scanf("%d",&search);
    for(i=0;i<n;i++){
    if(arr[i]==search){
        printf("found at position %d",i);
    }
    
    }
    for(i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;

    }
    printf("sorting element is");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    printf("sorted array is");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    
    }


    


