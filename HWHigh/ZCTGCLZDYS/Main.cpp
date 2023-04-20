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

#ifdef ONLY_TEST
#define debug cout
#else
class _debug {};
template <class T> _debug &operator<<(_debug &d, const T &t) { return d; }
static _debug              debug;
#endif

int main(int argc, char *argv[]) {
    int         n;
    vector<int> car;

    while (cin >> n) {
        car.push_back(n);
    }
    int nums[ 5 ]{0};
    int ans = 0;
    for (int i = 0; i < car.size() - 1; ++i) {
        nums[ car[ i ] ]++;
        if (i >= n) nums[ car[ i - n ] ]--;
        ans = max(ans, nums[ car[ i ] ]);
    }

    cout << ans << endl;
    return 0;
}
