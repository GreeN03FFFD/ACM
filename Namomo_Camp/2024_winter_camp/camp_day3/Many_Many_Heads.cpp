
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
    string s; cin >> s;
    s = ' ' + s;
    int n = s.length() - 1;
    for(int i=1;i<=n;i++) {
        if (s[i] == ')') s[i] = '(';
        if (s[i] == ']') s[i] = '[';
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i + 2 <= n && s[i] == s[i + 1] && s[i + 2] == s[i + 1]) {
            cout << "No" << '\n';
            return;
        }
        if(s[i] == s[i + 1]) cnt++;
    }
    if(cnt >= 3) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
}
 	  			 				 	    		   	 	 	 		*/
