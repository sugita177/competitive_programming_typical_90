// https://atcoder.jp/contests/typical90/tasks/typical90_br

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<long long> X(N, 0), Y(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int x, y;
    x = X.at(N/2);
    y = Y.at(N/2);
    long long dist = 0LL;
    for (int i = 0; i < N; i++) {
        dist += fabs(X.at(i) - x) + fabs(Y.at(i) - y);
    }
    cout << dist << endl;
    return 0;
}
