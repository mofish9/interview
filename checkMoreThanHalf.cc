#include <iostream>
#include <map>
using namespace std;

bool checkMoreThanHalf(int data[], int length) {
    map<int, int> mapper;
    int i = 0;
    map<int, int>::iterator it;
    for(; i < length; i++) {
        bool found = false;
        for(it = mapper.begin(); it != mapper.end(); it++) {
            if(data[i] % 10 == (*it).first % 10) {
                (*it).second++;
                found = true;
            }
        }
        if(!found)
            mapper.insert(pair<int, int>(data[i], 1));
    }
    for(it = mapper.begin(); it != mapper.end(); it++) {
        if((*it).second > length / 2)
            return true;
    }
    return false;
}

main()
{
    int data[10] = {1, 110, 213, 314, 415, 51, 61, 72, 82, 92};
    cout << checkMoreThanHalf(data, 10) << endl;
}
