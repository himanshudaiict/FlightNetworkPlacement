#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *next;
} N;
int Push(int x);
int Pop();
struct Node *point=NULL;
int top=0;
int isfull();
int isempty();
int main()
{
    struct Node *temp;
	temp=point;
	int ch,s,f,d,i;
	printf("Enter your choice \n");
	printf("1.Push \n 2.Pop \n 3.Display 4.Exit\n");
	scanf("%d",&ch);

	while(ch!=3)
	{
	    if(ch==1)
	    {
	    printf("Enter ur data\n");
	    scanf("%d",&s);
	    f=Push(s);
	    if(f==1)
	    printf("your push is successful \n");
	    else
	    printf("your push is not successful \n");
	    printf("1.Push \n 2.Pop \n 3.Dispay 4.Exit \n");
	    scanf("%d",&ch);
	    }
	    else if(ch==2)
	    {
	        int a;
	        a=Pop();
	        if(a)
	        printf("Pop returned=%d",a);
	        printf("1.Push \n 2.Pop \n 3.Display 4.Exit\n");
	        scanf("%d",&ch);
	    }
	    else if(ch==3)
	    {
	        printf("top=%d",top);
	    printf("your stack is ");
        while(point!=NULL)
	    {
	        d=point->data;
	        printf("\t %d",d);
	        point=point->next;
	    }
	    printf("1.Push \n 2.Pop \n 3.Display 4.Exit\n");
	    }
	    else
	    break;
     }

	    return 0;
}
int isfull()
{
    if(top==9)
    return 1;
    else
    return 0;
}
int Push(int m)
{
    struct Node *newnode,*temp;
    newnode=(struct Node*) malloc(sizeof(struct Node));
    if(m>=0 && m<=9)
    {
        if(isfull())
        return 0;
        else if(point==NULL)
        {
            if(m==0)
            {
            point=newnode;
            newnode->data=m;
            newnode->next=NULL;
            top++;
        return 1;
            }
            else
            printf("The operation is not permitted \n");
            return 0;
        }
        else
        {
            if(m==(point->data)+1)
            {
            newnode->data = m;
            newnode->next=point;
            point=newnode;
            top++;
            return 1;
            }
            else
            {
                printf("The operation is not permitted \n");
                return 0;
            }
        }
    }
    else
    printf("The operation is not permitted \n");
    return 0;
}

int Pop()
{
    struct Node *temp;
    if(isempty())
    {
        printf("Pop failed!!!\n");
        return 0;
    }
    else
    {
    temp=point;
    point=point->next;
    return temp->data;
    }
}
int isempty()
{
    if(top==0)
    return 1;
    else
    return 0;

}




