#include<stdio.h>

int queue[5];
int front = 0;
int rear = -1;
int max = 5;

void enqueue(int value)
{
    if(rear == max -1)
    {
        printf("Queue full\n");
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}
void dequeue()
{
    if(rear==front)
    {
        printf("underflow");
    }
    else
    {
        printf("dequeued value = %d\n",queue[front]);
        queue[front] = 0;
        front++;
    }
}

int main()
{
    int i;
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();
    enqueue(23);

    for(i = 0; i < max; i++)
    {
        printf("%d\n", queue[i]);
    }
}
