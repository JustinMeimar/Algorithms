#include <stdio.h>

void printA(int* a, int l, int h);

int rSemiSort(int* a, int l, int h){
	printA(a, l, h);

}

void printA(int* a, int l, int h){
	for(int i =l ; i<h; i++){
		printf("%d, ", a[i]);
	}

}

int main(){

	int a[12] = {1,2,3,4,5,6,7,8,9,14,13,12};
	int l = 0;
	int h = sizeof(a)/sizeof(a[0]) -1;
	
}
