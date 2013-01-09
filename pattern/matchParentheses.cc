#include <iostream>
#include <stack>
using namespace std;

bool checkParentheses(char *str, int len) {
    int i = 0;
    stack<char>s;
    for(i = 0; i < len; i++) {
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')') {
            if(s.top() == '(')
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())
        return true;
    return false;
}

main()
{
    char *str = "()(())(abc)";
    cout << checkParentheses(str, 11) << endl;
}
