#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int worker, vulnteer;
    cin >> worker >> vulnteer;
    vector<int> workers(worker);
    vector<int> vs(worker);
    for (int i = 0; i < worker; ++i) {
        cin >> workers[ i ];
    }

    sort(workers.begin(), workers.end(),
         [](int lhs, int rhs) { return lhs > rhs; });

    int first = 0, more = 0;
    int sum = 0;
    while (vulnteer--) {
        int firstV = 0;
        if (first < workers.size()) firstV = workers[ first ];
        int moreV = 0;
        if (more < workers.size()) moreV = workers[ more ] / 10;
        if (firstV >= moreV) {
            sum += firstV;
            ++vs[ first ];
            ++first;
        } else {
            sum += moreV;
            ++vs[ more ];
            if (vs[ more ] >= 4) ++more;
        }
    }
    cout << sum << endl;
    return 0;
}
