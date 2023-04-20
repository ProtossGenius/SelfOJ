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
    int m, n, v;
    cin >> m >> n;
    map<int, vector<pair<int, int>>> pos;
    vector<vector<int>>              rect;
    for (int i = 0; i < m; ++i) {
        rect.push_back(vector<int>(n));
        for (int j = 0; j < n; ++j) {
            cin >> v;
            rect[ i ][ j ] = v;

            pos[ v ].push_back({i, j});
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) cout << " ";
            int v = rect[ i ][ j ];
            if (pos[ v ].size() == 1) {
                cout << -1;
                continue;
            }

            int ans = m + n + 5;
            for (auto &p : pos[ v ]) {
                if (p.first == i && p.second == j) continue;
                ans = min(ans, abs(p.first - i) + abs(p.second - j));
            }

            cout << ans;
        }

        cout << endl;
    }
    return 0;
}
