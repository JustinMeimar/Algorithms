#include <stdio.h>

#define SIZE 11

void minMax(int *a, int n ){
	//works for even lengthed arrays..	
	//length of sub arrays
	int i = 0, j=0;
<<<<<<< HEAD
	int min, max;
	if(a[0] > a[1]){			// +1 key comparison
		min = a[1];
		max = a[0];
	}else{
		min = a[0];
		max = a[1];
	}
	for(i=2; i<(n-n%2); i+=2){ //                 (n/2)	
=======
	
	int small[SIZE/2-1] = {0};
	int large[SIZE/2-1] = {0};			 
	
	int min = a[0] > a[1] ? a[1] : a[0]; //needs MAX INT
	int max = a[1] > a[0] ? a[1] : a[0]; //not the move
	
	for(i=2; i<(n - n%2); i+=2){	
>>>>>>> 1a7dcc3b1c4d98a68148ad59c6098fb015a00352
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
		if(small[j] < min){
			min = small[j];
		}
		if(large[j] > max){
			max = large[j];
		}
		j++;
	}
<<<<<<< HEAD
	if(n%2 == 1){
		if(a[n-1] > max){						// +1 key comp
			max = a[n-1];
		}
		if(a[n-1] < min){						// +1 key comp
			min = a[n-1];
		}
	}
=======
	//handle odd element at end
	if(n%2 == 1){
		if(a[n-1] > max){
			max = a[n-1];
		}
		if(a[n-1] < min){
			min = a[n-1];
		}
	}
	for(int i  =0; i<(SIZE/2)-1; i++){printf("%d,", small[i]);}	
	printf("\n");
	for(int i  =0; i<(SIZE/2)-1; i++){printf("%d,", large[i]);}
>>>>>>> 1a7dcc3b1c4d98a68148ad59c6098fb015a00352
	printf("\nLargest: %d, Smallest: %d", max, min);
	//total comparison 3n +1 need 3n/2		
}

int main(){

	int a[SIZE] = {99,3,4,56,6,6,25,1,734,90,9999};
	int n = sizeof(a)/sizeof(a[1]);
	minMax(a, n);
}
