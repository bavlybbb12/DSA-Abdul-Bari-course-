#include <iostream>
using namespace std ;

int main () {

    //First type of 2D array declaration and initialization , all in stack
    int arr[3][2] = { {1, 2} , {4, 5} , {7, 8} } ;

    //Second type of 2D array declaration and initialization , partly in stack and partly in heap
    int* ptr[3] ;
    ptr[0] = new int[2] ;
    ptr[1] = new int[2] ;
    ptr[2] = new int[2] ;

    //Third type of 2D array declaration and initialization , all in heap
    int** ptr2 = new int*[3] ;
    ptr2[0] = new int[2] ;
    ptr2[1] = new int[2] ;
    ptr2[2] = new int[2] ;

    //To access any element of the 2D array, we can use the following syntax :
    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = 0 ; j < 2 ; j++ ) {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }


}