#include <iostream>
using namespace std;

int triDiagonal(int n)
{
    int tri[50];
    cout << "Enter " << 3 * n - 2 << " elements (lower, diag, upper): ";
    for (int i = 0; i < 3 * n - 2; i++)
        cin >> tri[i];

    cout << "Tri-Diagonal Matrix:\n";
    int k1 = 0, k2 = n - 1, k3 = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << tri[k2 + i] << " ";
            else if (i == j + 1)
                cout << tri[k1 + j] << " ";
            else if (j == i + 1)
                cout << tri[k3 + i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
