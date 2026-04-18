#include<iostream>
using namespace std;

int fun1 (int n) {
    
    if (n > 0) {
        static int x =0 ;
        x++ ;
        return fun1(n-1)+x ;
    }
    return 0 ;
}

int main() {
    
    int n = 5 ;
    cout << endl << fun1(n) ;
    return 0 ;
}