#include<iostream>
using namespace std;

const int size = 100;
int arr[size];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, value;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    if(pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    cout << "Inserted successfully\n";
}

void del() {
    int pos;
    cout << "Enter position to delete (0 to " << n-1 << "): ";
    cin >> pos;
    if(pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Deleted successfully\n";
}

void linearSearch() {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}

int main() {
    int choice;
    while(true) {
        cout << "\nMENU\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exit\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
