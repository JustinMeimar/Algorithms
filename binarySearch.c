#include <stdio.h>
void printArr(int* a, int len);


int binarySearch(int* arr, int n, int len){
	
	int s = 0;	//start
	int m = len/2; // mid
	int end = len;	//end

	while(end-1 > s){
		printf("%d %d %d\n", s, m, end);	
		if(arr[m] == n){
			printf("found %d at: %d\n",n, m);
			return m;
		}
		if(arr[m] < n){
			s = m;
			m = (s + end)/2;
		}else{
			end = m;
			m = (s + end)/2;
		}	
	}
	printf("%d not found\n", n);
	return -1;

}

int* insertionSort(int* arr, int len){
	// insertion sort start at left compares, swaps, then pushes;

	int i, j, key; 
	i = 1;
	while(i< len){

		j = i-1;
		key = arr[i];

		while(j>=0 && arr[j] > key){

			arr[j+1] = arr[j];	
			j--;
		}	

		arr[j+1] = key;
		
		printArr(arr, len);

		i++;
	}
	
	return arr;	

}

void printArr(int* a, int len){
	for(int i = 0; i< len; i++){
		printf("%d, ", *(a+i));

	}
	printf("\n");

}

int main(){

	int a[10] = {1,2,3,6,5,8,33,2,4,9};
	int len = sizeof(a) / sizeof(*a);	

	printArr(a, len);	
	insertionSort(a, len);
	printArr(a, len);
		
	for(int i = 1; i<10; i++){
		binarySearch(a, a[i], len);

	}
	binarySearch(a, 0, len);
	binarySearch(a, 7, len);
	binarySearch(a, 100, len);

	return 0;
	
	//binarySearch(a, 1);
}
