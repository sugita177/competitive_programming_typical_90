// https://atcoder.jp/contests/typical90/tasks/typical90_av

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> scores;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        scores.push_back(A - B);
        scores.push_back(B);
    }
    sort(scores.begin(), scores.end(), greater<int>());
    long long ans = 0LL;
    for (int i = 0; i < K; i++) {
        ans += scores.at(i);
    }
    cout << ans << endl;
    return 0;
}