#include <iostream>
#include <algorithm>
using namespace std;

int removeDuplicates(int arr[], int n) {
    sort(arr, arr + n);
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
	cin >> arr[i];
	}
    int newSize = removeDuplicates(arr, n);
    cout << "Unique elements:\n";
    for(int i = 0; i < newSize; i++){
	 cout << arr[i] << " ";
	}
    return 0;
}

