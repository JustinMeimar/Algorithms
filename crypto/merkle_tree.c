#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int get_top_hash(char **strings)
{

}

int main() {
    char string[] = "Hello, World";


    printf("string: %s, hash: %ld", string, hash(string)); 
    return 0;
}
