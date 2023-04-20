#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int taskNums = 0;
    while (cin >> taskNums) {
        vector<int> diff(50005);
        while (taskNums--) {
            int start, end, para;
            cin >> start >> end >> para;
            diff[ start ] += para;
            diff[ end ] -= para;
        }
        int ans = 0, current = 0;
        for (int d : diff) {
            current += d;
            ans = max(ans, current);
        }

        cout << ans << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
