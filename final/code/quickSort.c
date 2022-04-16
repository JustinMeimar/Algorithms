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

int partition(int arr[10], int p, int r){
	int piv = arr[r];
	int i = -1;
	for(int j = i+1; j < r; j++){
		if(arr[j] <= piv){
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	
	return i+1;
}

void quickSort(int arr[10], int p, int r){
	if(p < r){
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);

	}
}

int main(){
	
	int a[10]	= {9,3,1,7,11,13,2,10,2,5};
	
	printArr(a, 10);	
	quickSort(a, 0, 9);
	printArr(a, 10);	

	return 0;
}
