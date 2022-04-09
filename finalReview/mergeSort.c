#include <stdio.h>
#define LEN 7
// see running time analysis below:
void merge(int arr[LEN], int l, int m, int r){

	printf("%d, %d, %d\n", l, m,  r);
	
	int n1 = m - l +1;
	int n2 = r - m;
	
	int L[n1], R[n2];

	for(int i = 0; i<n1; i++){
		L[i] = arr[l+i];
	}
	for(int j = 0; j< n2; j++){
		R[j] = arr[m+ 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while(i < n1 && j < n2){
		if(L[i] < R[j]){
			// arr[l+ i] <--- L[i]
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	

	return;
}

int* mergeSort(int arr[LEN], int n, int i, int j){
	
	if(i >= j){
		// base case
		merge(arr, i, i, j);
		return;
	}
	int m = (i + j)/2;
	mergeSort(arr, n, i, m);
	mergeSort(arr, n, m+1, j);
	
	merge(arr, i, m,  j);

	return arr;

}
void printArray(int arr[LEN], int n){

	for(int i = 0; i<n; i++){
		printf("%d ", arr[i]);

	}
}

int main(){
	
	int arr[LEN] = {4,5,2,1,9,3,8};
	
	printArray(arr, 7);
	printf("\ni  m  j\n");
	mergeSort(arr, LEN, 0, 6);
	printArray(arr, 7);
	return 0;
}

/*
 Running Time Analysis:
		
 
 T(n) = 2T(n/2) + n
		 ^        ^
		 |		  |
	recrusive    merge

 */
