#include<stdio.h>
#include<stdlib.h>
#define max_size 1000
#define MAX 10
typedef struct node
{
    int a[100];
    int front;
    int rear;
}qu;s;
void enq(qu* p,int size);
void deq(qu* p,int x,int size);
int main()
{
FILE *fp;
int arr[max_size],size=0,i;
qu *p=&s;
int ch,x,y,n;
p->front=p->rear=-1;
fp = fopen("input.txt","r");
    while(fscanf(fp,"%d",&arr[size])!=EOF)
    {
        size++;
       deq(p,x,size);
    }
    fclose(fp);

    fp = fopen("output.txt","w");

    for(i=0;i<size;i++)
    {
        fprintf(fp,"%d\n",arr[i]);
       enq(p,size);
    }
    fclose(fp);
    return 0;

}
   void enq(qu*p,int size)
   {
       int m;
       if(p->rear==size-1)
       {
           printf("Overflow\n");
       }
       else if(p->front==-1 && p->rear==-1)
       {
           p->rear++;
           p->front++;


         p->a[p->rear]=m;
       }
       else
       {

         p->rear++;
         p->a[p->rear]=m;
       }
   }
   void deq(qu*p,int x,int size)
   {
       if(p->front==-1 && p->rear==-1)
    {
        printf("dequeued\n");
    }
    else if(p->front==p->rear)
    {
        x=p->a[p->front];
        p->front=-1;
        p->rear=-1;
         printf("Del=%d\n",x);
    }
    else
    {
        x=p->a[p->front];
        p->front++;
        printf("Del=%d\n",x);
    }
   }

