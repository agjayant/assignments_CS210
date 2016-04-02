//This program tells how to calculate runtime of a particular code segment.
#include <stdio.h>
#include <time.h>
int main()
{
    long long int n, i, flag=0;
    FILE *fp;
    fp = fopen("data","w");
    printf("Enter a positive integer: (-1 to stop) \n");
    scanf("%lld",&n);

    
    while(n!=-1)
    { 
    clock_t tStart = clock();   //record the clock time when this instruction was executed.
    flag=0;
    for(i=2;i<=n/2;++i)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("%lld is a prime number. \n",n);
    else
        printf("%lld is not a prime number. \n",n);

    
    double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
    printf("Execution Time: %.2fs\n", temp);
    
    fprintf(fp,"%lld,%.2f\n",n,temp);
    
    printf("Enter a positive integer: (-1 to stop)\n");
    scanf("%lld",&n);
    } 
    return 0;
}
