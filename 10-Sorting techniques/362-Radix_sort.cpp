#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> output(n);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        vector<int> count(10, 0);

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);
    
    cout << "Sorted array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}