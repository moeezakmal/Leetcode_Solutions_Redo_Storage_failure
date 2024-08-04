// Time: O(2^n)
// Space: O(n)

#include <stdlib.h>
#include <stdio.h>

// int fib(int n){
//     if (n == 0 || n == 1)
//         return n;
//     else
//         return fib(n-1) + fib(n-2);
// }

/*----------------------------------------*/


// Time: O(n)
// Space: ~O(2n) => O(n)

int fib(int n){
    return fibonacci(n, (int*)calloc((n+1),sizeof(int)));
}

int fibonacci(int i, int mem[]) {
    if (i == 0 || i == 1)
        return i;
    
    if (mem[i] == 0)
        mem[i] = fibonacci(i-1, mem) + fibonacci(i-2, mem);
    return mem[i];
}