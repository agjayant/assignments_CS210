#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int a[4]={1,1,1,0};

int* mul_matrix(int* first , int* second){
	int* final= malloc(sizeof(int) * 4);

	final[0]= (first[0]*second[0]+first[1]*second[2])%2014;
	final[1]= (first[0]*second[1]+first[1]*second[3])%2014;
	final[2]= (first[2]*second[0]+first[3]*second[2])%2014;
	final[3]= (first[2]*second[1]+first[3]*second[3])%2014;

	return final;
}

int* mul_recurse(long long n){

	//base case
	if(n==1){
		return a;
	}

	else {
		int* temp=mul_recurse(n/2);
		temp=mul_matrix(temp,temp);
		if(n%2==0) return temp;
		else return mul_matrix(a,temp);
	}
}

int main(){

	int t;
	scanf("%d",&t);

	FILE *fp;
	fp = fopen("clever_fib.txt","w");
	int j;
	while(t--){

		long long n;
		scanf("%lld",&n);

		if(n<=1) printf("%lld\n",n);
		else{
			j=100000;
			clock_t tStart = clock();
			int* final;			
			while(j--) final= mul_recurse(n-1);

			double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
    		printf("Execution Time: %.6fs\n", temp);
    		printf("%lld\n",n);
			printf("%d\n",final[0]);
					
			fprintf(fp,"%lld %.6f\n",n,temp);
		}
		
	}


	return 0;
}
