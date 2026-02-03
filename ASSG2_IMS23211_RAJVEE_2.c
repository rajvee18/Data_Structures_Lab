#include<stdio.h>
#include<math.h>

void swap(int *x,int *y)
{
    int temp= *x;
    *x=*y;
    *y=temp;
    
}

int partition(int A[],int p,int r)
{
    int x=A[r],i,j;
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;

}

int quick_sort(int A[],int p,int r)
{
    if (p<r)
    {
        int q=partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);

    }

}


int main()
{
    int n,key,i=0,j=0,count=0,temp;
    
    char ch;

   
    if (scanf("%d", &n) != 1) return 0;

    int A[n];
    
    while (count < 100) 
    { 
        if (scanf("%d", &A[i]) == 1)
        {
            count++;
        }

        
        ch = getchar();

        
        if (ch == '\n' || ch == EOF) {
            break;
        }
        i=i+1;
    }

    if (count != n) 
    {
        printf("-1\n");
        return 0;
    }

     for(i=0;i<n;i++)
    {
        if(A[i]>1000 || A[i]<-1000)
        {
            printf("-1");
            return 0;
        }
    }

    
    if (n>pow(10,9) || n<0)
    {
        printf("-1");
        return 0;
    }

    quick_sort(A,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }




}