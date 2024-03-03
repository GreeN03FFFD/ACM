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
const int mod = 998244353;
const int N   = 2E6 + 7;
using namespace std;
ll ksm(ll a,ll b) {ll res=1;a%=mod; while(b){if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll x) {return ksm(x, mod-2);}

void solve(){
    int n = 24, nums; cin >> nums;
    vector<int> dp(1 << n);
    for (int i = 1; i <= nums; i++) {
        string s; cin >> s;
        int S = 0;
        for (int j = 1; j <= 3; j++)
            S |= int(pow(2, (s[j - 1] - 'a')));
        dp[S]++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (j & (1 << i)) dp[j] += dp[j ^ (1 << i)];

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) ans ^= (nums - dp[i]) * (nums - dp[i]);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
}