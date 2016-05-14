#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge (int* arr, int* final,int start,int mid, int end);

void mergeSort(int* arr, int* final,int start, int end){
	if(start>=end) return;

	mergeSort(arr,final,start,(start+end)/2);
	mergeSort(arr,final,(start+end)/2+1,end);

	merge(arr,final,start,(start+end)/2,end);

}

void merge(int* arr, int* final,int start,int mid,int end){

	int i=start;
	int j=mid+1;

	int k=start;

	while(i<mid+1 && j<=end){
		if(arr[i]<arr[j]){
			final[k]=arr[i];
			k++;
			i++;
		}
		else{
			final[k]=arr[j];
			k++;
			j++;
		}
	}

	if(i==mid+1){
		while(j<=end){
			final[k]=arr[j];
			k++;	
			j++;
		} 
	}
	else{
		while(i<=mid){
			final[k]=arr[i];
			k++;
			i++;	
		}	
	}

	for(i=start;i<=end;i++){
		arr[i]=final[i];
	}

}

int main(){
	int n;
	scanf("%d",&n);

	int arr[n];
	int final[n];

	int i;
	for(i=0;i<n;i++){
		arr[i]=rand();
	}
	time_t start=clock();
	mergeSort(arr,final,0,n-1);
printf("%lf", (double)(clock() - start)/CLOCKS_PER_SEC);
/*	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	*/
	printf("\n");


	return 0;
}
