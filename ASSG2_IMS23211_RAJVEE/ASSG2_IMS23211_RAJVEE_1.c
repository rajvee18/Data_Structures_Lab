#include<stdio.h>
#include<math.h>

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

    
    if (n>pow(10,9) || n<0)
    {
        printf("-1");
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

    for(j=1;j<n;j++)
    {
        key=A[j];

        i=j-1;
        
        while(i>=0 && A[i]>key)
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}