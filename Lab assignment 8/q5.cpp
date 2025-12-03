#include <iostream>
#include <vector>
using namespace std;

void heapify_max(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify_max(a, n, largest);
    }
}


void heapSortAscending(vector<int>& a) {
    int n = (int)a.size();
    
    for (int i = n/2 - 1; i >= 0; --i)
        heapify_max(a, n, i);

    
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);        
        heapify_max(a, i, 0);    
    }
}

void heapify_min(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify_min(a, n, smallest);
    }
}

void heapSortDescending(vector<int>& a) {
    int n = (int)a.size();
    for (int i = n/2 - 1; i >= 0; --i)
        heapify_min(a, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);         
        heapify_min(a, i, 0);     
    }
}

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << '\n';
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    vector<int> a1 = arr;
    heapSortAscending(a1);
    cout << "Sorted ascending: ";
    printArray(a1);

    vector<int> a2 = arr;
    heapSortDescending(a2);
    cout << "Sorted descending: ";
    printArray(a2);

    return 0;
}
