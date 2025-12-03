//String Split, string:lowercase English alphabets, split in 3 substrings where one is substring of other 2
#include<iostream>
using namespace std;
int main(){
    int T;
    cout<<"Enter the no. of Test cases: ";
    cin>>T;
    string s[T];
    for(int i=0; i<T; i++){
        cout<<"Enter the string"<<i+1<<": ";
        cin>>s[i];
    }
    
    return 0;
}