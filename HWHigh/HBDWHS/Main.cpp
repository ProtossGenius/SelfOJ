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

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
double getValue(const string &str, map<string, double> &dict) {
    int    begin   = 0;
    double value   = 0;
    double ans     = 0;
    bool   readNum = true;
    for (int i = 0; i < str.size(); ++i) {
        if (isLetter(str[ i ]) && readNum) {
            readNum = false;
            value   = stod(str.substr(begin, i - begin));
            begin   = i;
        }
        if ((i == str.size() - 1) || (!isLetter(str[ i ]) && !readNum)) {
            int end = (i == str.size() - 1) ? str.size() : i;
            readNum = true;
            ans += value * dict[ str.substr(begin, end - begin) ];
            begin = i;
        }
    }

    return ans;
}
int main(int argc, char *argv[]) {
    map<string, double> values{{"JPY", 1825.0},     {"HKD", 123.0},
                               {"EUR", 14.0},       {"GBP", 12.0},
                               {"cents", 12300},    {"sen", 182500},
                               {"eurocents", 1400}, {"pence", 1200}};

    // init values
    for (auto &it : values) {
        it.second = 10000.0 / it.second;
    }
    values[ "CNY" ] = 100;
    values[ "fen" ] = 1;

    int n;
    while (cin >> n) {
        string money;
        double ans = 0;
        while (n--) {
            cin >> money;
            ans += getValue(money, values);
        }

        cout << int(ans) << endl;
    }
    return 0;
}
