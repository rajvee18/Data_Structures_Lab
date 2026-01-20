#include<stdio.h>

int gcd(int a,int b)
    {
        if(b==0)
            return a;
        int r = a%b;

        gcd(b,r);
    }

int main()
{

    int x,y,num;
    scanf("%d %d",&x,&y);
    num=gcd(x,y);
    
    printf("%d",num);

    
}