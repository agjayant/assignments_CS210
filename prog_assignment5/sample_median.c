#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quick_sort.h"

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

	for (i=0;i<sample_size;i++) sample[i]= arr[i*i-2];
//	for(i=0 ; i<sample_size;i++) printf("%d ",sample[i]);

//	printf("\n\n");



	//quick sort the sample  --------------------------------------------------------------------
	sort_quick(sample, 0, sample_size-1);

        int sample_median = sample [sample_size/2];
	printf("%d\n",sample_median);

	int arr_less[n];
	int arr_great[n];
	int count_less=0;
	int count_great=0;
	int k=0,l=0;

	int count_eq=0;

	//--------------------------------------------------------------assuming all entries in the array to be distinct

	for (i=0;i<n;i++){
		if(sample_median > arr[i]){
			
			count_less ++;
			arr_less[k]= arr[i];
			k++;

		}	
		else if (sample_median < arr[i]){
			
			count_great ++;
			arr_great[l]=arr[i];
			l++;	
		}

		else count_eq++;
	}

	printf("less: %d\n",count_less);

	printf("more: %d\n",count_great);
	if(count_less == count_great){
		printf("Median: %d" , sample_median);	
		return 0;
	}
	else if (count_less > count_great){		
		printf("error: %d", count_less+count_eq - n/2);	
	}


	else {		
		printf("error: %d", count_great+count_eq - n/2);	
	}

	 
	return 0;
}
