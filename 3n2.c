#include <stdio.h>

#define SIZE 11

void minMax(int *a, int n ){
	//works for even lengthed arrays..	
	//length of sub arrays
	int i = 0, j=0;
	int small[SIZE/2] = {0};
	int large[SIZE/2] = {0};
	
	for(i=0; i<n; i+=2){
		//printf("%d, %d\n", a[i], a[i+1]);
		if(a[i] < a[i+1]){
			small[j] = a[i];
			large[j] = a[i+1];
		}else{
			small[j] = a[i+1];
			large[j] = a[i];
		}
		j++;
	}
	if(SIZE % 2 == 1){	
		small[j] = a[n-1];
	}

	int smallest = small[0];
	
	for(int j =0;j<SIZE/2; j++){
		printf("%d,", small[j]);
		if(small[j] < smallest){
			smallest = small[j];
		}
	}
	printf("\n");	
	int largest = large[0];
		
	for(int j =0;j<SIZE/2; j++){
		printf("%d,", large[j]);
		if(large[j] > largest){
			largest = large[j];
		}
	}
	printf("\nLargest: %d, Smallest: %d", largest, smallest);
	//total comparison 3n +1 need 3n/2
		
}

int main(){

	int a[SIZE] = {99,3,4,56,6,6,25,1,734,90,735};
	int n = sizeof(a)/sizeof(a[1]);
	minMax(a, n);
}
