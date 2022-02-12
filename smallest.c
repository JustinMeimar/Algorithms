#include <stdio.h>

int smallest(int *a, int f, int l);

int min(int a, int b){
	if(a< b){
		return a;	
	}else{
		return b;
	}

}
int global = 0;

int smallest(int *a, int f, int l){
	printf("%d, %d \n", f, l);
	global += 1;		
	if(f == l){
		return a[f];
	}else{
		int mid = (f+l)/2;
		return min(smallest(a, f, mid), smallest(a, mid+1, l));
	}
}

int main(){
	int i;
	int a = 200;
	int array[a];
	for(i = 0; i < a; i++) {
		array[i] = i + 1;
	}
	int r = smallest(array, 0, a);
	printf("smallest: %d, global :%d", r, global);	
	return 0;
}
