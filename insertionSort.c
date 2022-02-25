#include <stdio.h>

void printA(int* a, int n){
	for(int i = 0; i<n; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");
}

void insertionSort(int* a, int n){

	for(int j = 1; j<n; j++){

		int x = a[j]; //a[j] is key
		int i = j-1; // start comparing to the left
		
		while((i >= 0) && (a[i] > x)){
			// assert that we don't check before array in mem
			// assert that key is larger than the comparative value
			a[i+1] = a[i]; //shift larger vales up one to make room to insert the lower value
			i--; //increment i so we can continue checking for larger values than key
		}	
		// once loop has terminated, a[i] is < x; so at a[i+1] we must insert x
		a[i+1] = x;
	}


}


int main(){

	//int a[6] = {5,2,4,6,1,3};
	int a[6] = {1,2,4,5,3,6};	
	int n = sizeof(a)/sizeof(a[0]);
	//printA(a, n);
	insertionSort(a, n);

}
