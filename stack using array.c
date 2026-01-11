#include<stdio.h>
int max = 5;
int top=-1;
int stack[5];
int i;
void push(int value)
    {
        if(top == max - 1)
        {
            printf("Stack Overflow\n");
        }
        else
        {
            top++;
            stack[top]=value;
            printf("pushed %d\n", stack[top]);
        }
    }
    void pop()
    {
        if(top==-1)
        {
            printf("stack underflow");
        }
        else
        {
            printf("popped %d\n", stack[top]);
            top--;
        }
    }
    
int main()
{
    
   push(10);
   push(20);
   push(30);
   pop();
   push(40);
   printf("top element %d\n", stack[top]);
   for(i=0;i<max;i++)
    {
        printf("%d\n",stack[i]);
    }
   
}