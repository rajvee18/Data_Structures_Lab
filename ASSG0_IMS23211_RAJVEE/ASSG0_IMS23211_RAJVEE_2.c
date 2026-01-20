#include<stdio.h>

int main()
{
    int n,count,num,flag=0;
    

    scanf("%d",&n);
    int arr[n];
    int visited[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;

        count=1;
        visited[i]=1;

        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j] && j != i)
            {
                count++;
                flag++;
                visited[j]=1;
            }
                
        }

        if(count>1)
        {
            printf("%d ",arr[i]);
            for(int k=0;k<n;k++)
            {
                if(arr[i]==arr[k])
                {
                    printf("%d ",k);
                }
            }
            printf("%d\n",count);

        }
        
            
            
    }
    if(flag<1)
        printf("-1");
        
    

    
}

