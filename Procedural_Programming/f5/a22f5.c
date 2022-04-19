#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define x 16

long long GetLongLong();

int main(){
long long num, l ;
int i ,A[x] , n ,  p , B[x] , s , p1, p2;
printf("Insert card number:");
num= GetLongLong();
if (num>=10000000000000000 || num<1000000000000000)
{
    printf("%lld  is invalid.", num);
}
else
   {

    n=15;
    l = num;

  for(i=1; i<=x; i++)
    {   p=l %10;
        l=l /10;
        A[n]=p;
        n=n-1;
    }

        if (A[0] < 4 ||  A[0]>7)
        {
            printf("%lld  is invalid.", num );
        }

        else
          {
          for(i=0; i<x; i++)
          { B[i]=A[i];
          }
          s=0;
          for(i=0; i<x; i+=2)
          {
            B[i]=2*B[i];
            if(B[i]>=10)
            {
             p1= B[i]/10;
             p2=B[i]%10;
             B[i]=p1 + p2;
            }
          }
    for(i=0; i<x; i++)
       {
           s=s+ B[i];
       }

    if (s % 10 ==0 )
    {
        printf("%lld  is VALID.", num);

    }
    else
    {
        printf("%lld  is invalid.", num);

    }
     }
}

return 0;}



long long GetLongLong()
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }

}
