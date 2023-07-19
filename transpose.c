#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int arr[100][100],i,j,temp,r,c;
    fp = fopen("transpose.txt","r");
    scanf("%d",&r);
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
    while(fscanf(fp,"%d",&arr[i][j])!=EOF)
    {
        r++;
        c++;
    }
        }
    }
    fclose(fp);

    fp = fopen("transpose.txt","w");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        fprintf(fp,"%d\n",arr[j][i]);
    }
    }
    fclose(fp);
    return 0;
}

