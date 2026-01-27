#include<stdio.h>
#include<math.h>
#include<limits.h>

long count=0;

int  merge(int A[],int p,int q,int r)
{
    int n1,n2,i,j,k;
    
    n1=q-p+1;
    n2=r-q;

    int L[n1+1];
    int R[n2+1];

    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];


    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i=0,j=0;

    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
            count++;

        }
        else
        {
            A[k]=R[j];
            j++;
            count++;

        }
    }


    
}

int merge_sort(int A[], int p,int r)
{
    int q;

    if(p<r)
    {
        q=floor((p+r)/2);
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);

    }
}

void Print(int A[],int n)
{
    
    

    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);

    }

    printf("\n%d",count);

   
}

int main()
{
    int n,p,r;
    scanf("%d",&n);
    int A[n];

    if (n>pow(10,5) || n<0)
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

    
    merge_sort(A,0,n-1);
    Print(A,n);
}