#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//should really add some comments... i know...

//longest common substring -- dynamic programming
void LCS(char* X, int len_x, char* Y, int len_y){
	//string of char X, Y
	int* arr = malloc(sizeof(int)*len_x*len_y);	
	
	for(int i = 0; i<len_x; i++){	
		arr[i] = 0;
	}
	for(int j = 0; j<len_y; j++){
		arr[len_x*j] = 0;
	}

	//dynammic programming starts:
		
	for(int i = 1; i<len_x; i++){		
		for(int j = 1; j<len_y; j++){

			arr[i*len_y + j] = arr[(i-1)*len_y + j]; //set inital lowest optimal
			
			if(arr[i*len_y + j-1] > arr[i*len_y + j]){
				arr[i*len_y + j] = arr[i*len_y + j-1];
			}

			if(X[i-1] == Y[j-1] && arr[(i-1)*len_y + j-1] + 1 > arr[i*len_y + j] ){
					
				arr[i*len_y + j] = arr[(i-1)*len_y + j-1] + 1;
			}	
		}	
	}
	
	
	//print dp array
	for(int k = 0; k<(len_x*len_y); k++){
		if(k %len_x == 0){
			printf("\n");
		}	
		printf("%d", arr[k]);
	}

	printf("\nanswer: %d", arr[len_x*len_y]);
}

int main(){
	 
	char* X = "dyanmicprogram";
	char* Y = "dog";

	int len_X = strlen(X);	
	int len_Y = strlen(Y);	
	
	printf("\nInputs: %s, %s\n", X, Y);

	LCS(X, len_X+1, Y, len_Y+1);
	
	return 0;
}
