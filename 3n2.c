#include <stdio.h>

#define SIZE 11

void minMax(int *a, int n ){
	//works for even lengthed arrays..	
	//length of sub arrays
	int i = 0, j=0;
	
	int small[SIZE/2-1] = {0};
	int large[SIZE/2-1] = {0};			 
	
	int min = a[0] > a[1] ? a[1] : a[0]; //needs MAX INT
	int max = a[1] > a[0] ? a[1] : a[0]; //not the move
	
	for(i=2; i<(n - n%2); i+=2){	
		//printf("%d, %d\n", a[i], a[i+1]);
		if(a[i] < a[i+1]){
			small[j] = a[i];
			large[j] = a[i+1];
		}else{
			small[j] = a[i+1];
			large[j] = a[i];
		}
		if(small[j] < min){
			min = small[j];
		}
		if(large[j] > max){
			max = large[j];
		}
		j++;
	}
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
	printf("\nLargest: %d, Smallest: %d", max, min);
	//total comparison 3n +1 need 3n/2		
}

int main(){

	int a[SIZE] = {99,3,4,56,6,6,25,1,734,90,9999};
	int n = sizeof(a)/sizeof(a[1]);
	minMax(a, n);
}
