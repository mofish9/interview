#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> v, int target) {
    int low = 0, high = v.size() - 1, mid;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(v[mid] == target) {
            return mid;
        } else if(v[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void findMatch(vector<int> a, vector<int> b) {
    sort(b.begin(), b.end());
    vector<int>::iterator it = a.begin();
    for(; it != a.end(); it++) {
        if(binarySearch(b, *it) != -1)
            cout << *it << endl;
    }
}

main() {
    vector<int> a, b;
    for(int i = 0; i < 10; i++) {
        a.push_back(i);
        b.push_back(2 * i);
    }
    findMatch(a, b);
}
