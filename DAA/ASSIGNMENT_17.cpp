#include <bits/stdc++.h>
using namespace std;

int fib[100100];

int fibonacci(int n) {
    if (n == 0 || n == 1) return n;
    if (fib[n] != -1) return fib[n];
    return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the position in Fibonacci series: ";
    cin >> n;

    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;

    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
