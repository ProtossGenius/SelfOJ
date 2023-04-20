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
    string a, b;
    cin >> a >> b;
    string ans;
    for (int i = 0; i < a.length(); ++i) {
        for (int j = i + ans.length(); j <= a.length(); ++j) {
            string str = a.substr(i, j - i);
            if (b.find(str) != string::npos) {
                ans = str;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
