#include <stdio.h>

void mergeSort(int* arr, int s, int e){

	if(s < e){
		int m = s + (e-s)/2;
		mergeSort(arr, s, m);
		mergeSort(arr, m+1, e);

		merge(arr, s, m, e);		
	}
	
}


void printA(int* a, int s, int e){
	for(int i=s; i<=e; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");

}

void merge(int* arr, int s, int m, int e){
	
	int i = 0;
	int j = 0;
	
	int n1 = m-s+1; //first sorted sub array len
	int n2 = e-m; //second sorted sub array len
	
	int la[n1];
	int ra[n2];
	
	//add elements to respective sortted sub arrays;
	
	for(int i = 0; i<n1; i++){
		la[i] = arr[s+i];
		printf("[%d],", la[i]);

	}

	printf(" %d| %d ,%d, %d", n1, s, m, e);
	printf("\n");
	for(int j = 0; j<n2; j++){
		ra[j] = arr[m+j+1];
	
		printf("[%d],", ra[j]);
	}

	printf(" %d| %d, %d, %d", n2, s, m, e);
	//traverse sub arrays, compare and insert into original.
	int k = s;
	
	while(i < n1 && j < n2){
		if(la[i] < ra[j]){
			arr[k] = la[i];
			i++;
		}else{
			arr[k] = ra[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = la[i];	
		i++;
		k++;
	}
	while(j< n2){
		arr[k] = ra[j];
		j++;
		k++;
	}
	
	printf("\n");
	for(int i=s; i<=e; i++){
		printf("%d,", arr[i]);
	}
	
	printf("\n------\n");
	
}

int main(){
	
	int a[8] = {9,8,7,6,5,4,3,2};
	int len = sizeof(a) / sizeof(*a);
	printA(a, 0, len-1);
	mergeSort(a, 0, len-1);

	return 0;

}
