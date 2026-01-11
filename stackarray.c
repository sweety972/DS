#include<stdio.h>
#define MAX 5
int top=-1;
int stack[MAX];
int push(int value){
    if(top==MAX-1){
        printf("overflow");
    }
    top++;
    stack[top]=value;
}
void pop(){
    if(top==-1){
        printf("underflow");
    }
    printf("popped %d\n",stack[top]);
    top--;
}
int main(){
    push(20);
     push(80);
      push(90);
      pop();
      for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
      }
      printf("top element %d",stack[top]);
}