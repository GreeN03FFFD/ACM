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
const int mod = 1e9 + 7;
const int N   = 2E6 + 7;
using namespace std;
ll ksm(ll a,ll b) {ll res=1;a%=mod; while(b){if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll x) {return ksm(x, mod-2);}

void solve() {
    int n; cin >> n;
    vector<ll> dp(1 << (20 + 1)), num(1 << (20 + 1), 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        dp[a]++;
    }

    for (int i = 1; i <= 1e6; i++) num[i] = (num[i - 1] << 1) % mod;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 1 << 20; j++)
            if (!(j & (1 << i))) (dp[j] += dp[j ^ (1 << i)]) %= mod;

    ll ans = 0;

    for (int i = 1; i < 1 << 20; i++){
        int k = 0;
        for (int j = 0; j <= 20; j++) if (i & (1 << j)) k++;
        if ((k & 1)) (ans += num[dp[i]] - 1) %= mod;
        else ans = ((ans - num[dp[i]] + 1) % mod + mod) % mod;
    }
    cout << (num[dp[0]] - 1 - ans + mod) % mod << '\n';

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
}
