#include <stdio.h>

void quickSort(int* a, int l, int h){
	if(l < h){
		int j = partition(a, l, h);
		quickSort(a, l, j-1);
		quickSort(a, j+1, h);
	}
}
void swap(int* a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}
int partition(int* a, int l, int h){
	
	printArray(a, l, h);	
	int pivot = a[l];
	int i = l+1;
	int j = h;
	while(i <= j){

		while(a[i] < pivot){
			i++;
		}
		while(a[j] > pivot){
			j--;
		}
		//swap a[i] and a[j];
		if(i <= j){

			swap(a, i, j);
		}		
		printf("%d , %d .. %d, %d\n", i ,j, l, h);

		printArray(a, l, h);
	}
	swap(a, l, j);
	printArray(a, l, h);

	return j;
}
void printArray(int *a, int l, int h){

	for(int i = l; i<= h; i++){
		printf("%d, ", a[i]);
	}	

	printf("\n_______________________\n");
}

int main(){
	
	int a[10] = {10,16,8,12,15,6,3,9,5,99};
	int len = sizeof(a)/ sizeof(a[0]);

	quickSort(a, 0, len-1);
	//partition(a, 0, len-1);
	
	printArray(a, 0, len-1);
}
