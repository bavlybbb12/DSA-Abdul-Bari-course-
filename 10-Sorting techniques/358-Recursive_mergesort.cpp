#include <iostream>
#include <vector>
using namespace std;

void merge ( vector<int>& arr1, vector<int>& arr2, vector<int>& merged ) {

    if (arr1.empty() && arr2.empty()) return;

    int i = 0, j=0, k=0;

    while ( i < arr1.size() && j < arr2.size()){

        if ( arr1[i] <= arr2[j]) merged[k++] = arr1[i++];
        else merged[k++] = arr2[j++];
    }

    while (i < arr1.size()) {
        merged[k++] = arr1[i++];
    }
    while (j < arr2.size()) {
        merged[k++] = arr2[j++];
    }

    return;
}

void mergeSort ( vector<int>& arr) {

    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    mergeSort (left);
    mergeSort (right);

    merge(left, right, arr);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}