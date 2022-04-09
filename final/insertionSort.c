#include <stdio.h>
/*
 * How does insertion sort work?
 * A = [1,2,4,5,6,7,3,5,4,3,2,1]
 *        j         i
 *  
 */

void printArr(int arr[9], int n){
	for(int i=0; i<9; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertionSort(int arr[9], int n){
	for(int i = 1; i<n; i++){
		int j = i-1;
		int orig = arr[i];

		while(j > -1 && arr[j] > orig){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = orig;
		printArr(arr, 9);
	}	

}


int main(){
	
	int arr[9] = {1,7,8,32,2,5,1,5,7};
	printArr(arr, 9);
	insertionSort(arr, 9);
	printArr(arr, 9);
	
	return 0;
}
