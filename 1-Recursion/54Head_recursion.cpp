#include <iostream>
using namespace std;

void fun ( int n ) {
    if ( n > 0 ) {
        fun(n-1) ;
        cout << n << " " ;
    }
}

int main () {
    int n = 5 ;
    cout << endl ;
    fun(n) ;
    return 0 ;
}