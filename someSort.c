#include <stdio.h>

void printA(int* a, int l, int h);
void printA(int* a, int l, int h){
	for(int i =l ; i<h; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");

}

int someSort(int* a, int b, int e){
	if(e == b+1){
		printf("done index: %d, %d \n", b, e);
		if(a[b] > a[e]){
			int temp = a[b];
			a[b] = a[e];
			a[e] = temp;
		}
		return 0;
	}else if(e > (b+1)){
		int p = ((b + e + 1)/3);
		printf("real index: %d, %d, %d \n", b, e, p);
		//printf("semantic index: %d, %d, %d\n", b+1, e+1, p+1);
		printA(a, 0, 5);	
		someSort(a, b, e-p);
		someSort(a, b+p, e);
		someSort(a, b, e-p);
	}
	
}

int main(){

	int a[5] = {5,4,3,2,1};
	//int a[3] = {3,2,1};	
	someSort(a, 0, 5);
	printf("\nfinal ans:");
	printA(a, 0, 5);
}
