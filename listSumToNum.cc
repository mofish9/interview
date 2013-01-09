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

void listSumToNumWithoutDuplicates(int num, int start, vector<int>*item, int used[]) {
    if(num == 0) {
        vector<int>::iterator it;
        for(it = item->begin(); it != item->end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    for(int i = start; i <= num; i++) {
        if(used[i] == 0) {
            item->push_back(i);
            used[i] = 1;
            listSumToNumWithoutDuplicates(num - i, i + 1, item, used);
            used[i] = 0;
            item->pop_back();
        }
    }
}

main()
{
    vector<int>res;
    int used[11];
    for(int i = 0; i < 11; i++)
        used[i] = 0;
    listSumToNumWithoutDuplicates(10, 1, &res, used);
}
