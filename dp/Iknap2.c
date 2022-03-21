#include <stdio.h>

int dp_knap(int vals[], int wghts[], int W, int n){
	
	int A[6][11] = {0}; //hard coded because C

	for(int i = 0; i< n; i++){
		A[i][0] = 0;	
	}
	for(int j = 0; j<W; j++){
		A[0][j] = 0;
	}
	
	for(int i = 1; i<n; i++){
		for(int j = 1; j<W; j++){
			//dp case choose max	dp_arr[i-1][j]	
			//						dp_arr[i][j-1]
			//						v.i + dp_arr[i][D-w.i]
			A[i][j] = A[i-1][j];
			if(j >= wghts[i-1] && A[i][j] < A[i-1][j-wghts[i-1]] + vals[i-1]){

				A[i][j] = A[i-1][j-wghts[i-1]] + vals[i-1];
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		printf("\n");
		for(int j = 0; j<W; j++){
			if(A[i][j] > 9){
				printf("%d ", A[i][j]);	
			}else{
				printf("%d  ", A[i][j]);
			}
			
		}
	}
}

int main(){
	//			  i = {1,2,3,4,5}	
	int vals[5]		= {4,3,6,5,7};
	int weights[5]	= {2,2,3,4,5};
	int W = 10;
	int n = 5;

	dp_knap(vals, weights, W+1, n+1);

	return 0;
}
