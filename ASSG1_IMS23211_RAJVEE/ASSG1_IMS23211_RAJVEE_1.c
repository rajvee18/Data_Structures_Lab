#include<stdio.h>
#include<math.h>

int main()
{
    int i=0,num,count,octal=0;

    scanf("%d",&num);
    count=0;

    while(num!=0)
    {

        octal=octal+(num%10)*pow(8,i);
        num=num/10;
        i++;
    }
    
    
    
    printf("%d",octal);
    
}