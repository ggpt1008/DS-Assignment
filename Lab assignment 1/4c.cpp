
#include<iostream>
using namespace std;

int main() {
    int n,m;
    cout<<"Enter no. of rows ";
    cin>>n;
    cout<<"Enter no. of columns ";
    cin>>m;
    cout<<"Enter elements of array ";

    int arr[n][m];   

    // Input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[j][i]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}
