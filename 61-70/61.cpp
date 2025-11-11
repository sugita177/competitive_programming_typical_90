// https://atcoder.jp/contests/typical90/tasks/typical90_bi

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    deque<int> X;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) X.push_front(x);
        if (t == 2) X.push_back(x);
        if (t == 3) cout << X.at(x-1) << endl;
    }
    return 0;
}