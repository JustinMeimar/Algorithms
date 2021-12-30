#include <stdio.h>

int Isqrt(x){
	//using binary search cause other method too easy..
	
	//setting up the array
	int arr[x/2];	
	for(int i = 0; i< x/2; i++){
		arr[i] = i;
		//printf("%d", arr[i]);
	}

	//binary search
	int start = 0;	
	int end = x/2;
	int m = end/2;

	while(1){
		printf("%d\n", m);
		if( ( arr[m]*arr[m] ) < x ){
			if( ( arr[m+1]*arr[m+1] ) > x ){
				//printf("here(%d)", i);
				return m;
			}	
		}
		if( arr[m]*arr[m] > x ){
			end = m; 		
		}else{
			start = m;
		}
	}
	
}
int main(){
	printf("%d", Isqrt(39));
	return 0;

}
