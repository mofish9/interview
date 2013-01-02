#include <iostream>
#include <stack>
using namespace std;

class StackWithMin
{
private:
    stack<int> data;
    stack<int> min;
public:
    int pop();
    void push(int x);
    int getMin();
};

void StackWithMin::push(int x)
{
    if(data.empty()) {
        data.push(x);
        min.push(x);
    } else {
        data.push(x);
        int y = min.top();
        min.pop();
        if(x < y)
            min.push(x);
        else
            min.push(y);
    }
}

int StackWithMin::pop()
{
    int x = data.top();
    data.pop();
    return x;
}

int StackWithMin::getMin() 
{
    return min.top();
}

int main()
{
    StackWithMin s;
    for(int i = 5; i < 10; i++)
        s.push(i);
    s.push(3);
    s.push(12);
    cout << s.getMin() <<endl;
}
