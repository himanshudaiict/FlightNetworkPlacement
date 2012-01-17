#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i;
    int *circle,*temp;
    circle=(int *)malloc(sizeof(int)*m);
    temp=(int *)malloc(sizeof(int)*m);
    printf("Enter the no. of players(m) \n");
    scanf("%d",&m);
    printf("Enter the random variable(n) \n");
    scanf("%d",&n);
    while(n>m)
    {
    printf("Invalid input\n value of random variable must be less then no. of players \n Enter the random variable again\n");
    scanf("%d",&n);
    }
    for(i=0;i<m;i++)
    {
        circle[i]=i+1;
    }
    int j=0;
    while(m>1)
    {
        for(i=0;i<m;i++)
        temp[i]=circle[i];
        for(j=0;j<m;j++)
        circle[j]=temp[(n+j)%m];
        m=m-1;
    }
    printf("the winner is %d",circle[0]);
    return 0;

}
