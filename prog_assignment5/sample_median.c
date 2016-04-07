#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quick_sort.h"
#include "heap_maxmin.h"

double sqrt(double x);

int main(){
	int n;
	scanf("%d",&n);
	int i=0;

	int arr[n];

	for (i=0;i<n;i++)  arr[i] = rand()/10000;
//	for (i=0;i<n;i++)  scanf("%d",&arr[i]);

//	for(i=0 ; i<n;i++) printf("%d ",arr[i]);

//	printf("\n\n");

	int sample_size = (int)sqrt((double)n);

     
	int sample[sample_size];

	for (i=0;i<sample_size;i++) sample[i]= arr[i*i];
//	for(i=0 ; i<sample_size;i++) printf("%d ",sample[i]);

//	printf("\n\n");



	//quick sort the sample  --------------------------------------------------------------------
	sort_quick(sample, 0, sample_size-1);

        int sample_median = sample [sample_size/2];
	printf("%d\n",sample_median);

	int arr_less[n];
	int arr_great[n];


	struct heapStruct *h;
	int k=0,l=0;

	int count_eq=0;

	//--------------------------------------------------------------assuming all entries in the array to be distinct

	for (i=0;i<n;i++){
		if(sample_median > arr[i]){
			

			arr_less[k]= arr[i];
			k++;

		}	
		else if (sample_median < arr[i]){
			

			arr_great[l]=arr[i];
			l++;	
		}

		else count_eq++;
	}

	int error,temp;

	printf("less: %d\n",k);

	printf("more: %d\n",l);
	if(k==l){
		printf("Median: %d\n" , sample_median);	
		return 0;
	}
	else if (k >l){		

		error = k+count_eq -n/2;
		printf("error: %d\n", error);

		h = initHeapfromArrayMine( arr_less,k+1 );
		for(i=0;i<error;i++) temp = removeMax(h);
		printf("Median: %d\n",temp);
		freeHeap(h);

	}


	else {		
		error = l+count_eq -n/2;
		printf("error: %d\n", error);

		h = initHeapfromArray( arr_great,l+1 );
		for(i=0;i<error;i++) temp = removeMin(h);
		printf("Median: %d\n",temp);
		freeHeap(h);
	
	}

	 
	return 0;
}
