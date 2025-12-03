#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> h;

    void up(int i) {
        while (i > 0 && h[(i-1)/2] < h[i]) {
            swap(h[(i-1)/2], h[i]);
            i = (i-1)/2;
        }
    }

    void down(int i) {
        int n = h.size();
        while (true) {
            int l = 2*i + 1, r = 2*i + 2, big = i;
            if (l < n && h[l] > h[big]) big = l;
            if (r < n && h[r] > h[big]) big = r;
            if (big == i) break;
            swap(h[i], h[big]);
            i = big;
        }
    }

public:
    void push(int x) {
        h.push_back(x);
        up(h.size() - 1);
    }

    int pop() {
        int mx = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) down(0);
        return mx;
    }

    int top() { return h[0]; }
    bool empty() { return h.empty(); }
};

int main() {
    MaxHeap pq;
    pq.push(40);
    pq.push(10);
    pq.push(30);

    cout << pq.top() << endl;  
    pq.pop();
    cout << pq.top() << endl;  
}
