#include <iostream>
#include <limits.h>
using namespace std;

main()
{
    int a[10] = {4, 7, 3, 9, 10, 1, 2, 5, 15, 13};
    int max = -1, min = INT_MAX;
    for(int i = 0; i < 10; i++) {
        if(a[i] > max)
            max = a[i];
        else if(a[i] < min)
            min = a[i];
    }
    cout << "MAX: " << max << endl;
    cout << "MIN: " << min << endl;
}
