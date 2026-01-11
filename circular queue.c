#include<stdio.h>
#define N 10
int queue[N];
int rear=-1;
int front=-1;
void enqueue(int x){
    if(rear==-1 && front==-1){
        rear=front=0;
        queue[rear]=x;
        
    }
    else if((rear+1)%N==front){
        printf("queue is full");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("stack is empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("dequed element is:%d\n",queue[front]);
        front=(front+1)%N;
    }

    }
    void display(){
        if(rear==-1 && front==-1){
            printf("empty");
        }
        else{
            
            printf("queue is");
            int i=front;
            while(i!=rear){
                printf("%d",queue[i]);
                i=(i+1)%N;

            }
            printf("%d\n",queue[rear]);
        }
    }
    void peek(){
        if(rear==-1 && front==-1){
            printf("empty");
        }
        printf("%d\n",queue[front]);

    }
    void main(){
        enqueue(23);
        enqueue(32);
        enqueue(43);
        enqueue(67);
        enqueue(56);
        display();
        dequeue();
        display();
        peek();

    }