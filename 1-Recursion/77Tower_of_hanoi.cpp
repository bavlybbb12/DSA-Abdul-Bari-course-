#include <iostream>
using namespace std;

void TOH( int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    TOH(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    TOH(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    cout << "The sequence of moves is:" << endl;
    TOH(n, 'A', 'C', 'B'); 
    
    return 0;
}