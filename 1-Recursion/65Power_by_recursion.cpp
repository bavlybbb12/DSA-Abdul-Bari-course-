#include <iostream>
using namespace std ;

double power ( double b , int r ) {

    if (r == 0) return 1 ;
    else if ( r % 2 == 0 ) return power ( b*b , r/2 ) ;
    else return b * power ( b , r-1 ) ;

}

int main () {

    double b ;
    int r ;
    cout << "Enter base and exponent : " ;
    cin >> b >> r ;
    cout << power(b,r) << endl ;
    return 0 ;

}