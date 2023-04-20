#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    int pos[ 10005 ]{0};
    int p;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        sum += p;
        pos[ p ] = p;
    }

    int bestDist = sum;
    int ans      = 0;
    int cnt      = 0;
    int leftSum  = 0;
    for (int i = 0; i <= 10000; ++i) {
        int exist = 0;
        if (pos[ i ]) exist = 1;
        int dist = i * cnt - leftSum + sum - pos[ i ] - i * (n - cnt - exist);
        if (dist < bestDist) {
            bestDist = dist;
            ans      = i;
        }
        cnt += exist;
        leftSum += pos[ i ];
    }

    cout << ans << endl;

    return 0;
}
