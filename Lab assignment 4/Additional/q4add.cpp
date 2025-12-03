#include <iostream>
#include <vector>
using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    int cnt0 = 0, cnt1 = 0;
    for (int s : students) {
        if (s == 0) cnt0++;
        else cnt1++;
    }

    for (int top : sandwiches) {
        if (top == 0) {
            if (cnt0 == 0) break;
            cnt0--;
        } else {
            if (cnt1 == 0) break;
            cnt1--;
        }
    }
    // remaining students = remaining sandwiches not taken
    return cnt0 + cnt1;
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    cout << countStudentsUnableToEat(students, sandwiches) << endl; 
    return 0;
}
