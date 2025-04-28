#include <iostream>
#include <omp.h>

long long fibonacci(int n){
        if (n<=1) return n;
        long long x, y;

        #pragma omp task shared(x)
        x = fibonacci(n - 1);
        #pragma omp task shared(y)
        y = fibonacci(n - 2);

        #pragma omp taskwait
        return x+y;
}

int main(){
        int n = 10;
        #pragma omp parallel
        #pragma omp single
        std::cout <<fibonacci(n) << std::endl;
        return 0;
}
