#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool isZero(map<char, int> copy) {
    for (auto &it : copy) {
        if (it.second != 0) return false;
    }
    return true;
}
int deal(char *str) {
    int            strLen = strlen(str);
    int            count  = strLen / 4;
    map<char, int> dic;

    // 计算每个位置和预期相差几个
    for (int i = 0; i < strLen; i++) {
        char c = str[ i ];
        if (dic.count(c))
            dic[ c ] = dic[ c ] + 1; //保存k-v 字符-个数+1
        else
            dic[ c ] = 1 - count; //字符-需要的个数(用负数表示, 最后才能归0)
    }                             //比如AASW 就是 [A,1] [S,0] [W,0]

    int ans = strLen;
    for (int i = 0; i < strLen; i++) {
        int            res = 0;
        map<char, int> copy(dic);

        if (copy[ str[ i ] ] > 0) //如果某个方向多走了
        {
            for (int j = i; j < strLen; j++) //往后遍历其他的
            {
                char c    = str[ j ];
                copy[ c ] = copy[ c ] - 1; //把他变换一下
                res++;                     //答案++
                if (isZero(copy)) break;   //判断是否都是0
            }
        }
        if (isZero(copy)) ans = min(ans, res);
    }
    return ans;
}

int main() {
    const int len = 110;
    char      str[ len ];
    while (cin.getline(str, len)) {
        cout << deal(str) << endl;
    }
}
