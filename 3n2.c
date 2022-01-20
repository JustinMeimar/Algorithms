#include <stdio.h>

#define SIZE 3

void minMax(int *a, int n ){
	//works for even lengthed arrays..	
	//length of sub arrays

	int min, max;
	if(a[0] > a[1]){			// +1 key comparison
		min = a[1];
		max = a[0];
	}else{
		min = a[0];
		max = a[1];
	}
	int i = 2;
	printf("\n");
	while(i<(SIZE-1)){ //while i < 10
		
		printf("..%d, %d, %d\n", a[i], a[i+1], i);
		if(a[i] < a[i+1]){
			if(min > a[i]){
				min = a[i];
			}
			if(max < a[i+1]){
				max = a[i+1];
			}
		}else{
			if(min > a[i+1]){
				min = a[i+1];
			}
			if(max < a[i]){
				max = a[i];
			}
		}
		
		i+=2;
	}
	if(n%2 == 1){
		if(a[n-1] > max){						// +1 key comp
			max = a[n-1];
		}
		if(a[n-1] < min){						// +1 key comp
			min = a[n-1];
		}
	}
	printf("\nLargest: %d, Smallest: %d", max, min);
	//total comparison 3n +1 need 3n/2		
}

int main(){

	int a[SIZE] = {99,9,999};
	int n = sizeof(a)/sizeof(a[1]);
	printf("SIZE: %d, %d ", n, SIZE);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ", a[i]);	
	}	
	minMax(a, n);
}
