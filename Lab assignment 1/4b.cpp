<<<<<<< HEAD
#include <iostream>
using namespace std;

int main() {
    int m, n, p, q;

    // Input size of first matrix
    cout << "Enter rows and columns of first matrix: ";
    cin >> m >> n;

    // Input size of second matrix
    cout << "Enter rows and columns of second matrix: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int A[50][50], B[50][50], C[50][50] = {0};

    // Input first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
=======
#include <iostream>
using namespace std;

int main() {
    int m, n, p, q;

    // Input size of first matrix
    cout << "Enter rows and columns of first matrix: ";
    cin >> m >> n;

    // Input size of second matrix
    cout << "Enter rows and columns of second matrix: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int A[50][50], B[50][50], C[50][50] = {0};

    // Input first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
>>>>>>> 977b011 (files uploaded)
