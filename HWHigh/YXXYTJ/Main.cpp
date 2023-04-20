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
    map<int, int> card;
    int           n;
    cin >> n;
    int id;

    int nums[ 35 ];
    for (int i = 0; i < 30; ++i) {
        cin >> nums[ i ];
    }

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < nums[ i ]; ++j) {
            cin >> id;
            card[ id ]++;
        }
    }

    vector<pair<int, int>> pairs;
    for (pair<int, int> p : card) {
        pairs.emplace_back(p);
    }

    sort(pairs.begin(), pairs.end(),
         [](auto &lhs, auto &rhs) { return lhs.second > rhs.second; });

    for (int i = 0; i < 5; ++i) {
        if (i) cout << " ";

        cout << pairs[ i ].first;
    }
    cout << endl;
    return 0;
}
