// https://atcoder.jp/contests/typical90/tasks/typical90_bl

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N, 0LL);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<long long> diff(N-1, 0LL);
    long long ans = 0LL;
    for (int i = 0; i < N-1; i++) {
        diff.at(i) = A.at(i+1) - A.at(i);
        ans += abs(diff.at(i));
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        long long V;
        cin >> L >> R >> V;
        int idx_L = L - 1;
        int idx_R = R - 1;
        if (idx_L > 0) {
            long long prev_L = diff.at(idx_L-1); 
            diff.at(idx_L-1) += V;
            ans = ans + abs(diff.at(idx_L-1)) - abs(prev_L);
        }
        if (idx_R < N-1) {
            long long prev_R = diff.at(idx_R);
            diff.at(idx_R) -= V;
            ans = ans + abs(diff.at(idx_R)) - abs(prev_R);
        }
        cout << ans << endl;
    }
    
    
    return 0;

}