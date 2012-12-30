#include <iostream>
#include <vector>
using namespace std;

vector<int> findIntersectionFromTwoSortedArrays(vector<int> a, vector<int> b) {
    vector<int> result;
    int la = a.size(), lb = b.size(), i = 0, j = 0;
    while(i < la && j < lb) {
        if(a[i] > b[j])
            j++;
        else if(a[i] < b[j])
            i++;
        else {
            result.push_back(a[i]);
            i++;
            j++;
        }
    }
    return result;
}

main()
{
    int a[5] = {1, 3, 4, 5, 7};
    int b[6] = {1, 5, 7, 9, 10, 11};
    vector<int> aa(a, a + 5);
    vector<int> bb(b, b + 6);
    vector<int> r = findIntersectionFromTwoSortedArrays(aa, bb);
    for(int i = 0; i < r.size(); i++)
        cout << r[i] << endl;
}
