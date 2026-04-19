#include <iostream>
using namespace std ;

double power ( double b , int r ) {
    
    if (  r == 0 ) return 1 ;
    else if ( r % 2 == 0 ) return power ( b*b , r/2 ) ;
    else return b * power ( b , r-1 ) ;

}

double factorial ( int n ) {

    if ( n == 0 ) return 1 ;
    else return factorial(n-1)*n ;

}

double taylor ( double x , int n ) {

    if ( n == 0 ) return 1 ;
    else return power(x , n)/factorial(n) + taylor( x , n-1 ) ;
}

int main () {

    double x ;
    int n ;
    cout << "Enter value of the base and its power : " ;
    cin >> x >> n ;
    cout << taylor(x,n) << endl ;
    return 0 ;

}