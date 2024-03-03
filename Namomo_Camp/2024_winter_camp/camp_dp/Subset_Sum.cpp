#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, c;
    cin >> n >> c;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int y = 0;
    vector<int> a(1), b(1);
    for (int i = 1; i <= n; i++) {
        if (y + v[i] <= c) y += v[i], b.push_back(-v[i]);
        else a.push_back(v[i]);
    }
    n = a.size() - 1, m = b.size() - 1;
    int maxn = 2e4;
    vector dp(n + 1, vector<int>(2e4 + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int k = -maxn; k <= maxn; k++) {
            if(dp[i][k] == -1) continue;
            //第一种转移
            if(i + 1 <= n) {
                if (a[i + 1] + k <= maxn) dp[i + 1][k + v[i]] = dp[i][k];
                else dp[i + 1][k] = dp[i][k];
            }
            //第二种转移

        }
    }
    for (int i = maxn; i >= 0; i--) {
        if (dp[n][i] != -1) {
            cout << i + y << '\n';
            return;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}
