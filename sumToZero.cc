#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sumToZero(vector<int> d) {
    sort(d.begin(), d.end());
    int len = d.size(), i = 0, j, k = len - 1, sum;
    for(i = 0; i < len - 1; i++) {
        j = i + 1;
        k = len - 1;
        while(j < k) {
            sum = d[i] + d[j] + d[k];
            if(sum == 0) {
                cout << d[i] << " " << d[j] << " " << d[k] << endl;
                k--; 
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                j++;
            }
        } 
    }
}

main()
{
    int a[] = {-1, 6, 2, -2, 8, 3, 0, 1, -3, -11, 12};
    vector<int> d(a, a + sizeof(a) / sizeof(a[0]));
    sumToZero(d);
}
