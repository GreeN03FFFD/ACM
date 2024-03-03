
#include<bits/stdc++.h>
using namespace std;

int dp[2][201][201][3];
void solve() {
    int n; cin >> n;
    vector v(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
    //vector dp(n + 1, vector(201, vector(201, vector<int>(3))));
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 200; j++)
            for (int k = 0; k <= 200; k++)
                for (int lst = 0; lst <= 2; lst++)
                    dp[i][j][k][lst] = 0;
    // dp[i][j][k][lst] 第i天， 某课旷了j天，某课旷了k天,昨天学的是lst课
    for (int i = 0; i < n; i++) {
        int now = i & 1, pre = 1 - now;
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 200; k++) {
                for (int lst = 0; lst <= 2; lst++) {
                    //x1为上次选的课的序号，x2，x3为当前未选的两门课的序号
                    int x1 = lst, x2 = (1 + lst) % 3, x3 = (2 + lst) % 3;
                    //计算昨天的得分 - 今天的扣分
                    int d1 = min(200, j + 1), d2 = min(200, k + 1);
                    int res = dp[pre][j][k][lst] - j * (j < 200) - k * (k < 200);
                    //选x1
                    dp[now][d1][d2][x1] = max(dp[now][d1][d2][x1], res + v[i + 1][x1]);
                    //选x2
                    dp[now][d2][1][x2] = max(dp[now][d2][1][x2], res + v[i + 1][x2]);
                    //选x3
                    dp[now][1][d1][x3] = max(dp[now][1][d1][x3], res + v[i + 1][x3]);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= 200; j++)
        for (int k = 0; k <= 200; k++)
            for (int lst = 0; lst <= 2; lst++)
                ans = max(ans, dp[1 - (n & 1)][j][k][lst] - j * (j < 200) - k * (k < 200));
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}
