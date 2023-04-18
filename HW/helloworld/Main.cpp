#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string walk;
    while (cin >> walk) {
        int nums[ 200 ]{0};
        for (char c : walk) {
            nums[ int(c) ]++;
        }
        cout << (nums[ int('W') ] - nums[ int('S') ]) / 2 +
                    (nums[ int('A') ] - nums[ int('D') ]) / 2
             << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
