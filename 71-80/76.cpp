// https://atcoder.jp/contests/typical90/tasks/typical90_bx

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N, 0LL);
    long long sum = 0LL;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    if (sum % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    long long one_tenth = sum / 10;

    // 尺取り法を用いる
    int left = 0;
    int right = 0;
    long long current_sum = 0LL;
    while (left < N)
    {
        while (right < 2 * N && current_sum < one_tenth)
        {
            current_sum += A.at(right % N);
            right++;
        }
        if (current_sum == one_tenth) {
            cout << "Yes" << endl;
            return 0;
        }
        current_sum -= A.at(left % N);
        left++;
    }
    
    cout << "No" << endl;
    return 0;
}