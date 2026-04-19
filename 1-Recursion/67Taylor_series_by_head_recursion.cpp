#include <iostream>
using namespace std ;

double taylor ( double x , int n ){
    
    static double p = 1 , f = 1 ;
    double r ;

    if ( n == 0 ) return 1 ;

    else {
        
        r = taylor ( x , n-1 ) ;
        p *= x ;
        f *= n ;
        return r + p/f ;

    }

}

int main () {

    double x ;
    int n ;
    cout << "Enter value of the base and its power : " ;
    cin >> x >> n ;
    cout << taylor(x,n) << endl ;
    return 0 ;

}