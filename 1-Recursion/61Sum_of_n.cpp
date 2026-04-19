#include <iostream>
using namespace std ;
//loops and the formula are faster than recursion
int sum (int n) {

    if (n == 0)return 0 ;
    else if (n > 0) return sum(n-1)+n ;
    else return sum(n+1)+n ;
}

int main () {

    cout << "Enter number so be summed up to " ;
    int n ;
    cin >> n ;
    cout << sum(n) << endl ;
    return 0 ;

}