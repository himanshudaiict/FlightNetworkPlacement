#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node *next;
};

struct Node *head=NULL;
void push(int a);
int pop();
void display();

int lastI=-1;

int main()
{
        int a,b,c,d,x,y,z,flag=0,i,j,k,m;
	int arr[10];
	printf("Enter the sequence ( one at a time) for which the validity is to be checked\n");
	for(i=0;i<10;i++)
	{
		scanf("%d", &arr[i]);
	}

	//Input taken

	for(j=0;j<=arr[0];j++)
	{
		push(j);
	}

	int v=pop();


	for (k=1;k<10;k++)
	{
		if(arr[k]>arr[k-1])
		{
			for(m=arr[k-1];m<=arr[k];m++)
			{
				push(m);
			}

			v=pop();
		}

		else
		{
			int z= pop();
			if(z!= arr[k])
			{
				printf("Sequence not valid\n");
				flag=1;
				break;
			}
		}
	}

	if(!flag)
	{
		printf("Sequence valid\n");
	}
    return 0;
}

void push(int a)
{
        struct Node *newnode;
	if(a==lastI+1 && lastI<11)
	{
	lastI++;

        newnode= (struct Node*)malloc(sizeof(struct Node));
        newnode->data=a;

        if(head==NULL)
        {
                head= newnode;
                newnode->next= NULL;
        }

        else
        {
                newnode->next= head;
                head=newnode;
        }

        printf("PUSH Successful\n");
	}

	else
	{
		printf("You are not permitted to enter this data. PUSH Unsuccessful\n");
	}

}

int pop()
{
        struct Node *temp;
        int n;
        temp= head;
        if(temp==NULL)
        {
                printf("Stack UnderFlow...Nothing to pop\n");
		return -1;
        }

        else
	{
		temp=head;
		head= head->next;
                n= temp->data;
                printf("The popped data is %d\n",n);
                //lastI--;
                free(temp);
		return n;
        }
}



