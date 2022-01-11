#include <stdio.h>

void printA(int* a, int l, int h);
int putInPlace(int*a, int j, int key);

int rInsertionSort(int* A, int n){
	//start l = 1;
	if(n > 0){
		rInsertionSort(A, n-1);
		int key = A[n];
		putInPlace(A, n, key);
	}
}

int putInPlace(int *A, int j, int key){
		
	int i = j-1;
	if(i == 0){
		A[i+1] = key;
	}
	if(A[i] <= key){
		A[i+1] = key;
	}
	else{
		A[i+1] = A[i];
		putInPlace(A, j-1, key);
	}
}

void printA(int* a, int l, int h){
	for(int i =l ; i<=h; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");

}

int main(){

	int a[12] = {1,2,3,4,5,6,7,8,9,14,13,12};
	int l = 0;
	int h = sizeof(a)/sizeof(a[0]) -1;
	printA(a, l, h);
	rInsertionSort(a, h);
	printA(a, l, h);

}
