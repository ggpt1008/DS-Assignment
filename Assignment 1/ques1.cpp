// 1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT



#include <iostream>
using namespace std;

int main() {
    int arr[100];         
    int n = 0;    // current size of array
    int choice;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        // 1) CREATE ARRAY
        case 1: {
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            break;
        }

        // 2) DISPLAY ARRAY
        case 2: {
            if (n == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Array elements: ";
                for(int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }

        // 3) INSERT ELEMENT
        case 3: {
            int pos, val;
            cout << "Enter position to insert (0 - " << n << "): ";
            cin >> pos;
            cout << "Enter value to insert: ";
            cin >> val;

            if(pos < 0 || pos > n) {
                cout << "Invalid position!\n";
            } else {
                for(int i = n; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos] = val;
                n++;
                cout << "Element inserted.\n";
            }
            break;
        }

        // 4) DELETE ELEMENT
        case 4: {
            int pos;
            cout << "Enter position to delete (0 - " << n-1 << "): ";
            cin >> pos;

            if(pos < 0 || pos >= n) {
                cout << "Invalid position!\n";
            } else {
                for(int i = pos; i < n-1; i++) {
                    arr[i] = arr[i+1];
                }
                n--;
                cout << "Element deleted.\n";
            }
            break;
        }

        // 5) LINEAR SEARCH
        case 5: {
            int key, found = -1;
            cout << "Enter element to search: ";
            cin >> key;

            for(int i = 0; i < n; i++) {
                if(arr[i] == key) {
                    found = i;
                    break;
                }
            }

            if(found == -1)
                cout << "Element not found.\n";
            else
                cout << "Element found at position " << found << endl;

            break;
        }

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}
