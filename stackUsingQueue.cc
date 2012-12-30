#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

queue<int> q1;
queue<int> q2;

void push(int d) {
    q1.push(d);
}

int pop() {
    if(q1.empty())
        return NULL;
    while(!q1.empty()) {
        int d = q1.front();
        q1.pop();
        if(q1.empty()) {
            queue<int> t = q1;
            q1 = q2;
            q2 = t;
            return d;
        } else
            q2.push(d);
    }
}

main()
{
    push(1);
    push(2);
    push(3);
    //assert(pop() == 3);
    //assert(pop() == 1);
    cout << pop() << endl; 
    cout << pop() << endl;
    cout << pop() << endl;
}
