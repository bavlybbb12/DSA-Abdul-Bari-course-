#include<iostream>
using namespace std ;

struct Array {

    int* address ;
    int size ;
    int length ;

};

void display ( struct Array &arr) {

    cout << "Elements are : \n" ;
    for ( int i = 0 ; i < arr.length ; i ++ ) cout << arr.address[i] << ", " ;

}

void linear_search ( struct Array &arr, int key ) {

    for ( int i = 0 ; i < arr.length ; i ++ ) {
        if ( arr.address[i] == key ) {
            cout << "Element found at index : " << i << "\n" ;
            return ;
        }
    }

    cout << "Element not found in array \n" ;

}

void append ( struct Array &arr, int x) {

    if ( arr.length < arr.size ) { 
        arr.address[arr.length ++] = x ;
        cout << "Array after appending : \n" ;
        display ( arr ) ;
    }

    else cout << "Array is full, cannot append \n" ;

}

void delete_element ( struct Array& arr, int index ) {

    if ( index >=0 && index < arr.length ) {

        int x = arr.address[index] ;
        for ( int i = index ; i < arr.length - 1 ; i ++ ) arr.address[i] = arr.address[i+1] ;
        arr.length -- ;
        cout << "Deleted element is : " << x << "\n" ;
        cout << "Array after deleting : \n" ;
        display ( arr ) ;

    }

    else cout << "Invalid index, cannot delete \n" ;

}

void insert ( struct Array &arr, int index, int x ) {

    if ( index >=0 && index <= arr.length && arr.length < arr.size ) {

        for ( int i = arr.length ; i > index ; i -- ) arr.address[i] = arr.address[i-1] ;
        arr.address[index] = x ;
        arr.length ++ ;
        cout << "Array after inserting : \n" ;
        display ( arr ) ;

    }

    else cout << "Invalid index or array is full, cannot insert \n" ;

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

    append ( arr, 10 ) ;
    insert ( arr, 2, 20 ) ;

    display ( arr ) ;

    delete_element ( arr, 2 ) ;

    linear_search ( arr, 10 ) ;

}