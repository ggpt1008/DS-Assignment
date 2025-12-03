#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;

    q.push("1");   // first binary number

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        // Generate next two binary numbers
        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n;
    cout<<"Enter no : ";
    cin >> n;

    generateBinary(n);

    return 0;
}
