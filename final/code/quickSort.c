#include <stdio.h>

/*
 * How Quicksort Works:
 *  
 *  A = [5, 4 2, 6, 1, 7, 2, 6, 3, 7, 9, 1]
 *	
 *	partition around pivot (last element usually)
 *  
 *  A = [10, 4 2, 6, 1, 7, 2, 6, 3, 7, 9, 5]
 *       i                             j  piv
 *	
 *	while 
 *	    
 *
 * */
void printArr(int arr[10], int n){

	for(int i = 0; i< n; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

int partition(int arr[10], int l, int r){
	int i = l;
	int j = r-1;
	int piv = r;

	printf("%d, %d\n", l, r);
	
	
	
	return j;
}

void quickSort(int arr[10], int l, int r){
	if(l >= r){
		printArr(arr, 10);	
		return;
	}

	int p = partition(arr, l, r);

	quickSort(arr, l, p-1);
	quickSort(arr, p+1, r);

}

int main(){
	
	int a[10]	= {9,3,1,7,11,13,2,10,2,5};
	
	printArr(a, 10);	
	quickSort(a, 0, 9);
	printArr(a, 10);	

	return 0;
}
