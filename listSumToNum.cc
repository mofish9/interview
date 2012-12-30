#include <iostream>
#include <vector>
using namespace std;

void listSumToNum(int num, vector<int> *item) {
    if(num == 0) {
        vector<int>::iterator it;
        for(it = item->begin(); it != item->end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    for(int i = 1; i <= num; i++) {
        item->push_back(i);
        listSumToNum(num - i, item);
        item->pop_back();
    }
}

main()
{
    vector<int>res;
    listSumToNum(10, &res);
}
