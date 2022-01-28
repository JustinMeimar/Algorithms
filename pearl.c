#include <stdio.h>

#define k 3

void traversePearls(int* pearls, int len, int l, int h){
	int m = (l+h)/2;
	if(pearls[m] == 1 && pearls[m+1] == 0){
		printf("%d", m);
		return;
	}
	if(pearls[m] == 0){
		//search l - (m -1)
		traversePearls(pearls, len, l, m-1);
	}
	else{
		traversePearls(pearls, len, m, h);
		//search m - h
	}
}

void printA(int* a, int len){
	for(int i =0; i<len; i++){
		if(i % 10 == 0){
			printf("\n");	
		}	
		printf("%d,", a[i]);
	}
	printf("\n");

}
int main(){
	int pearls[100];
	for(int i=0; i<100; i++){
		if(i % 10 == 0){
			printf("\n");
		}	
		if(i <99){
			pearls[i] = 1;
		}else{
			pearls[i] = 0;
		}
		printf("%d,", pearls[i]);
	}	
	printf("\n");
	int len = sizeof(pearls)/sizeof(int);
	traversePearls(pearls, len, 0, 99);

	return 0;

}
