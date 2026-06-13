#include <iostream>
#include <vector>
using namespace std;

void bubbleSort ( vector<int>& arr) {
    
    if (arr.empty()) return;

    for ( int i = 0; i < arr.size()-1; i++){

        int flag = 0;
        
        for ( int j = 0; j < arr.size()-i-1; j++){
            
            if ( arr[j] > arr[j+1]) { 
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
          
        }
        if ( flag == 0) break;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}