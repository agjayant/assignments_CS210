#include<stdio.h>
#include<time.h>
int count=0; 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int l, int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
    int j;
    for ( j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
	    //count++;
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
	count++;
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above 
int main()
{

	FILE *fp;
    fp = fopen("quick6","w");
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

    quickSort(arr, 0, n-1);

    double temp= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
	printf("%ld\n",CLOCKS_PER_SEC);
    fprintf(fp,"%d	%d	%.6f\n",n,count,temp);
    //printf("\nSorted array is \n");
    //printArray(arr, n);
	}
    return 0;
}
