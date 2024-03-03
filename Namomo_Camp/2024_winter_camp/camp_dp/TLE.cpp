#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
typedef long long ll;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9;
const int N   = 2E6 + 7;
using namespace std;
ll ksm(ll a,ll b) {ll res=1;a%=mod; while(b){if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll x) {return ksm(x, mod-2);}

void solve1(){
    int n, m; cin >> n >> m;
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << m)); // 第i个填j的方案数
    //初始化
    for (int j = 0; j < 1 << m; j++) dp[1][j] = (j % c[1] != 0);
    //DP
    // dp[i][j] = sigma dp[i - 1][x] (x & j == 0)
    // x & j == 0 即 x ∈ ~j
    for (int i = 2; i <= n; i++) {
        vector<ll> f(1 << m, 0);
        for (int j = 0; j < 1 << m; j++) f[j] = dp[i - 1][j];
        //SoS DP
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 1 << m; k++)
                if (k & (1 << j)) (f[k] += f[k ^ (1 << j)]) %= mod;
        //取反赋值
        for (int j = 0; j < 1 << m; j++) dp[i][j] = f[(1 << m) - 1 - j];
        for (int j = 0; j < 1 << m; j += c[i]) dp[i][j] = 0;
    }
    ll ans = 0;
    for (int j = 0; j < 1 << m; j++)
        (ans += dp[n][j]) %= mod;
    cout << ans << '\n';
}


void solve2(){
    int n, m; cin >> n >> m;
    vector<ll> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<ll> f(1 << m, 0);
    for (int i = 0; i < 1 << m; i++) f[i] = (i % c[1] != 0);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            for (int k = 0; k < 1 << m; k++)
                if (k & (1 << j)) (f[k] += f[k ^ (1 << j)]) %= mod;
        reverse(f.begin(), f.end());
        for (int j = 0; j < 1 << m; j += c[i]) f[j] = 0;
    }
    ll ans = 0;
    for (int i = 0; i < 1 << m; i++)
        (ans += f[i]) %= mod;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while(t--) solve2();
}
