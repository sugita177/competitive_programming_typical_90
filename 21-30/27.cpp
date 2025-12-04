// https://atcoder.jp/contests/typical90/tasks/typical90_aa

// 集合 (set) を使用する

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> name_set;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (name_set.insert(S).second) {
            cout << (i + 1) << endl;
        }
    }
    return 0;
}