#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int rfib(int n){

	if(n<=1) return n;
	else return (rfib(n-1)+rfib(n-2))%2014;
	//return -1;

}

int main(){
	int t,n;

	scanf("%d",&t);

	FILE *fp;
    fp = fopen("rfib.txt","w");

	while(t--){
		scanf("%d",&n);
		clock_t tStart = clock();
		printf("%d\n",rfib(n));
		double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
    	printf("Execution Time: %.4fs\n", temp);
    	fprintf(fp,"%d %.3f\n",n,log(temp));
	}

	return 0;

}