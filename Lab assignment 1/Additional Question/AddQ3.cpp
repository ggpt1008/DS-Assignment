//String Anagrams
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str1, str2;
    cout<<"Enter the 1st string: ";
    cin>>str1;
    cout<<"Enter the 2nd string: ";
    cin>>str2;
    if(str1.length()==str2.length()){
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1 == str2){
            cout<<"The given strings form an anagram pair."<<endl;
        }
        else{
            cout<<"The given strings do not form an anagram pair."<<endl;
        }
    }
    else{
        cout<<"The given strings aren't equal in lenght!"<<endl;
    }

    return 0;
}