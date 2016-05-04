#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
double sqrt(double x);

int comp = 0 ;

struct heapStruct {

    int* heaparray;
    int capacity;
    int size;
};

struct heapStruct * initHeapfromArray(int* values, int length);
void heapify(struct heapStruct *h);
void heapifyMine(struct heapStruct *h);
void percolateDown(struct heapStruct *h, int index);
void percolateDownMine(struct heapStruct *h, int index);
void percolateUp(struct heapStruct *h, int index);
void percolateUpMine(struct heapStruct *h, int index);
void insert(struct heapStruct *h, int value);
void insertMine(struct heapStruct *h, int value);
int removeMin(struct heapStruct *h);
int removeMax(struct heapStruct *h);
void printHeap(struct heapStruct *h);
void swap(struct heapStruct *h, int index1, int index2);
int minimum(int a, int indexa, int b, int indexb);
int maximum(int a, int indexa, int b, int indexb);
void freeHeap(struct heapStruct *h);


// Frees the struct pointed to by h.
void freeHeap(struct heapStruct *h) {
     free(h->heaparray);    
     free(h);
}

struct heapStruct * initHeapfromArrayMine(int* values, int length) {

    int i;
    struct heapStruct* h;

    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    // We allocate one extra slot, since slot 0 stays unused. 
    h->heaparray = (int*)malloc(sizeof(int)*(length+1));

    // Just copy the values into our array.
    for (i=1; i<=length; i++)
        h->heaparray[i] = values[i-1];

    // This is the number of values we copied.
    h->size = length;

    // This takes our random values and rearranges them into a heap.
    heapifyMine(h);
    return h;
}

struct heapStruct * initHeapfromArray(int* values, int length) {

    int i;
    struct heapStruct* h;

    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    // We allocate one extra slot, since slot 0 stays unused. 
    h->heaparray = (int*)malloc(sizeof(int)*(length+1));

    // Just copy the values into our array.
    for (i=1; i<=length; i++)
        h->heaparray[i] = values[i-1];

    // This is the number of values we copied.
    h->size = length;

    // This takes our random values and rearranges them into a heap.
    heapify(h);
    return h;
}

void heapifyMine(struct heapStruct *h) {

    int i;

    // We form a heap by just running percolateDown on the first half of the 
    // elements, in reverse order.
    for (i=h->size/2; i>0; i--)
        percolateDownMine(h, i);

}


// h points to a heap structure that has values inside of it, but isn't yet
// organized into a heap and does exactly that.
void heapify(struct heapStruct *h) {

    int i;

    // We form a heap by just running percolateDown on the first half of the 
    // elements, in reverse order.
    for (i=h->size/2; i>0; i--)
        percolateDown(h, i);

}

