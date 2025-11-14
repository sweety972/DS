#include<stdio.h>
#define N 100
int queue[N];
int rear=-1;
int front=-1;
void enqueue(int x)
{
    if(rear==-1 && front==-1){
        rear=front=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("stack is full");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(rear==-1 && front==-1){
      printf("stack is empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else {
        printf("dequeue element is %d",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    if(rear==-1 && front==-1){
      printf("stack is empty");
    }
    printf("queue is");
    int i=front;
    while(i!=front){
        printf("%d",queue[i]);
        i=(i+1)%N;
    }
    printf("display",queue[rear]);

}
void main(){
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
}

