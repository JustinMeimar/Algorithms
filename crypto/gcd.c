#include <stdio.h>

/**
Euclidian Greatest Common Divisor Algorithm
08/15/2023
*/

int gcd(int x, int y)
{
    printf("x: %d, y: %d\n", x, y);
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }

    if (x < y) {
        int new_y = (y - x);
        gcd(x, new_y);
    } else if (y < x) {
        int new_x = (x - y);
        gcd(new_x, y);
    } else {
        return x;
    }
}

int main() {
    
    gcd(18, 48);
    gcd(48, 18);
    gcd(1, 1);
    gcd(7, 13);
    gcd(512, 2008);
    
    return 0;
}


/**
Running Time Analysis:

W.C x is prime, y is prime: O(2N) 

x, y
13, 11
2, 11
2, 9 
2, 7 
2, 5
2, 3
2, 1
1, 1 ==> RETURN 1
*/