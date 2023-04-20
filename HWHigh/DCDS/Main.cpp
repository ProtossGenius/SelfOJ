#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverse(char *str, int begin, int end) {
    while (begin < end) {
        --end;
        swap(str[ begin ], str[ end ]);
        ++begin;
    }
}

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char line[ 105 ];
    int  begin = -1;
    while (cin.getline(line, 105)) {
        for (int i = 0; i < 105 && line[ i ]; ++i) {
            if (is_letter(line[ i ])) {
                if (begin == -1) {
                    begin = i;
                }

                continue;
            }

            if (begin != -1) {
                reverse(line, begin, i);
                begin = -1;
            }
        }

        cout << line << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
