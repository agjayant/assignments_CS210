#include <stdio.h>
#include <time.h>

int main(){
	int i,t,temp;
	long long a,b;
	long long n;
	scanf("%d",&t);

	FILE *fp;
    fp = fopen("ifib.txt","w");

	while(t--){

		scanf("%lld",&n);

		

		a=0,b=1;
		clock_t tStart = clock();

		if(n<=1){
			printf("%lld\n",n);
		}
		else{
			for(i=0;i<n-1;i++){
				temp=b;
				b=(a+b)%2014;
				a=temp;
			}

			double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
    		printf("Execution Time: %.4fs\n", temp);

    		fprintf(fp,"%lld %.2f\n",n,temp);

			printf("%lld\n",b);
		}


				
	}
	

	return 0;
}