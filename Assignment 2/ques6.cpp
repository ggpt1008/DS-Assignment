// Write a program to implement the following operations on a Sparse Matrix,
// assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices.


#include <iostream>
using namespace std;

#define MAX 50  // fixed size for triplets

// Function to read sparse matrix in triplet form
void readSparse(int T[][3], int &nz) {
    int rows, cols;
    cout << "Enter total rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> nz;

    T[0][0] = rows;
    T[0][1] = cols;
    T[0][2] = nz;

    cout << "Enter row, col, value for each non-zero:\n";
    for (int i = 1; i <= nz; i++) {
        cin >> T[i][0] >> T[i][1] >> T[i][2];
    }
}

// Function to display triplet
void display(int T[][3]) {
    int nz = T[0][2];
    cout << "\nTriplet Representation:\n";
    for (int i = 0; i <= nz; i++) {
        cout << T[i][0] << "  " << T[i][1] << "  " << T[i][2] << endl;
    }
}

// (a) Transpose of sparse matrix
void transpose(int A[][3], int B[][3]) {
    int rows = A[0][0];
    int cols = A[0][1];
    int nz = A[0][2];

    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = nz;

    int k = 1;

    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nz; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

// (b) Add two sparse matrices
void add(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition Not Possible!\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int nzA = A[0][2], nzB = B[0][2];

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= nzA && j <= nzB) {
        if (A[i][0] < B[j][0] ||
            (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] ||
                (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }

    while (i <= nzA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= nzB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

// (c) Multiplication of sparse matrices
void multiply(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication Not Possible!\n";
        return;
    }

    int nzA = A[0][2], nzB = B[0][2];
    int k = 1;

    C[0][0] = A[0][0];       // rows of A
    C[0][1] = B[0][1];       // cols of B

    for (int i = 1; i <= nzA; i++) {
        for (int j = 1; j <= nzB; j++) {
            if (A[i][1] == B[j][0]) {
                C[k][0] = A[i][0];
                C[k][1] = B[j][1];
                C[k][2] = A[i][2] * B[j][2];
                k++;
            }
        }
    }

    C[0][2] = k - 1;
}

// MAIN MENU
int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int nzA, nzB;

    cout << "Enter Sparse Matrix A:\n";
    readSparse(A, nzA);

    cout << "\nEnter Sparse Matrix B:\n";
    readSparse(B, nzB);

    cout << "\n--- Matrix A ---";
    display(A);

    cout << "\n--- Matrix B ---";
    display(B);

    // Transpose
    transpose(A, C);
    cout << "\nTranspose of A:";
    display(C);

    // Addition
    add(A, B, C);
    cout << "\nAddition (A + B):";
    display(C);

    // Multiplication
    multiply(A, B, C);
    cout << "\nMultiplication (A × B):";
    display(C);

    return 0;
}

