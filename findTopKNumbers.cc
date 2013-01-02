#include <iostream>
#include <queue>
using namespace std;

vector<int> findTopKNumbers(vector<int> data, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int i = 0;
    for(i = 0; i < data.size(); i++) {
        if(minHeap.size() == k) {
            minHeap.pop();
        }
        minHeap.push(data[i]);
    }
    vector<int> res;
    while(minHeap.size() > 0) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    return res;
}

main()
{
    int d[] = {6, 5, 7, 9, 10, 4, 11, 2, 18, 24, 34, 16};
    vector<int> data(d, d + 12);
    vector<int> r = findTopKNumbers(data, 5);
    for(int i = 0; i < r.size(); i++)
        cout << r[i] << endl;
}
