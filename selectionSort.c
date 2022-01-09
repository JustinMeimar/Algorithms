#include <stdio.h>

void selectionSort(int* a, int n){
	//algorithm goes like.. 
	for(int i = 0; i<n ; i++){			// n+1 
		//for every smallest i
		int s = a[i];					// n
		for(int j=i+1; j<n; j++){		// n (n+1)
			if(a[j] < s){				// n n
				int temp = s;			// n ~ n or 0
				s = a[j];				// n ~ n or 0
				a[j] = temp;			// n ~ n or 0
			}	
		}
		a[i] = s;						// n
	}

//	Avg: T(n) = n+1 + n + n(n+1) + 4n^2 + n 
//	          = 4n+1 + 5n^2 
//	          = 5n^2 + 4n + 1
//			  O(n^2)
//	Worst = Avg.
//
//	Best: T(n) = n+1 + n + n^2 + n + n^2 + 3n + n
//		       = 2n^2 + 7n + 1
//		       O(n^2)
//
//	Conclusion: Selection sort is an L 
}
void printA(int* A, int n){
	for(int i = 0; i<n; i++){
		printf("%d,", A[i]);

	}
	printf("\n");

}
int main(){
	int A[10] = {10,9,8,7,6,5,4,3,2,1};
	int n = sizeof(A)/sizeof(A[0]);
	printA(A, n);
	selectionSort(A, n);
	printA(A, n);
	return 0;
}
