#include <iostream>
using namespace std ;

void B(int n); 

void A (int n) {
    if (n > 0) {
        cout << n << "A " ;
        B(n-1) ;
    }
}

void B (int n) {
    if (n > 0) {
        cout << n << "B " ;
        A(n/2) ;
    }
}

int main () {
    int n = 20 ;
    A(n) ;
    return 0 ;
}