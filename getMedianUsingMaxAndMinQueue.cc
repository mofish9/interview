#include <iostream>
#include <queue>
using namespace std;

class GetMedian 
{
    int n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

public:

    GetMedian() {
        n = 0;
    }

    void insert(int d) {
        int toMin, toMax;
        if(n % 2 == 0) {
            maxHeap.push(d);
            n++;
            if(minHeap.size() == 0)
                return;
            if(maxHeap.top() > minHeap.top()) {
                toMin = maxHeap.top();
                toMax = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(toMax);
                minHeap.push(toMin);
            } 
        } else {
            maxHeap.push(d);
            toMin = maxHeap.top();
            maxHeap.pop();
            minHeap.push(toMin);
            n++;
        }
    }

    float getMedian() {
        if(n % 2 == 0)
            return (float)(maxHeap.top() + minHeap.top()) / 2.0f;
        else
            return maxHeap.top();
    }

    int getN() {
        return n;
    }
};

int main()
{
    GetMedian gm;
    for(int i = 0; i < 9; i++)
        gm.insert(i);
    cout << gm.getN() << endl;
    cout << gm.getMedian() << endl;
    return 0;
}
