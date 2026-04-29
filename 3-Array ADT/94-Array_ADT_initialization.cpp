#include<iostream>
using namespace std ;

struct Array {

    int* address ;
    int size ;
    int length ;

};

void display ( struct Array arr) {

    cout << "Elements are : \n" ;
    for ( int i = 0 ; i < arr.length ; i ++ ) cout << arr.address[i] << ", " ;

}

int main () {

    cout << "Enter size of array needed: \n" ;
    int size ;
    cin >> size ;
    
    int* address = new int [size] ;
    
    struct Array arr = { address, size, 0 } ;

    cout << "Enter number of elements you want to insert: \n" ;
    cin >> arr.length ;
    
    cout << "Enter the elements: \n" ;
    for ( int i = 0 ; i < arr.length ; i ++ ) cin >> arr.address[i] ;

    display ( arr ) ;

}