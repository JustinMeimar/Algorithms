#include<stdio.h>

int reverse(int x){
	

	char digs[32] = {0};
	int i = 10;
	int j = 0;	
	int ans = 0;

	while(i/10 < x){

		digs[j] = (x%i)/(i/10); 	
		i *= 10;
		j++;

	}
	j--;
	i = 1;
	while(j >= 0){

		ans += (digs[j] * i);
		i *= 10;	
		j--;

	}
	if(x < 0){
		ans *= -1;
	}
	return ans;
}

int main(){
	
	printf("%d", reverse(123456789));
	return 0;

}


