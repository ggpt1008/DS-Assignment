// Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix


// a)
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[100], n;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     // Reverse logic
//     int start = 0, end = n - 1;
//     while (start < end) {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }

//     cout << "Reversed Array: ";
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";

//     return 0;
// }


// b)
// #include <iostream>
// using namespace std;

// int main() {
//     int A[10][10], B[10][10], C[10][10];
//     int m, n, p;

//     cout << "Enter rows & columns of Matrix A (m n): ";
//     cin >> m >> n;

//     cout << "Enter rows of Matrix B must be " << n << ", enter columns (p): ";
//     cin >> p;

//     cout << "Enter Matrix A:\n";
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             cin >> A[i][j];

//     cout << "Enter Matrix B:\n";
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < p; j++)
//             cin >> B[i][j];

//     // Multiply matrices
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < p; j++) {
//             C[i][j] = 0;
//             for (int k = 0; k < n; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }

//     cout << "Result (A × B):\n";
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < p; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// c)
#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int r, c;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    // Transpose
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
