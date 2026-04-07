#include <iostream>
using namespace std ;

void trial1 (int n) {

    if (n > 0) {
        trial1(n - 1) ;
        cout << n << " " ;
    }

}

void trial2 (int n) {
       
    if (n > 0) {
        cout << n << " " ;
        trial2(n - 1) ;
    }
    
}

int main() {

    int x = 5 ;
    trial1(x) ;
    cout << endl ;
    trial2(x) ;

}