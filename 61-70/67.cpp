// https://atcoder.jp/contests/typical90/tasks/typical90_bo

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert(string S) {
    string base9_str = "";
    long long decimal_value = stoll(S, nullptr, 8);
    if (decimal_value == 0) {
        base9_str = "0";
    } else {
        while (decimal_value > 0)
        {
            int remainder = decimal_value % 9;
            base9_str += to_string(remainder == 8 ? 5 : remainder);
            decimal_value /= 9;
        }
        
    }
    reverse(base9_str.begin(), base9_str.end());
    return base9_str;
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        N = convert(N);
    }
    cout << N << endl;
    return 0;
}