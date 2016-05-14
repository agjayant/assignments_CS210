#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int count1=0;
int count2=0;
int L[1000000], R[1000000];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

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
	count1++;
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
	count2++;
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
    fp = fopen("comp6","w");
	int n,i,j,count3=0,flag=0;
	scanf("%d",&n);
    int arr[n], brr[n];
    //int arr_size = sizeof(arr)/sizeof(arr[0]);
   for(j=0;j<2000;j++){
		 for(i=0;i<n;i++){
	    	arr[i]=rand();
		brr[i]=arr[i];
	       }
    //printf("Given array is \n");
    //printArray(arr, arr_size);
    count1=0;
//    printf("check1\n");
    clock_t tStart = clock();   //record the clock time when this instruction was executed.

    mergeSort(arr, 0, n-1);

    double temp1= (double)(clock() - tStart)/CLOCKS_PER_SEC; //runtime of the above code segment is current time minus start time tStart.
    
  //  printf("check2\n");
    count2=0;
    tStart = clock();   //record the clock time when this instruction was executed.

    quickSort(brr, 0, n-1);

    double temp2= (double)(clock() - tStart)/CLOCKS_PER_SEC;
    if(temp1<temp2) {
	count3++;
	flag=1;
    }
    fprintf(fp,"%d	%d	%.6f	%d	%.6f	%d\n",n,count1,temp1,count2,temp2,flag);
    //printf("\nSorted array is \n");
    //printArray(arr, n);
     flag=0;
	}
printf("%d",count3);
    return 0;
}
