#include <stdio.h>

int max(int a, int b){
	return (a > b)? a : b;
}

int cutRod(int price[], int n){
	//array of prices to be filled in, n = length of rod
	int val[n+1];		//array of optimal values at given length
	val[0] = 0;			//for length == 0, optimal is 0 (base case)
	int i, j;

	for(i = 1; i<=n; i++){
		//calculate max combinations of sub rod max length i	
		int max_val = -1;
		for(j = 0; j< i; j++){
			max_val = max(max_val, price[j] + val[i-j-1]);
		}
		val[i] = max_val; 
	}
	return val[n];
}

int main(){
	int n = 8;	
	int arr[8] = {1, 5, 8, 9, 10, 17, 17, 20};
	int optimal = cutRod(arr, n);	
	printf("optimal is: %d\n", optimal);	
	return 0;
}
