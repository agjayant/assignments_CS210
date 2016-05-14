#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int count=0;
int L[1000000], R[1000000];

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
   
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
	count++;
        if (L[i] <= R[j])
        {
	    //count++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 
 
/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{

	FILE *fp;
    fp = fopen("merge6","w");
	int n,i,j;
	scanf("%d",&n);
    int arr[n];
    //int arr_size = sizeof(arr)/sizeof(arr[0]);
   for(j=0;j<100;j++){
	 for(i=0;i<n;i++){
    	arr[i]=rand();
    }
    //printf("Given array is \n");
    //printArray(arr, arr_size);
    count=0;
    clock_t tStart = clock();   //record the clock time when this instruction was executed.

    mergeSort(arr, 0, n-1);

    double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.

    fprintf(fp,"%d	%d	%.6f\n",n,count,temp);
 //   printf("%0.6f\n",temp);
    //printf("\nSorted array is \n");
    //printArray(arr, n);
	}
    return 0;
}
