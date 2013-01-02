#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printPairSumToValue(vector<int> d, int target) {
    int i = 0, j = d.size() - 1;
    sort(d.begin(), d.end());
    while(i < j) {
        int sum = d[i] + d[j];
        if(sum == target) {
            cout << d[i] << ":" << d[j] << endl;
            i++;
        } else if(sum > target)
            j--;
        else
            i++;
    }
}

main()
{
    int d[10] = {3, 6, 7, 4, 5, 2, 8, 1, 9, 10};
    vector<int> data(d, d + 10);
    printPairSumToValue(data, 10);
}
