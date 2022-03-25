#include <stdio.h>
#include <stdlib.h>
//recursive solution:
//max(
//		lsp(str[0:n-1])
//		lsp(str[1:n])	
//		lsp(str[1:n-1] iff str[0] == str[n])
//)
//
void lsp(char* str, int len){
	printf("%c", str[len-1]);
	
	str[len-1] = '\0';
	
	printf("%s", str);
	
}

int main(){
	char* str = malloc(sizeof(char)*6);
	str = "babad";
	
	lsp(str, 5);

	return 0;
}
