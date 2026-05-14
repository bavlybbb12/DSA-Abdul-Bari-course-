#include <iostream>
#include <stack>
#include <string>
using namespace std ;

int main () {

    string expression ;
    cout << "Enter an expression: " ;
    getline(cin, expression) ;

    stack <char> stackk ;

    for ( char ch : expression ) {

        if ( ch == '(' ) stackk.push(ch) ;
        else if ( ch == ')' ) {
            if ( stackk.empty() ) {
                cout << "Unmatched parenthesis found at position " << &ch - &expression[0] << endl;
                return 0 ;
            }
            stackk.pop() ;
        }   

    }

    if ( !stackk.empty() ) {
        cout << "Unmatched parenthesis found" << endl;
        return 0 ;
    }

    cout << "All parentheses are matched" << endl;
    return 0 ;
}