#include<stdio.h>
#include<math.h>

long count=0;

 // for INT_MAX

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    // +1 for sentinel
    int L[n1 + 1];
    int R[n2 + 1];

    // Copy left subarray
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    // Copy right subarray
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

 

    int i = 0, j = 0;

    // Merge
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
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