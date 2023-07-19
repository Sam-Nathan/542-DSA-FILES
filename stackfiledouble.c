#include<stdio.h>
#include<stdlib.h>
#define max_size 1000
#define MAX 10
typedef struct stack
{
    int data[MAX];
    int top;
}stack;a;

void push(stack *s);
int pop(stack *s);

int main()
{
    stack *s=&a;
    int ch;
    s->top=-1;
    FILE *fp;
    int m;
    int arr[max_size],i,j,temp,size=0;
    fp = fopen("double.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;
        pop(s);
    }
    fclose(fp);

    fp = fopen("output.txt","w");

    for(i=0;i<size;i++)
    {   m=2*arr[i];
        fprintf(fp,"%d\n",m);
        push(s);
    }
    fclose(fp);
    return 0;
}

void push(stack *s)
{
    if(s->top<MAX-1)
    {
        s->top++;
    }
    else

    {
        printf("stack overflow");
    }
}

int pop(stack *s)
{
    if(s->top==-1)
    {
        printf("Poped\n");

    }
    else
    {
        int temp;
        temp=s->data[s->top];
        s->top--;
        return temp;
    }
}

