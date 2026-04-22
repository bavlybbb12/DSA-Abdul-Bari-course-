#include <iostream>
using namespace std;

int main () {

    int n ;
    cout << "Enter the size of the original array : " ;
    cin >> n ;

    int *arr = new int[n] ;

    cout << "Enter the elements of the original array : " ;
    for (int i = 0 ; i < n ; i++) cin >> arr[i] ;

    int news ;
    cout << "Enter the size of the new array : " ;
    cin >> news ;

    int* newarr = new int[news] ;

    for ( int i = 0 ; i < n ; i++ ) newarr[i] = arr[i] ;

    cout << "The elements of the new array are : " ;

    for ( int i = 0 ; i < news ; i++ ) cout << newarr[i] << " " ;

    int choice ;
    cout << "\nDo you want to add more elements to the new array ? \n( type : 1 for yes , type : 0 for no) : " ;
    cin >> choice ;

    if ( choice == 1 ) {

        int add ;
        cout << "Enter the number of elements you want to add : " ;
        cin >> add ;

        for ( int i = 0 ; i < add ; i ++ ) {

            cout << "Enter the element to be added and their position in the new array ( position should be greater than " << news - 1 << " ) : " ;

            cin >> newarr[news + i] ;

            if ( news + i < news + add ) cout << "Element added successfully ! \n" ;
            else {cout << "Position is out of range ! \n" ; return ; }

        }

    }

    else if ( choice == 0 ) cout << "No more elements will be added to the new array ! \n" ;
    
    else cout << "Invalid choice ! \n" ;

}