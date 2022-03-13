#include <stdio.h>
int max(int a, int b){
	return a > b ? a : b;
}

int LSA_itterative(){
	
	int arr[8] = {2,-3,2,-1,2,-1,2,-1};
	int maxSub = arr[0];	
	int curSum = 0;

	for(int i = 0; i< 7; i++){
		if(curSum < 0){
			curSum = 0;	
		}
		curSum += arr[i];
		maxSub = max(maxSub, curSum);
	}	
	//sliding window

	return maxSub;

}

int LSA_recursive(int* arr, int l, int r, int n){
	int mid = (l+r)/2;


}

int main(){
	//int x = LSA_itterative();	
	//printf("%d", x);
	int arr[8] = {2,-3,2,-1,2,-1,2,-1};
	LSA_recursive(arr, 0, 7, 7);	
	
	return 0;
}
