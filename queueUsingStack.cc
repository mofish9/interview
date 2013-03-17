#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack
{
private:
    stack<int> inbox;
    stack<int> outbox;

public:
    void enqueue(int d) {
        inbox.push(d);
        cout << inbox.top() << endl;
    };
    int dequeue() {
        if(outbox.empty())
        {
	        while(!inbox.empty()) {
	            outbox.push(inbox.top());
	            inbox.pop();
	        }
        }
        int r = outbox.top();
        outbox.pop();
        return r; 
    };
};

int main()
{
    QueueUsingStack q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}
