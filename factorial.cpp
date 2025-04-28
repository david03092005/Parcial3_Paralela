#include <iostream>
#include <omp.h>

long long factorial(int start, int end) {
    if (start > end) {
	    return 1;
    }
    if (start == end) {
	    return start;
    }
    if (end - start == 1) {
	    return start * end;
    }
    int mid = (start + end) / 2;
    long long x, y;

    #pragma omp task shared(x)
    x = factorial(start, mid);

    #pragma omp task shared(y)
    y = factorial(mid + 1, end);

    #pragma omp taskwait
    return x * y;
}

int main() {
    int n = 10;
    long long result = 0;

    #pragma omp parallel
    {
        #pragma omp single
        result = factorial(1, n);
    }

    printf("%lld\n", result);
    return 0;
}

