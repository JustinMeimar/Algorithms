#include <stdio.h>

#define SIZE 10

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
	for(int i=2; i<(n-n%2); i+=2){ //                 (n/2)	
		//printf("%d, %d\n", a[i], a[i+1]);
		if(a[i] < a[i+1]){						// + (n/2) -1 key comparison
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

	int a[SIZE] = {99,3,4,56,6,6,25,1,734,90};
	int n = sizeof(a)/sizeof(a[1]);
	minMax(a, n);
}
