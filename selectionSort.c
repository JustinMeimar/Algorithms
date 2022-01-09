#include <stdio.h>

void selectionSort(int* a, int n){
	//algorithm goes like.. 
	for(int i = 0; i<n ; i++){
		//for every smallest i
		int s = a[i];
		for(int j=i+1; j<n; j++){
			if(a[j] < s){
				int temp = s;
				s = a[j];
				a[j] = temp;
			}
		}
		a[i] = s;

	}
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
