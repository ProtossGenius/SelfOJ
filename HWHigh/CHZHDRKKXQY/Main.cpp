#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> closeDoor(char rect[ 250 ][ 250 ], int m, int n) {
    for (int i = 1; i < m; ++i) {
        if (rect[ i ][ 0 ] != 'X' && rect[ i - 1 ][ 0 ] != 'X') {
            rect[ i ][ 0 ] = rect[ i - 1 ][ 0 ] = 'C';
        }
        if (rect[ i ][ n - 1 ] != 'X' && rect[ i - 1 ][ n - 1 ] != 'X') {
            rect[ i ][ n - 1 ] = rect[ i - 1 ][ n - 1 ] = 'C';
        }
    }

    for (int i = 1; i < n; ++i) {
        int dm = 0;
        if (rect[ dm ][ i ] != 'X' && rect[ dm ][ i - 1 ] != 'X') {
            rect[ dm ][ i ] = rect[ dm ][ i - 1 ] != 'C';
        }
        dm = m - 1;
        if (rect[ dm ][ i ] != 'X' && rect[ dm ][ i - 1 ] != 'X') {
            rect[ dm ][ i ] = rect[ dm ][ i - 1 ] = 'C';
        }
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < m; ++i) {
        if (rect[ i ][ 0 ] == 'O') res.push_back({i, 0});
        if (rect[ i ][ n - 1 ] == 'O') res.push_back({i, n - 1});
    }
    for (int i = 0; i < n; ++i) {
        if (rect[ 0 ][ i ] == 'O') res.push_back({0, i});
        if (rect[ m - 1 ][ i ] == 'O') res.push_back({m - 1, i});
    }
    return res;
}
const vector<pair<int, int>> adds{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int inRange(int x, int size) { return x >= 0 && x <= size; }
int getSize(char rect[ 250 ][ 250 ], int m, int n, pair<int, int> point) {
    int                   size = 0;
    queue<pair<int, int>> q;
    q.push(point);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        size += 1;
        rect[ p.first ][ p.second ] = 'D';
        for (const auto &add : adds) {
            int x = p.first + add.first;
            int y = p.second + add.second;
            if (inRange(x, m) && inRange(y, n)) {
                if (rect[ x ][ y ] != 'O') continue;

                q.push({x, y});
            }
        }
    }

    return size;
}

int main(int argc, char *argv[]) {
    char rect[ 250 ][ 250 ];

    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> rect[ i ];
    }

    auto           points = closeDoor(rect, m, n);
    int            ans    = -1;
    pair<int, int> maxPoint;
    for (const auto &point : points) {
        int size = getSize(rect, m, n, point);
        if (size > ans) {
            ans      = size;
            maxPoint = point;
        }
    }

    if (ans == -1) {
        cout << "NULL" << endl;
    } else {
        cout << maxPoint.first << " " << maxPoint.second << " " << ans << endl;
    }
}
