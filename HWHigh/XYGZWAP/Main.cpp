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

int valueof(vector<int> &arr, int pos) {
    return pos < 0 || pos >= arr.size() ? 0 : arr[ pos ];
}

int main(int argc, char *argv[]) {
    vector<int> pos;
    int         v;
    while (cin >> v) {
        pos.push_back(v);
    }
    int         begin = -1;
    vector<int> lx(pos.size());
    for (int i = 0; i < pos.size(); ++i) {
        if (pos[ i ] == 1 && begin == -1) {
            begin = i;
        }
        if (pos[ i ] != 1 && begin != -1) {
            pos[ begin ] = i - begin;
            pos[ i - 1 ] = pos[ begin ];
            begin        = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < pos.size(); ++i) {
        if (pos[ i ] != 0) continue;
        ans = max(ans, valueof(pos, i - 1) + valueof(pos, i + 1));
    }

    cout << ans << endl;
    return 0;
}
