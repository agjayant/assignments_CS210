#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int start, int end){

	int i=start-1;    // index for swaapping
	int temp;         // temp variable for swapping
	int j;	          // iterator
	
	for(j=start;j<=end-1; j++){
		if(arr[j]<arr[end]){       // arr[end] is chosen as the pivot
			i++;

			//swap arr[j] and arr[i]
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;

		}

	}

	//swap arr[i+1] and arr[end]
	temp=arr[end];
	arr[end]=arr[i+1];
	arr[i+1]=temp;

	return i+1;        // returns the index of the pivot

}

int sort_quick(int *arr, int start, int end){

	if(start >= end) {
		return 0; 
	}

	int pivot= partition(arr, start, end);

	sort_quick(arr, start, pivot-1);
	sort_quick(arr, pivot+1, end);

	return 0;
}

int main(){
	int n;
	scanf("%d",&n);

	int arr[n];
	int i;
	for(i=0;i<n;i++){
		arr[i]=rand();
	}

	
	sort_quick(arr,0, n-1);
/*
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
*/		
	printf("\n");
	return 0;

}
