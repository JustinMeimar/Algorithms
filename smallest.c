#include <stdio.h>

#define SIZE 10

int smallest(int *a, int f, int l);

int floor_sqrt(int x){
	if(x == 0 || x == 1){
		return x;
	}
	int i = 1, result = 1;
	while(result <= x){
		i++;
		result = i*i;
	}
	return i-1;
}
int min(int a, int b){
	if(a< b){
		return a;	
	}else{
		return b;
	}

}
int global = 0;

int depthOfTree(int *a, int f, int l){
	int dif = (l-f);
	int depth = floor_sqrt(SIZE);	
	
	while(dif > 0){
		dif >>= 1;
		depth+=1;
	}
	return depth;
}

int smallest(int *a, int f, int l){
	printf("first: %d, last: %d, A[f]: %d, depth: %d\n", f, l, a[f], depthOfTree(a, f, l));

	global += 1;		
	if(f == l){
		return a[f];
	}else{
		int mid = (f+l)/2;
		//return min(smallest(a, f, mid), smallest(a, mid+1, l));
		return min(smallest(a, mid+1, l), smallest(a, f, mid));

	}
}

int main(){
	int i;
	int a = SIZE;
	int array[a];
	for(i = 0; i < a; i++) {
		array[i] = i + 1;
	}
	int r = smallest(array, 0, a-1);
	printf("smallest: %d, global :%d", r, global);	
	return 0;
}
