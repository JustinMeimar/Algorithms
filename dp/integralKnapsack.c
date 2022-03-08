#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 6

int print_2D(int A[ROW][COL], int r, int c);

int dp_knap(int W, int*w, int*v){
	//start with base case:
	
	int n = (ROW-1);
	
	int A[ROW][COL] = {0};

	for(int i = 0; i<=n; i++){
		A[i][0] = 0; //subproblems of item = 0 are 0
	}
	for(int j = 0; j<W; j++){
		A[0][j] = 0; //subproblems of weight = 0 are 0
	}
	
	for(int i = 0; i<=n; i++){
		for(int D = 0; D<=W; D++){
			A[i][D] = A[i-1][D];
			if(D >= w[i] && A[i][D] < (A[i-1][D-w[i]] +v[i])){
				A[i][D] = A[i-1][D-w[i]] + v[i];
			}
		}
	}		
	print_2D(A, ROW+1, COL+1);

	return A[n-1][W-1];
	
}
int print_2D(int A[ROW][COL], int r, int c){
	for(int i = 0; i<r; i++){
		if(i != 0){printf("\n");}
		for(int j = 0; j<c; j++){
			printf("%d, ", A[i][j]);
		}
	}
	printf("\n");
}
int main(){
	int W = 5;
	int w[3] = {4, 2, 2};
	int v[3] = {6, 5, 4};

	dp_knap(W, w, v);

	return 0;
}
