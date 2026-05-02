#include <iostream>
#include <vector>
using namespace std;

class diagonal{
    
    private:
    int n;
    int* A;

    public:

    diagonal(int n) {n = n ; A = new int[n] ;}
    void set (int i , int j , int x );
    void get ( int i , int j );
    void display();
    ~diagonal() { delete []A ; }

};

void diagonal :: set (int i , int j , int x )
{
    if (i == j)
        A[i-1] = x ;
}

void diagonal :: get ( int i , int j )
{
    if (i == j)
        cout << A[i-1] << endl ;
    else
        cout << "0" << endl ;
}

void diagonal :: display()
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (i == j)
                cout << A[i-1] << " " ;
            else
                cout << "0 " ;
        }
        cout << endl ;
    }
}

int main()
{
    int n ;
    cout << "Enter the size of the matrix of the diagonal matrix : " ;
    cin >> n ;
    diagonal d(n) ;
    d.set(1,1,5) ;
    d.set(2,2,10) ;
    d.set(3,3,15) ;
    d.display() ;
    return 0 ;
}