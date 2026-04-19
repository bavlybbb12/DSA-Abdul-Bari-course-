#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(100, -1);

unsigned long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter a number (up to 93): ";
    cin >> n;
    
    if (n > 93) {
        cout << "Warning: Number too large! Program terminated." << endl;
        return 1;
    } else {
        cout << fib(n) << endl;
    }
    
    return 0;
}