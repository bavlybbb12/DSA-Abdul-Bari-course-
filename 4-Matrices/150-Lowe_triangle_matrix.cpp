#include <iostream>
#include <vector>
using namespace std;

class triangle{
    
    private:
    int n;
    int* A;

    public:

    triangle() { n = 0 ; A = nullptr ; }
    triangle(int n) {this-> n = n ; A = new int[n*(n+1)/2] ;}
    void set (int i , int j , int x );
    void get ( int i , int j );
    void display();
    ~triangle() { delete []A ; }

};

void triangle :: set ( int i , int j , int x )
{
    if (i >= j)
        A[i*(i+1)/2 + j-1] = x ;
}

void triangle :: get ( int i , int j )
{
    if (i >= j)
        cout << A[i*(i+1)/2 + j-1] << endl ;
    else
        cout << "0" << endl ;
}

void triangle :: display()
{
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i >= j)
                cout << A[i*(i+1)/2 + j-1] << " " ;
            else
                cout << "0 " ;
        }
        cout << endl ;
    }
}

int main()
{
    int n ;
    cout << "Enter the size of the matrix of the triangle matrix : " ;
    cin >> n ;
    triangle d(n) ;
    d.set(1,1,5) ;
    d.set(2,2,10) ;
    d.set(3,3,15) ;
    d.display() ;
    return 0 ;
}