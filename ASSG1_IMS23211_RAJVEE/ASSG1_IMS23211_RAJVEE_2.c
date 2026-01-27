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
    int n;
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
        
        

    }
    for(int i=0;i<n;i++)
    {
        if(A[i]>1000 || A[i]<-1000)
        {
            printf("-1");
            return 0;
        }
    }
    

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n-k-1;i++)
        {
            if(A[i]>A[i+1])
            {
                swap(&A[i],&A[i+1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

    
}