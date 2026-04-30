#include<iostream>
using namespace std ;

struct Array {

    int* address ;
    int size ;
    int length ;

};

void get ( struct Array& arr , int index ) {

    if ( index >=0 && index < arr.length ) cout << "Element at index " << index << " is : " << arr.address[index] << "\n" ;
    else cout << "Invalid index, cannot get element \n" ;

}

void sum ( struct Array& arr ) {

    int s = 0 ;
    for ( int i = 0 ; i < arr.length ; i ++ ) s += arr.address[i] ;
    cout << "Sum of all elements in array is : " << s << "\n" ;

}

void maximum ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int max = arr.address[0] ;
        for ( int i = 1 ; i < arr.length ; i ++ ) {
            if ( arr.address[i] > max ) max = arr.address[i] ;
        }
        cout << "Maximum element in array is : " << max << "\n" ;
    }

    else cout << "Array is empty, cannot find maximum \n" ;

}

void minimum ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int min = arr.address[0] ;
        for ( int i = 1 ; i < arr.length ; i ++ ) {
            if ( arr.address[i] < min ) min = arr.address[i] ;
        }
        cout << "Minimum element in array is : " << min << "\n" ;
    }

    else cout << "Array is empty, cannot find minimum \n" ;

}

void changer ( struct Array& arr, int index, int x ) {

    if ( index >=0 && index < arr.length ) {
        arr.address[index] = x ;
        cout << "Array after changing : \n" ;
        display ( arr ) ;
    }

    else cout << "Invalid index, cannot change element \n" ;

}

void binary_search ( struct Array& arr , int key , int low , int high ) {
    if ( low <= high ) {

        int mid = ( low + high ) / 2 ;
        if ( arr.address[mid] == key ) {
            cout << "Element found at index : " << mid << "\n" ;
            return ;
        }

        else if ( arr.address[mid] > key ) binary_search ( arr, key, low, mid - 1 ) ;
        else binary_search ( arr, key, mid + 1, high ) ;

    }

    else cout << "Element not found in array \n" ;
}

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

void reverse ( struct Array& arr ) {

    for ( int i = 0, j = arr.length - 1 ; i < j ; i ++, j -- ) {
        int temp = arr.address[i] ;
        arr.address[i] = arr.address[j] ;
        arr.address[j] = temp ;
    }

    cout << "Array after reversing : \n" ;
    display ( arr ) ;

}

void shift_left ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[0] ;
        for ( int i = 0 ; i < arr.length - 1 ; i ++ ) arr.address[i] = arr.address[i+1] ;
        arr.address[arr.length - 1] = x ;
        cout << "Array after left shift : \n" ;
        display ( arr ) ;
    }

}

void shift_right ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[arr.length - 1] ;
        for ( int i = arr.length - 1 ; i > 0 ; i -- ) arr.address[i] = arr.address[i-1] ;
        arr.address[0] = x ;
        cout << "Array after right shift : \n" ;
        display ( arr ) ;
    }

}

void rotate_left ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[0] ;
        for ( int i = 0 ; i < arr.length - 1 ; i ++ ) arr.address[i] = arr.address[i+1] ;
        arr.address[arr.length - 1] = x ;
        cout << "Array after left rotation : \n" ;
        display ( arr ) ;
    }

}

void rotate_right ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[arr.length - 1] ;
        for ( int i = arr.length - 1 ; i > 0 ; i -- ) arr.address[i] = arr.address[i-1] ;
        arr.address[0] = x ;
        cout << "Array after right rotation : \n" ;
        display ( arr ) ;
    }

}

void shift_right ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[arr.length - 1] ;
        for ( int i = arr.length - 1 ; i > 0 ; i -- ) arr.address[i] = arr.address[i-1] ;
        arr.address[0] = x ;
        cout << "Array after right shift : \n" ;
        display ( arr ) ;
    }

}

void rotate_left ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[0] ;
        for ( int i = 0 ; i < arr.length - 1 ; i ++ ) arr.address[i] = arr.address[i+1] ;
        arr.address[arr.length - 1] = x ;
        cout << "Array after left rotation : \n" ;
        display ( arr ) ;
    }

}

void rotate_right ( struct Array& arr ) {

    if ( arr.length > 0 ) {
        int x = arr.address[arr.length - 1] ;
        for ( int i = arr.length - 1 ; i > 0 ; i -- ) arr.address[i] = arr.address[i-1] ;
        arr.address[0] = x ;
        cout << "Array after right rotation : \n" ;
        display ( arr ) ;
    }

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

    get ( arr, 2 ) ;

    binary_search ( arr, 10, 0, arr.length - 1 ) ;

    maximum ( arr ) ;

    minimum ( arr ) ;

    sum ( arr ) ;

    reverse ( arr ) ;
    shift_left ( arr ) ;
    shift_right ( arr ) ;
    rotate_left ( arr ) ;
    rotate_right ( arr ) ;
}