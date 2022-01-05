#include <stdio.h>

int rBinarySearch(int* a, int l, int h, int key){
	//recursive implementation
	//printf("%d, %d, %d\n", l, h, key);
	if(l == h){
		if(a[l] == key){
			return l;
		}
		return -1;
	}else{
		int mid = (l + h) /2;
		if(key == a[mid]){
			return mid;
		}
		if(a[mid] > key){
			return rBinarySearch(a, l, mid-1, key);
		}
		else{
		//a[mid] < key
			return rBinarySearch(a, mid+1, h, key);
		}
	}
}

int main(){
	int array[13] = {1,3,5,7,9,11,14,23,27,35,37,40,41};
	int l = 0;
	int h = sizeof(array)/sizeof(array[0]);
	
	//int kindex = rBinarySearch(array, l, h-1, 41);
	//printf("%d", kindex);	
	//rigorous testing:
	
	for(int i = 0; i<h; i++){
		int kindex = rBinarySearch(array, l, h-1, array[i]);
		printf("key (%d) = %d\n",array[i], kindex);
		//printf("%d,", array[i]);	
	}
	int kindex = rBinarySearch(array, l, h-1, 999);
	printf("key (%d) = %d\n",999, kindex);	
//	printf("key = %d", kindex);	

	 
	return 0;

}
