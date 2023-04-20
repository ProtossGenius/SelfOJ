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
    int T, n;
    cin >> T >> n;
    int         cost, value;
    vector<int> dp(100005);
    for (int i = 0; i < n; ++i) {
        cin >> cost >> value;
        for (int i = T; i >= cost; --i) {
            if (i >= cost) {
                dp[ i ] = max(dp[ i - 1 ], dp[ i - cost ] + value);
            }
        }
    }

    cout << dp[ T ] << endl;

    return 0;
}
