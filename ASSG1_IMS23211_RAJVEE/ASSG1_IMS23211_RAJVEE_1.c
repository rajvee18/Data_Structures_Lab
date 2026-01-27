#include<stdio.h>
#include<math.h>

void swap(int *x,int *y)
{
    int temp= *x;
    *x=*y;
    *y=temp;
    
}

int main()
{
    int n,count=0,minimum;
    scanf("%d",&n);
    int A[n];
    if (n>pow(10,9) || n<0)
    {
        printf("-1");
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        count++;
        

    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>1000 || A[i]<-1000)
        {
            printf("-1");
            return 0;
        }
    }
    if(count>n)
    {
        printf("-1");
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        minimum=i;

        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[minimum])
            {
                minimum=j;
            }
        }
        swap(&A[i],&A[minimum]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

}