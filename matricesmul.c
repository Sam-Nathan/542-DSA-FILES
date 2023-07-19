#include<stdio.h>
void read (int a[][3]);
void display (int a[][3]);
void multiply(int b[][3],int c[][3],int d[][3]);

void main()
{
   int b[3][3],c[3][3];
   int d[3][3];
   printf("1st matrix:\n");
   read (b);
   printf("2nd matrix:\n");
   read (c);
   multiply(b,c,d);
   printf("product:\n");
   display(d);
}
void read (int a[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }

}
void display (int a[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }

}
void multiply(int b[][3],int c[][3],int d[][3])
{   int i,j,k,sum;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
            {
                sum=sum+(*(*(b+i)+k))*(*(*(c+k)+j));
            }
            *(*(d+i)+j)=sum;
        }
    }
}
