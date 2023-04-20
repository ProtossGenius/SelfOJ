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

void remove_target(deque<pair<int, int>> &que, int &target, int &ans) {
    ++target;
    auto &front = que.front();

    if (front.first == target - 1) {
        if (front.second != front.first)
            front.first++;
        else
            que.pop_front();
        return;
    }
    ++ans;
    int size = que.size();
    que.clear();
    que.push_back({target, target + size - 1});
}
void head_add(deque<pair<int, int>> &que, int num) {
    que.push_front({num, num});
}
void tail_add(deque<pair<int, int>> &que, int num) {
    que.push_back({num, num});
}
int main(int argc, char *argv[]) {
    int n;

    cin >> n;
    deque<pair<int, int>> que;
    string                cmd;
    int                   target = 1;
    int                   ans    = 0;
    int                   num    = 0;
    for (int i = n * 2; i > 0; --i) {
        cin >> cmd;
        switch (cmd[ 0 ]) {
        case 'r':
            remove_target(que, target, ans);
            break;
        case 'h':
            cin >> cmd >> num;
            head_add(que, num);
            break;
        case 't':
            cin >> cmd >> num;
            tail_add(que, num);
            break;
        }
    }

    cout << ans << endl;
}
