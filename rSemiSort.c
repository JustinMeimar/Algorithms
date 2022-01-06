#include <stdio.h>

void printA(int* a, int l, int h);

int rSemiSort(int* a, int l, int h){
	printA(a, l, h);
	int m = (l+h)/2;

	if(l >= h){
		//base case
		return a[l];

	}
	if(a[m] < a[m+1]){
		//we are in the asscending
		rSemiSort(a, m+1, h);
	}
	else{
		//we are descending
		rSemiSort(a, l, m);
	}
}

void printA(int* a, int l, int h){
	for(int i =l ; i<=h; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");
}

int main(){

	int a[12] = {1,2,3,4,5,6,7,8,9,14,13,12};
	int l = 0;
	int h = sizeof(a)/sizeof(a[0]) -1;
	
	int lar = rSemiSort(a, l, h);

	printf("\n%d", lar);
}
