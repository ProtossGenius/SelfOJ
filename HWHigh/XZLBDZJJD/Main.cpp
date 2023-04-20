#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Node {
  public:
    int value;
    int next;
};

int main() {
    map<int, Node> memory;
    int            head, n;
    cin >> head >> n;
    int pass = n / 2;

    while (n--) {
        int  addr;
        Node n;
        cin >> addr >> n.value >> n.next;
        memory[ addr ] = n;
    }
    Node node = memory[ head ];
    while (pass--) {
        node = memory[ node.next ];
    }

    cout << node.value << endl;

    // 严谨一点的做法是
}
