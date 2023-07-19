#include <stdio.h>
void main() {
    FILE *fp;
    int matrix[10][10];
    int r,c;
    int i, j;
    int symmetric=1;
    fp = fopen("input.txt","r");
    fscanf(fp,"%d\n",&r);
    fscanf(fp,"%d",&c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    fclose(fp);
    if (r!= c)
    {
       printf("MATRIX DIMENSIONS ARE NOT EQUAL!");
       exit(0);
    }
    else
        {
        for (i = 0; i < r; i++)
            {
            for (j = 0; j < c; j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    symmetric = 0;
                    break;
                }
            }
            if (symmetric == 0)
            {
                break;
            }
        }
    }
    if (symmetric==1)
    {
        printf("The matrix is symmetric.\n");
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }

}