void percolateDownMine(struct heapStruct *h, int index) {

    int max;

    // Only try to percolate down internal nodes.
    if ((2*index+1) <= h->size) {

        // Find the maximum value of the two children of this node.            
        max = maximum(h->heaparray[2*index], 2*index, h->heaparray[2*index+1], 2*index+1);

      // If this value is more than the current value, then we need to move
      // our current value down the heap.  
        if (h->heaparray[index] < h->heaparray[max]) {
            swap(h, index, max);

            // This part is recursive and allows us to continue percolating
            // down the element in question.
            percolateDownMine(h, max);

	comp++; //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

        }


    }

    // Case where our current element has exactly one child, a left child.
    else if (h->size == 2*index) {

        // Here we only compare the current item to its only child.
        // Clearly, no recursive call is needed since the child of this node
        // is a leaf. 
        if (h->heaparray[index] < h->heaparray[2*index])
            swap(h, index, 2*index);


	comp++; //||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    }




}


void percolateDown(struct heapStruct *h, int index) {

    int min;

    // Only try to percolate down internal nodes.
    if ((2*index+1) <= h->size) {

        // Find the minimum value of the two children of this node.            
        min = minimum(h->heaparray[2*index], 2*index, h->heaparray[2*index+1], 2*index+1);

      // If this value is less than the current value, then we need to move
      // our current value down the heap.  
        if (h->heaparray[index] > h->heaparray[min]) {
            swap(h, index, min);

            // This part is recursive and allows us to continue percolating
            // down the element in question.
            percolateDown(h, min);

	comp ++ ; //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

        }
    }

    // Case where our current element has exactly one child, a left child.
    else if (h->size == 2*index) {

        // Here we only compare the current item to its only child.
        // Clearly, no recursive call is needed since the child of this node
        // is a leaf. 
        if (h->heaparray[index] > h->heaparray[2*index]){
            swap(h, index, 2*index);

comp ++ ; //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
}
    }



}

int removeMax(struct heapStruct *h) {

    int retval;

    // We can only remove an element, if one exists in the heap!
    if (h->size > 0) {

        // This is where the minimum is stored.
        retval = h->heaparray[1];

        // Copy the last value into this top slot.
        h->heaparray[1] = h->heaparray[h->size];

        // Our heap will have one fewer items.
        h->size--;

        // Need to let this value move down to its rightful spot in the heap.
        percolateDownMine(h, 1);

        // Now we can return our value.
        return retval;
    }

    // No value to return, indicate failure with a -1.
    else
        return -1;
}

int removeMin(struct heapStruct *h) {

    int retval;

    // We can only remove an element, if one exists in the heap!
    if (h->size > 0) {

        // This is where the minimum is stored.
        retval = h->heaparray[1];

        // Copy the last value into this top slot.
        h->heaparray[1] = h->heaparray[h->size];

        // Our heap will have one fewer items.
        h->size--;

        // Need to let this value move down to its rightful spot in the heap.
        percolateDown(h, 1);

        // Now we can return our value.
        return retval;
    }

    // No value to return, indicate failure with a -1.
    else
        return -1;
}

// For debugging purposes, lets us see what's in the heap.  
void printHeap(struct heapStruct *h) {
    int i;

    for (i=1; i<=h->size; i++)
        printf("%d ", h->heaparray[i]);
    printf("\n");
}

// Swaps the values stored in the heap pointed to by h in index1 and index2.
void swap(struct heapStruct *h, int index1, int index2) {
    int temp = h->heaparray[index1];
    h->heaparray[index1] = h->heaparray[index2];
    h->heaparray[index2] = temp;
}

int maximum(int a, int indexa, int b, int indexb) {

    // Return the value associated with a.    
    if (a > b)
        return indexa;

    // Return the value associated with b.
    else
        return indexb;
}

// Returns indexa if a < b, and returns indexb otherwise.
int minimum(int a, int indexa, int b, int indexb) {

    // Return the value associated with a.    
    if (a < b)
        return indexa;

    // Return the value associated with b.
    else
        return indexb;
}


int partition(int* arr, int start, int end){

        int i=start-1;    // index for swaapping
        int temp;         // temp variable for swapping
        int j;            // iterator
    
        for(j=start;j<=end-1; j++){
                if(arr[j]<arr[end]){       // arr[end] is chosen as the pivot
                        i++;

                        //swap arr[j] and arr[i]
                        temp=arr[j];
                        arr[j]=arr[i];
                        arr[i]=temp;

                }

		comp++; //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

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
        int i=0;

        int arr[n];
	int check[n];

        for (i=0;i<n;i++){  
		scanf("%d",&arr[i]);
		//arr[i] = rand()/10000;
		check[i]=arr[i];
	}

//      for (i=0;i<n;i++)  scanf("%d",&arr[i]);

//      for(i=0 ; i<n;i++) printf("%d ",arr[i]);

//      printf("\n\n");

        int sample_size = (int)sqrt((double)n);


        int sample[sample_size];

        for (i=0;i<sample_size;i++) sample[i]= arr[i*i];
//      for(i=0 ; i<sample_size;i++) printf("%d ",sample[i]);

//      printf("\n\n");



        //quick sort the sample  --------------------------------------------------------------------
        sort_quick(sample, 0, sample_size-1);

        int sample_median = sample [sample_size/2];
        printf("%d\n",sample_median);

        int arr_less[n];
        int arr_great[n];


        struct heapStruct *h;
        int k=0,l=0;

        int count_eq=0;
	
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

		comp++;         // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
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
	sort_quick(check,0,n-1);
	printf("check median: %d\n",check[n/2]);

	printf("comparisons: %d",comp);
        return 0;
}

