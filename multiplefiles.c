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
    int c, n;
    int u,t;
    s->top=-1;
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    int m;
    int arr[max_size],i,j,temp,size=0;
    fp = fopen("double.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;
    }
    fclose(fp);

    fp = fopen("input.txt","w");


    for(i=0;i<size;i++)
    {
        for (c = 1; c <= 10; c++)
    {
        arr[i] = rand()%100 + 1;
        fprintf(fp,"%d\n",arr[i]);

    }

    }

    fclose(fp);
    printf("input numbers:\n");
        for (c = 1; c <= 10; c++)
    {
        arr[i] = rand()%100 + 1;
        printf("%d\n",arr[i]);

    }
    while(1)
    {
        printf("1--push\n");
        printf("2--pop\n");
        printf("3--exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :
            push(&s);

        u++;
            break;
        case 2 :
            printf("poped element = %d\n",pop(&s));
        t++;
            break;
        case 3 :
    fp1 = fopen("pop.txt","w");
    for(i=0;i<t;i++)
    {
         pop(&s);
        fprintf(fp,"%d\n",arr[i]);

    }

    fp2 = fopen("push.txt","w");
    for(i=0;i<u;i++)
    { push(&s);
      fprintf(fp,"%d\n",arr[i]);

    }

            exit(0);
            break;
    }
    return 0;
}
}

void push (stack *s)
{

        s->top++;
        printf("enter the element to insert:\n");
        scanf("%d",&s->data[s->top]);




}

int pop(stack *s)
{
    int temp;
    if (s->top == -1)
    {
        printf("underflow\n");
        return ;
    }
    else
    {
        temp=s->data[s->top];

        s->top--;
        return temp;

    }

}
