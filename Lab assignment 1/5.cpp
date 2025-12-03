#include<iostream>
using namespace std;

int main() {

    int rows,cols;
    int arr[100][100];

    cout<<"Enter no of rows :";
    cin>>rows;
    cout<<"Enter no of columns :";
    cin>>cols;

    cout<<"Enter no of elements";
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<rows; i++){
        int sumrows = 0;
        for(int j=0; j<cols; j++){
            sumrows = sumrows + arr[i][j];
        }
        cout<<"Sum of rows : "<< i+1 << "=" <<sumrows<<endl;
    }

    for(int j=0;j<cols;j++){
        int sumcols = 0;
        for(int i=0;i<rows;i++){
            sumcols += arr[i][j];
        }
        cout<<" Sum of cols : "<< j+1<< "=" <<sumcols<<endl;
    }

    return 0;
}