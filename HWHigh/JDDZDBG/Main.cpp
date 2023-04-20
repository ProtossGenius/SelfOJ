#include <algorithm>
#include <climits>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int sum = 0;
    int n;
    int count = 0;
    while (cin >> n) {
        ++count;
        if (n < 0) n = 0;
        if (n > 255) n = 255;
        sum += n;
    }

    cout << 128 - (sum / count) << endl;
    return 0;
}
