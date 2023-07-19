#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node* insert(struct node *);
struct node* sort(struct node *,int n);
void display(struct node *);
struct node *temp,*temp1,*newnode;
void main()
{
    int n,i;
    printf("n=");
    scanf("%d",&n);
    printf("enter data:\n");
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        scanf("%d",&newnode->data);
        head=insert(newnode);
    }display(head);
   sort(head,n);


}
struct node* insert(struct node *newnode)
{
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
        return (head);

    }
    else
    {
        temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return (head);
    }
}

struct node* sort(struct node *head,int n)
{  int i,j;
temp=head;
while(temp->next!=NULL)
{
    {
        for(i=0;i<n;i++)
    {
        for(j=i;j<n-i;j++)
        {
            if(temp->data>temp->next->data)
            {
                temp1 =temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1;
            }
        }
    }
    }
}printf("AFTER:\n");
display(head);

}

void display(struct node *head)
{
    if(head==NULL)
    {
       printf("EMPTY");

    }
    else
    {
        temp=head;
        printf("BEFORE:\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
   printf("\n");
    }

}
