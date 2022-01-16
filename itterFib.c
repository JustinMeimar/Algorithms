#include <stdio.h>
#include <stdlib.h>

int* fib(int n){
	//itterative FIB O(n)
	int* F = malloc(sizeof(int)*n); //allocate array of size n
	F[0] = 0;
	F[1] = 1;

	for(int j = 2; j<n; j++){
		F[j] = F[j-1] + F[j-2];	
		//printf("%d", F[j]);
	}
	return F;

}
int main(){
	int x = 7;
	int* F = fib(x);
	for(int i = 0; i<x; i++){
		printf("%d, ", F[i]);
	}
	free(F); //VALGRIND GANG
	return 0;
}
