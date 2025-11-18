// Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
// 𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
// implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix 

// A)
// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter size of diagonal matrix (n x n): ";
//     cin >> n;

//     int diag[n]; // only n elements needed

//     cout << "Enter diagonal elements:\n";
//     for (int i = 0; i < n; i++)
//         cin >> diag[i];

//     cout << "\nDiagonal Matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == j)
//                 cout << diag[i] << " ";
//             else
//                 cout << "0 ";
//         }
//         cout << endl;
//     }
// }

// b)
// #include <iostream>
// using namespace std;

// #define N 5

// int main() {
//     int tri[3 * N - 2];  // fixed size storage

//     cout << "Enter tri-diagonal elements (3N - 2 = " << 3*N-2 << " numbers):\n";
//     for (int i = 0; i < 3 * N - 2; i++) {
//         cin >> tri[i];
//     }

//     cout << "\nTri-diagonal Matrix:\n";
//     int k = 0;

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {

//             if (i == j)                // main diagonal
//                 cout << tri[i] << " ";
//             else if (i == j + 1)       // lower diagonal
//                 cout << tri[N + (i - 1)] << " ";
//             else if (i + 1 == j)       // upper diagonal
//                 cout << tri[N + (N - 1) + i] << " ";
//             else
//                 cout << 0 << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// c)
// #include <iostream>
// using namespace std;

// #define N 5

// int main() {

//     int lower[N * (N + 1) / 2];

//     cout << "Enter lower triangular elements (" << N*(N+1)/2 << " numbers):\n";
//     for (int i = 0; i < N * (N + 1) / 2; i++)
//         cin >> lower[i];

//     cout << "\nLower Triangular Matrix:\n";

//     int k = 0;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             if (i >= j)
//                 cout << lower[k++] << " ";
//             else
//                 cout << 0 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//d)
// #include <iostream>
// using namespace std;

// #define N 5

// int main() {
//     int upper[N * (N + 1) / 2];

//     cout << "Enter upper triangular elements (" << N*(N+1)/2 << " numbers):\n";
//     for (int i = 0; i < N * (N + 1) / 2; i++)
//         cin >> upper[i];

//     cout << "\nUpper Triangular Matrix:\n";

//     int k = 0;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             if (i <= j)
//                 cout << upper[k++] << " ";
//             else
//                 cout << 0 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//e) 
#include <iostream>
using namespace std;

#define N 5

int main() {

    int sym[N * (N + 1) / 2];

    cout << "Enter elements of symmetric matrix (" << N*(N+1)/2 << " numbers):\n";
    for (int i = 0; i < N * (N + 1) / 2; i++)
        cin >> sym[i];

    cout << "\nSymmetric Matrix:\n";

    int k = 0;
    int store[N][N];

    // Fill lower triangular
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            store[i][j] = sym[k++];
        }
    }

    // Copy to upper part
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            store[i][j] = store[j][i];
        }
    }

    // Print matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << store[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
