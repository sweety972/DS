#include<stdio.h>
#define MAX 10
int rear=-1;
int front=0;
int queue[MAX];
int enqueue(int value){
    if(rear==MAX-1){
        printf("overflow");
    }
    rear++;
    queue[rear]=value;
}
void dequeue(){
    if(front==-1){
        printf("underflow");
    }
    printf("popped %d\n",queue[front]);
    front++;
}
int main(){
    enqueue(20);
     enqueue(80);
      enqueue(90);
      dequeue();
      for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
      }
      
}